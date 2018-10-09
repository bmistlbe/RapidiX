#include "../includes/CrossSection.h"
#include "cuba.h"

int wup=0;

void CrossSection::ParallelIntegrate()
{

    
    VegasIntegrator vegas;
    vegas.verbose=MCVerbose;
    if(Y==110)
        vegas.dimension=4;
    else
        vegas.dimension=3;
    vegas.components=1;
    vegas.precision=MCPrecision;
    vegas.startsize=1e4;
    vegas.batchsize=1e4;
    vegas.gridsize=100;
    vegas.mineval=10;
    vegas.maxpoints=(vegas.mineval)*vegas.batchsize;
    vegas.GridExport=false;
    vegas.ExportComponents=pos2.size()+2;
    double * chi,*res,*err;
    
    IncCoefs.Initiate();
    
    xs= vector<vector<double> > (6,vector<double> (4,0));
    error= vector<vector<double> > (6,vector<double> (4,0));
    vegas.Integrate(&ParallelIntegrand,res,err,chi,this);
    cout<<"Warmup done! - Grids are ready."<<endl;

    
    vegas.batchsize=1e5;
    int num_threads=NrThreads;
    vector<VegasIntegrator> Integrators(num_threads);
    for(int i=0;i<Integrators.size();i++)
    {
        Integrators[i]=vegas;
        Integrators[i].SetRandomSeed(RandomSeedOffset*num_threads+i);
        Integrators[i].StoredIntegrals.clear();
        Integrators[i].StoredErrors.clear();
    }

    int i=0;
    vector<CrossSection> myxs(num_threads);
#pragma omp parallel for private(i)
    for( i=0;i<myxs.size();i++)
    {
        myxs[i]=(*this);
    }
        
    double error=0;
    double integral=0;
    double chisq=0;
    int c=0;
    wup=1;
    while(true)
    {
        c++;
        double * locres[num_threads];
        double * locerr[num_threads];
        double * locchi[num_threads];
        
#pragma omp parallel for private(i)
        for(i=0;i<Integrators.size();i++)
            Integrators[i].ContinueIntegrate(&ParallelIntegrand,locres[i],locerr[i],locchi[i],&myxs[i]);
        
        //Combine local Samples generated from different OMP threads - this is just to determine how precise the inclusive XS was computed.
        integral=0;
        error=0;
        chisq=0;
        for(int j=0;j<num_threads;j++)
        {
            if(locres[j][0]==0)
                continue;
            error+=1.0/locerr[j][0]/locerr[j][0];
            integral+=locres[j][0]/locerr[j][0]/locerr[j][0];
        }
        error=1.0/sqrt(error);
        integral=error*error*integral;
        for(int j=0;j<num_threads;j++)
            chisq+=pow(integral-locres[j][0],2)/locerr[j][0]/locerr[j][0]/num_threads;
        if(MCVerbose>=1)
            cout<<"Current iterator: "<<c<<": "<<integral<<" +- "<<error<<" +- "<<fabs(error/integral)*100<<" % ChiSq/DOF: "<< chisq<<endl;
        
        //Histogramming
        vector<double *> data;
        for(i=0;i<Integrators.size();i++)
            data.insert(data.end(),Integrators[i].StoredExportData.begin(),Integrators[i].StoredExportData.end());
        
        
#pragma omp parallel for private(i)
        for(i=0;i<data.size();i++)
            data[i][0]=data[i][0]/(double)num_threads;
        
        vector<MCEvent> Events=CreateEvents(data);
        
//#pragma omp parallel for private(i)
//        for(i=0;i<data.size();i++)
//            delete[] data[i];
        data.clear();
        
        Histopheles.AddEvents(Events,Events.size());
        Histopheles.Export(ResultFile);
        
        //While Loop Break;
        if(fabs(error/integral)<MCPrecision)
            break;
    }
    cout<<"Through!"<<endl; 
    return;
}


void CrossSection::IntegrateCuba()
{

    int NDIM;
    if(Y==110)
        NDIM=3;
    else
        NDIM=2;
    int NCOMP=pos2.size()+1;
    int NVEC=1;
    double EPSREL= MCPrecision;
    double EPSABS= 1e-18;
    int VERBOSE=MCVerbose;
    int LAST=4;
    int SEED=0;
    int MINEVAL=1000;
    int MAXEVAL=5000000;
    int NSTART=1000;
    int NINCREASE=5000;
    int NBATCH=1000;
    int KEY=9;
    double res[NCOMP], err[NCOMP], chi[NCOMP];
    int comp, nregions, neval, fail,cuhre_key=9;
    
    
    IncCoefs.Initiate();
    xs= vector<vector<double> > (6,vector<double> (4,0));
    error= vector<vector<double> > (6,vector<double> (4,0));
    
    //Cuhre(NDIM, NCOMP, CubaIntegrand, this, NVEC,EPSREL, EPSABS,  VERBOSE, MINEVAL, MAXEVAL, KEY,0, &nregions, &neval,&fail, res, err, chi);
    fail=0;
    Cuhre(NDIM, NCOMP, CubaIntegrand, this, NVEC,EPSREL, EPSABS, VERBOSE ,MINEVAL, MAXEVAL, KEY, NULL, NULL,&nregions, &neval, &fail, res,err,chi);
    if(fail!=0)
        Vegas(NDIM, NCOMP, CubaIntegrand,this, NVEC, EPSREL, EPSABS, VERBOSE, SEED, MINEVAL, MAXEVAL, NSTART, NINCREASE, NBATCH, NULL, NULL, NULL,&neval, &fail, res, err, chi);
    
    for(int i=0;i<pos2.size();++i)
    {
        xs[pos2[i][1]][pos2[i][0]]=res[i+1]-1e-6;
        error[pos2[i][1]][pos2[i][0]]=err[i+1];
        cout<<"Integration Result "<<i<<" = "<<res[i+1]<<" +- "<<err[i+1]<<" +- "<<fabs(err[i+1]/res[i+1])*100 <<" %"<<endl;
        if(fabs(xs[pos2[i][1]][pos2[i][0]])<1e-5)
        {
            xs[pos2[i][1]][pos2[i][0]]=0;
            error[pos2[i][1]][pos2[i][0]]=0;
        }
    }
    return;
}


static int CubaIntegrand(const int *ndim, const double xx[], const int *ncomp, double ff[], void *userdata)
{
    CrossSection * xs=(CrossSection*) userdata;
    double x1=xx[0];
    double x2=xx[1];
    
    double tau=xs->tau;
    double Y,Jac;
    if(xs->Y==110)
    {
        Y=fabs(log(tau))*xx[2]-0.5*fabs(log(tau));
        Jac=fabs(log(tau))*xs->pref;
    }
    else
    {
        Y=xs->Y;
        Jac=xs->pref;
    }
    double bound1=sqrt(tau)*exp(-Y);
    double bound2=sqrt(tau)*exp(Y);
    
    for(int i=0;i<xs->pos2.size()+1;i++)
        ff[i]=1e-9;
    
    vector<vector<double> > res=xs->Evaluate(x1,x2,bound1,bound2,Jac);
    for(int i=0;i<xs->pos2.size();++i)
        ff[i+1]+=res[xs->pos2[i][1]][xs->pos2[i][0]];
    ff[0]=xs->ComputeTotalXS(res)+1e-6;
    if(isnan(fabs(ff[0]))||isinf(fabs(ff[0])))
    {
        cout<<"nan!! "<<endl;
        return -999;
    }
    
    //cout<<ff[0]<<endl;
    xs=0;
    return 0;
}




int ParallelIntegrand(const double * xx,double * ff,const void * userdata,double * ExportData)
{
    CrossSection * xs=(CrossSection*) userdata;
    double x1=xx[0];
    double x2=xx[1];
    double tau=xs->tau;
    double Y,Jac;

    if(xs->Y==110)
    {
        Y=fabs(log(tau))*xx[2]-0.5*fabs(log(tau));
        Jac=fabs(log(tau))*xs->pref;
    }
    else
    {
        Y=xs->Y;
        Jac=xs->pref;
    }
    double bound1=sqrt(tau)*exp(-Y);
    double bound2=sqrt(tau)*exp(Y);
    
    ff[0]=1e-9;
    
    vector<vector<double> > res=xs->Evaluate(x1,x2,bound1,bound2,Jac);
    ExportData[1]=Y;
    for(int i=0;i<xs->pos2.size();++i)
        ExportData[i+2]+=res[xs->pos2[i][1]][xs->pos2[i][0]];
    ff[0]=xs->ComputeTotalXS(res)+1e-6;
    xs=0;
    return 0;
}
