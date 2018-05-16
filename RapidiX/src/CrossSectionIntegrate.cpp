#include "../includes/CrossSection.h"

int wup=0;

void CrossSection::ParallelIntegrate()
{

    
    VegasIntegrator vegas;
    vegas.verbose=MCVerbose;
    vegas.dimension=3;
    vegas.components=1;
    vegas.precision=MCPrecision;
    vegas.startsize=1e5;
    vegas.batchsize=1e5;
    vegas.gridsize=100;
    vegas.mineval=10;
    vegas.maxpoints=(vegas.mineval)*vegas.batchsize;
    vegas.GridExport=true;
    vegas.ExportComponents=pos2.size()+2;
    double * chi,*res,*err;
    
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
        
#pragma omp parallel for private(i)
        for(i=0;i<data.size();i++)
            delete[] data[i];
        data.clear();
        
        Histopheles.AddEvents(Events,Events.size());
        Histopheles.Export(ResultFile);
        
        //While Loop Break;
        if(fabs(error/integral)<MCPrecision)
            break;
    }
    
    return;
}


int ParallelIntegrand(const double * xx,double * ff,const void * userdata,double * ExportData)
{
    CrossSection * xs=(CrossSection*) userdata;
    double x1=xx[1];
    double x2=xx[2];
    double tau=xs->tau;
    double Y=fabs(log(tau))*xx[0]-0.5*fabs(log(tau));
    double bound1=sqrt(tau)*exp(-Y);
    double bound2=sqrt(tau)*exp(Y);
    double Jac=fabs(log(tau))*xs->pref;
    
    ff[0]=1e-9;
    
    vector<vector<double> > res=xs->Evaluate(x1,x2,bound1,bound2,Jac);
    ExportData[1]=Y;
    for(int i=0;i<xs->pos2.size();++i)
        ExportData[i+2]+=res[xs->pos2[i][1]][xs->pos2[i][0]];
    ff[0]=xs->ComputeTotalXS(res)+1e-6;
    xs=0;
    return 0;
}
