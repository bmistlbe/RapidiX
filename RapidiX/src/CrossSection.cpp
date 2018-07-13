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
    x111=pow(x1,11);
    x211=pow(x2,11);
    x112=pow(x1,12);
    x212=pow(x2,12);
    x113=pow(x1,13);
    x213=pow(x2,13);
    x114=pow(x1,14);
    x214=pow(x2,14);
    x115=pow(x1,15);
    x215=pow(x2,15);
    x116=pow(x1,16);
    x216=pow(x2,16);
    x117=pow(x1,17);
    x217=pow(x2,17);
    x118=pow(x1,18);
    x218=pow(x2,18);
    x119=pow(x1,19);
    x219=pow(x2,19);
    x120=pow(x1,20);
    x220=pow(x2,20);

    
    LogNNLO1=log(1 + 2*x1);
    LogNNLO2=log(x1);
    LogNNLO3=log(1 + 2*x2);
    LogNNLO4=log(1 - x1*x2);
    LogNNLO5=log(x2);
    LogNNLO6=log(x1 + x2);
    LogNNLO7=log(1 + x1*x2);
    LogNNLO8=log(pow(-x1 + x2,2));
    
    
    GNNLO1=HPL(0,1.,-2.*x1);
    GNNLO2=HPL(0,1.,pow(x1,2));
    GNNLO3=HPL(0,1.,(2.*pow(x1,2))/(1. + x1));
    GNNLO4=HPL(0,1.,(-4.*x1)/pow(1. - 1.*x1,2));
    GNNLO5=HPL(0,1.,1. - 1.*x1);
    GNNLO6=HPL(0,1.,(-1.*(1. - 1.*x1)*(1. + x1))/(x1*(x1 + x2)));
    GNNLO7=HPL(0,1.,(-1.*(-1.*x1 + x2))/(x1 + x2));
    GNNLO8=HPL(0,1.,(-1.*x1 + x2)/((3. - 2.*(1. - 1.*x1))*x2));
    GNNLO9=HPL(0,1.,(0.5*(-1.*x1 + x2)*(1. + x2 - 1.*(1. - 1.*x1)*x2))/((1. - 1.*x1)*(1. + x1)*x2));
    GNNLO10=HPL(0,1.,x1*x2);
    GNNLO11=HPL(0,1.,((1. - 1.*x1)*(1. + x1)*x2)/(x1 + x2));
    GNNLO12=HPL(0,1.,pow(x1,2)*pow(x2,2));
    GNNLO13=HPL(0,1.,(2.*pow(x2,2))/(1. + x2));
    GNNLO14=HPL(0,1.,(-1.*(1. - 1.*x1)*(1. + x1))/(pow(x1,2)*(1. - 1.*x2)*(1. + x2)));
    GNNLO15=HPL(0,1.,(-1.*(-1.*x1 + x2))/((1. + x1)*(1. - 1.*x2)));
    GNNLO16=HPL(0,1.,(-0.5*(-1.*x1 + x2)*(1. + x2 - 1.*(1. - 1.*x1)*x2))/(x1*(1. - 1.*x2)*(1. + x2)));
    GNNLO17=HPL(0,1.,(-1.*(1. - 1.*x1)*x2)/(1. - 1.*x2));
    GNNLO18=HPL(0,1.,(2.*(1. + x1)*x2)/((1. - 1.*x2)*(-1. + x2 - 1.*(1. - 1.*x1)*x2)));
    GNNLO19=HPL(0,1.,(-2.*(1. - 1.*x1)*x2)/((1. - 1.*x2)*(1. + x2 - 1.*(1. - 1.*x1)*x2)));
    GNNLO20=HPL(0,1.,(-1.*(1. - 1.*x1)*(1. + x1)*pow(x2,2))/((1. - 1.*x2)*(1. + x2)));
    GNNLO21=HPL(0,1.,(-1.*(1. - 1.*x1)*(1. - 1.*x2))/(x1 + x2));
    GNNLO22=HPL(0,1.,(-0.5*(1. - 1.*x1)*(1. - 1.*x2))/(x1 + x2));
    GNNLO23=HPL(0,1.,(x1*(1. - 1.*x2)*(1. + x2))/(x1 + x2));
    GNNLO24=HPL(0,1.,(-1.*(1. - 1.*x1)*(1. + x1)*(1. - 1.*x2)*(1. + x2))/pow(-1.*x1 + x2,2));
    GNNLO25=HPL(0,1.,(-2.*x1*(1. - 1.*x2))/((1. - 1.*x1)*(1. + x2 - 1.*(1. - 1.*x1)*x2)));
    GNNLO26=HPL(0,1.,(x1 - 1.*x2)/((3. - 2.*(1. - 1.*x1))*(1. + x2)));
    GNNLO27=HPL(0,1.,(-4.*x1*x2)/pow(2. - 1.*x1 - 1.*(1. - 1.*x1)*(1. - 1.*x2) - 1.*x2,2));
    GNNLO28=HPL(0,0.,1.,2. - 2./(1. - 1.*x1));
    GNNLO29=HPL(0,0.,1.,1/(4. - 2.*(1. - 1.*x1)));
    GNNLO30=HPL(0,0.,1.,x1);
    GNNLO31=HPL(0,0.,1.,1/(1. + x1));
    GNNLO32=HPL(0,0.,1.,1. + 0.5*(-1. + x1));
    GNNLO33=HPL(0,0.,1.,-1.*x1);
    GNNLO34=HPL(0,0.,1.,-2.*x1);
    GNNLO35=HPL(0,0.,1.,-4.*x1*(1. + x1));
    GNNLO36=HPL(0,0.,1.,0.5*(1. - 1.*x1));
    GNNLO37=HPL(0,0.,1.,1. - 1.*x1);
    GNNLO38=HPL(0,0.,1.,(1. - 1.*x1)*(1. + x1));
    GNNLO39=HPL(0,0.,1.,2. - 2./(1. - 1.*x2));
    GNNLO40=HPL(0,0.,1.,1/(4. - 2.*(1. - 1.*x2)));
    GNNLO41=HPL(0,0.,1.,x2);
    GNNLO42=HPL(0,0.,1.,1/(1. + x2));
    GNNLO43=HPL(0,0.,1.,1. + 0.5*(-1. + x2));
    GNNLO44=HPL(0,0.,1.,-1.*x2);
    GNNLO45=HPL(0,0.,1.,-2.*x2);
    GNNLO46=HPL(0,0.,1.,-4.*x2*(1. + x2));
    GNNLO47=HPL(0,0.,1.,0.5*(1. - 1.*x2));
    GNNLO48=HPL(0,0.,1.,1. - 1.*x2);
    GNNLO49=HPL(0,0.,1.,(1. - 1.*x2)*(1. + x2));
    
    MRRNNLO1=0;
    MRRNNLO2=0;
    MRRNNLO3=0;
    MRRNNLO4=0;
    MRRNNLO5=0;
    MRRNNLO6=0;
    MRRNNLO7=0;
    MRRNNLO8=0;
    MRRNNLO9=0;
    MRRNNLO10=0;
    MRRNNLO11=0;
    MRRNNLO12=0;
    MRRNNLO13=0;
    MRRNNLO14=0;
    MRRNNLO15=0;
    MRRNNLO16=0;
    MRRNNLO17=0;
    MRRNNLO18=0;
    
    //SetMRR();
    //*/

    return;
}

int cc=0;
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
    cc=0;
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
    
    cout<<"Count is in the end: "<<cc<<endl;
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
    
    
    //cout<<"x1 "<<x1<<" x2 "<<x2<<" xs qQ2 NNLO "<<XSCoef[2][5][0][0]<<endl;
    
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
        
        values[pos[i][0]][pos[i][1]][pos[i][2]]*=Jac*pow(L,pos[i][2]);
        
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
    for(int i=0;i<res.size();++i)
        for(int j=0;j<res[i].size();++j)
        {
            res[i][j]*=pow(ar,j);
            //cout<<i<<" "<<j<<" xs: "<<res[i][j]<<endl;
        }
    //*/

    return res;
}

int Integrand(const double * xx,double * ff,const void * userdata,double * ExportData)
{
    CrossSection * xs=(CrossSection*) userdata;
    double x1=xx[1];
    double x2=xx[2];
    if(x1<0.3&&x2<0.3)
        cc++;
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
