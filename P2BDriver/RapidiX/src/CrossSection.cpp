#include "../includes/CrossSection.h"


void CrossSection::Initiate()
{
    ar=GetAlpha(mur,amz*Pi,mZ)/Pi;
    mt=GetMT(mur,mtatmt,amz*Pi,mZ);
    tau=mh*mh/E/E;
    WC=WilsonCoeff(mt,mur,WCMode);
    Lfr=2*log(muf/mur);
    L=2*log(mh/muf);
    pref=ar*ar*Pi*Pi*Born;

    
    cout<<"Initiating with the following parameters:"<<endl;
    cout<<"E_COM="<<E<<endl;
    cout<<"m_H="<<mh<<endl;
    cout<<"M_Z="<<mZ<<endl;
    cout<<"M_t(M_t)="<<mtatmt<<endl;
    cout<<"Alpha(M_Z)="<<amz*Pi<<endl;
    cout<<"mu_R="<<mur<<endl;
    cout<<"mu_F="<<muf<<endl;
    cout<<"Alpha(mu_R)="<<ar*Pi<<endl;
    cout<<"M_t(mu_R)="<<mt<<endl;
    if(WCMode==0)
        cout<<"Wilson Coefficient set to 1"<<endl;
    else if (WCMode==1)
        cout<<"Wilson Coefficient in ms-bar mode"<<endl;
    else if (WCMode==2)
        cout<<"Wilson Coefficient in on-shell mode"<<endl;
    
    return;
}

double GetMT(double mu,double mT,double alphamZ,double mZ)
{
    int it=10000;
    int nf=5;
    double locm=mT;
    double deltamu=(mu-mT)/(double)it;
    double gamma0=1;
    double gamma1=4.208333333333333 - 0.1388888888888889*nf;
    double gamma2=19.515625 - 2.284121493373736*nf - 0.02700617283950617*pow(nf,2);
    double gamma3=98.9434142552029 - 19.1074619186354*nf + 0.27616255142989465*pow(nf,2) + 0.005445404963397852*pow(nf,3);
    double gamma4=0;
    for(int i=0;i<=it;++i)
    {
        double locmu=mT+deltamu*i;
        double as=GetAlpha(locmu,alphamZ,mZ)/Pi;
        double gamma=as*gamma0
        +as*as*gamma1
        +as*as*as*gamma2
        +as*as*as*as*gamma3
        +as*as*as*as*as*gamma4;
        locm+=-locm*gamma*(locmu*locmu-(locmu-deltamu)*(locmu-deltamu))/locmu/locmu;
    }
    return locm;
}


double GetAlpha(double mu,double alphamZ,double mZ)
{
    int it=10000;
    double deltamu=(mu-mZ)/(double)it;
    double a=alphamZ;
    for(int i=0;i<it;++i)
    {
        double locmu=mZ+deltamu*i;
        a+=-a*a/Pi*(beta[0]+beta[1]*a/Pi+beta[2]*a/Pi*a/Pi+beta[3]*a*a*a/Pi/Pi/Pi)*(locmu*locmu-(locmu-deltamu)*(locmu-deltamu))/locmu/locmu;
    }
    return a;
}

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

//Returns a vector [4][6][4]
//First Index: Limit: {regular, x2 singular, x1 singular, both singular}
//Second index: Initial state {gg,qg,gq,qqbar,qq,q Q2}
//Third index: Order in as: {LO,NLO,NNLO,N3LO}
vector<vector<vector<double> > >  CrossSection::Evaluate(double xx1,double xx2)
{
    x1=xx1;
    x2=xx2;
    ComputeDummyVariables();
    SetCoefs();

    //Jacobian is one for all integrations, directly in rapidity! pref is the partonic Born cross section.
    double Jac=pref;
    vector<vector<vector<double> > > values=zero;
    
    //Set the output vector.
    for(int i=0;i<pos.size();++i)
    {
        if(pos[i][1]==0)
        {
            values[0][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0];
            values[1][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][1];
            values[2][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][2];
            values[3][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][3];
            
        }
        else if(pos[i][1]==1)
        {
            values[0][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0];
            values[2][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][2];
        }
        else if(pos[i][1]==2)
        {
            values[0][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0];
            values[1][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][1];
        }
        else
            values[0][pos[i][1]][pos[i][0]]+=Jac*pow(L,pos[i][2])*XSCoef[pos[i][0]][pos[i][1]][pos[i][2]][0];
    }
    
    //Apply WC and Mu_R-mu_F separation and alpha_S powers
    vector<double> avals={1,ar,ar*ar,pow(ar,3)};
    for(int i=0;i<values.size();++i)
    {
        for(int j=0;j<values[i].size();++j)
        {
            values[i][j]=MuREvolution(Lfr,values[i][j]);
            values[i][j]=Multiply(WC,values[i][j]);
            
            for(int k=0;k<values[i][j].size();++k)
                values[i][j][k]*=avals[k];
        }
    }
    //*/

    return values;
}
