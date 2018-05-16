#include "../includes/CrossSection.h"


int N3LOExpansion=-1;


void CrossSection::ComputeDummyVariables()
{
    Lx11=log(1 - x1);
    Lmx11=log(1 + x1);
    Lx21=log(1 - x2);
    Lmx21=log(1 + x2);
    Lx12=pow(log(1 - x1),2);
    Lmx12=pow(log(1 + x1),2);
    Lx22=pow(log(1 - x2),2);
    Lmx22=pow(log(1 + x2),2);
    Lx13=pow(log(1 - x1),3);
    Lmx13=pow(log(1 + x1),3);
    Lx23=pow(log(1 - x2),3);
    Lmx23=pow(log(1 + x2),3);
    Lx14=pow(log(1 - x1),4);
    Lmx14=pow(log(1 + x1),4);
    Lx24=pow(log(1 - x2),4);
    Lmx24=pow(log(1 + x2),4);
    Lx15=pow(log(1 - x1),5);
    Lmx15=pow(log(1 + x1),5);
    Lx25=pow(log(1 - x2),5);
    Lmx25=pow(log(1 + x2),5);
    x12=pow(x1,2);
    x22=pow(x2,2);
    x13=pow(x1,3);
    x23=pow(x2,3);
    x14=pow(x1,4);
    x24=pow(x2,4);
    x15=pow(x1,5);
    x25=pow(x2,5);
    x16=pow(x1,6);
    x26=pow(x2,6);
    x17=pow(x1,7);
    x27=pow(x2,7);
    x18=pow(x1,8);
    x28=pow(x2,8);
    x19=pow(x1,9);
    x29=pow(x2,9);
    x110=pow(x1,10);
    x210=pow(x2,10);

    return;
}


void CrossSection::Integrate()
{

    
    VegasIntegrator vegas;
    vegas.verbose=MCVerbose;
    vegas.dimension=3;
    vegas.components=pos2.size()+1;
    vegas.precision=MCPrecision;
    vegas.startsize=1e5;
    vegas.batchsize=1e5;
    vegas.gridsize=100;
    vegas.mineval=10;
    vegas.maxpoints=1e9;
    vegas.GridExport=false;
    vegas.ExportComponents=0;
    double * chi,*res,*err;
    
    xs= vector<vector<double> > (6,vector<double> (4,0));
    error= vector<vector<double> > (6,vector<double> (4,0));
    vegas.Integrate(&Integrand,res,err,chi,this);
    
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




double CrossSection::ComputeTotalXS(const vector<vector<double > > & vec)
{
    double tot=0;
    for(int i=0;i<vec.size();++i)
        for(int j=0;j<vec[i].size();++j)
                tot+=vec[i][j];
    return tot;
}



vector<vector<double> >  CrossSection::Evaluate(double xx1,double xx2,double bound1,double bound2,double Jac)
{
    x1=xx1;
    x2=xx2;
    ComputeDummyVariables();
    
    Lumi.SetLuminosity(x1,x2,bound1,bound2);
    vector<vector<vector<double> > > values=zero;
    SetCoefs();
    

    for(int i=0;i<pos.size();++i)
    {
        if(pos[i][1]==0)
            values[pos[i][0]][pos[i][1]][pos[i][2]]+=
            XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0]*Lumi.L[pos[i][1]]
            +XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][2]*Lumi.Lgg10
            +XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][1]*Lumi.Lgg01
            +XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][3]*Lumi.Lgg00;
        else if(pos[i][1]==1)
            values[pos[i][0]][pos[i][1]][pos[i][2]]+=
            XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0]*Lumi.L[pos[i][1]]
            +XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][2]*Lumi.Lqg10;
        else if(pos[i][1]==2)
            values[pos[i][0]][pos[i][1]][pos[i][2]]+=
            XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0]*Lumi.L[pos[i][1]]
            +XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][1]*Lumi.Lgq01;
        else
            values[pos[i][0]][pos[i][1]][pos[i][2]]+=XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0]*Lumi.L[pos[i][1]];
        
        values[pos[i][0]][pos[i][1]][pos[i][2]]*=Jac*pow(ar,pos[i][0])*pow(L,pos[i][2]);
        
    }
    vector<vector<double> > res(6,vector<double> (4,0));
    for(int i=0;i<values.size();++i)
        for(int j=0;j<values[i].size();++j)
            for(int k=0;k<values[i][j].size();++k)
                res[j][i]+=values[i][j][k];
    
    for(int i=0;i<res.size();++i)
    {
        res[i]=MuREvolution(Lfr,res[i]);
        res[i]=Multiply(WC,res[i]);
    }
    //*/

    return res;
}

int Integrand(const double * xx,double * ff,const void * userdata,double * ExportData)
{
    CrossSection * xs=(CrossSection*) userdata;
    double x1=xx[1];
    double x2=xx[2];
    double tau=xs->tau;
    double Y=fabs(log(tau))*xx[0]-0.5*fabs(log(tau));
    double bound1=sqrt(tau)*exp(-Y);
    double bound2=sqrt(tau)*exp(Y);
    double Jac=fabs(log(tau))*xs->pref;
    
    for(int i=0;i<xs->pos2.size()+1;i++)
        ff[i]=1e-9;
    
    vector<vector<double> > res=xs->Evaluate(x1,x2,bound1,bound2,Jac);
    for(int i=0;i<xs->pos2.size();++i)
        ff[i+1]+=res[xs->pos2[i][1]][xs->pos2[i][0]];
    ff[0]=xs->ComputeTotalXS(res)+1e-6;

    
    xs=0;
    return 0;
}
