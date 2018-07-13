

#ifndef CrossSection_h
#define CrossSection_h



#include "GlobalDefs.h"
#include "HPLs.h"
#include "Wilson.h"


double GetAlpha(double mu,double alphamZ,double mZ);
double GetMT(double mu,double mT,double alphamZ,double mZ);

class CrossSection{
private:
public:
    
    //Variables for evaluation
    double x1,x2;
    double Lmx11, Lmx12, Lmx13, Lmx14, Lmx15, Lmx21, Lmx22, Lmx23, Lmx24, Lmx25, Lx11, Lx12, Lx13, Lx14, Lx15, Lx21, Lx22, Lx23, Lx24, Lx25;
    double x110, x12, x13, x14, x15, x16, x17, x18, x19, x210, x22, x23, x24, x25, x26, x27, x28, x29;
    
    
    //Parameters
    double mh;
    double muf;
    double mur;
    double E;
    double mZ;
    double mt;
    double mtatmt;
    double Gf;
    double conversion_to_pb;
    double ar;
    double amz;
    double Born;
    double tau;
    double L;
    double Lfr;
    double pref;
    int WCMode;
    
    //Wilson Coefficient
    vector<double> WC;
    
    //Variables for the evaluation
    vector<vector<vector<double> > > zero;
    vector<vector<int> > pos,pos2;
    double XSCoef[4][6][4][4];
    

    //Action Functions
    void ComputeDummyVariables();
    vector<vector<vector<double> > >  Evaluate(double xx1,double xx2);
    void SetCoefs();
    void SetNNLO();
    void SetN3LO();
    
    
    
    //Set Parameters
    void SetMH(double Q){mh=Q;return;};
    void SetMuf(double Q){muf=Q;return;};
    void SetMur(double Q){mur=Q;return;};
    void SetE(double Q){E=Q;return;};
    void SetmZ(double Q){mZ=Q;return;};
    void SetAlphamZ(double Q){amz=Q/Pi;return;};
    void Setmt(double Q){mtatmt=Q;return;};
    void SetWilsonCoefficientMode(int i){WCMode=i;return;};
    void Initiate();
    
    
    
    CrossSection()
    {
        WCMode=1;
        amz=0.118/Pi;
        ar=0.118/Pi;
        mh=125;
        muf=mh;
        mur=mh;
        E=13000;
        mZ=91.1876;
        mt=162.7;
        conversion_to_pb=3.893793656e8;
        Gf=1.16637/100000.0;
        Born=Gf/sqrt(2.0)/288.0/Pi*conversion_to_pb;
        tau=mh*mh/E/E;
        
        
        Lfr=0;
        L=0;
        
        WC=vector<double> (4,0);
        WC[0]=1;
        pref=1;
        
        //Order , Initial Stat , Log Power, Distribution
        for(int i=0;i<4;i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<4;k++)
                    for(int l=0;l<4;l++)
                        XSCoef[i][j][k][l]=0;

        
        //Limit , Initial Stat , order
        zero=vector<vector<vector<double> > >  (4,vector<vector<double> > (6,vector<double>(4,0)));
        
        //order , initial stat , Log Power
        pos.push_back(lst(0,0,0));
        //NLO
        pos.push_back(lst(1,0,0));
        pos.push_back(lst(1,0,1));
        pos.push_back(lst(1,1,0));
        pos.push_back(lst(1,1,1));
        pos.push_back(lst(1,2,0));
        pos.push_back(lst(1,2,1));
        pos.push_back(lst(1,3,0));
        pos.push_back(lst(1,3,1));
        //NNLO - g g
        pos.push_back(lst(2,0,0));
        pos.push_back(lst(2,0,1));
        pos.push_back(lst(2,0,2));
        //NNLO - g q
        pos.push_back(lst(2,1,0));
        pos.push_back(lst(2,1,1));
        pos.push_back(lst(2,1,2));
        //NNLO - g q
        pos.push_back(lst(2,2,0));
        pos.push_back(lst(2,2,1));
        pos.push_back(lst(2,2,2));
        //NNLO - q qbar
        pos.push_back(lst(2,3,0));
        pos.push_back(lst(2,3,1));
        pos.push_back(lst(2,3,2));
        //NNLO - q q
        pos.push_back(lst(2,4,0));
        pos.push_back(lst(2,4,1));
        pos.push_back(lst(2,4,2));
        //NNLO - q Q2
        pos.push_back(lst(2,5,0));
        pos.push_back(lst(2,5,1));
        pos.push_back(lst(2,5,2));
        //*/
        //N3LO - g g
        pos.push_back(lst(3,0,0));
        pos.push_back(lst(3,0,1));
        pos.push_back(lst(3,0,2));
        pos.push_back(lst(3,0,3));
        //N3LO - q g
        pos.push_back(lst(3,1,0));
        pos.push_back(lst(3,1,1));
        pos.push_back(lst(3,1,2));
        pos.push_back(lst(3,1,3));
        //N3LO - g q
        pos.push_back(lst(3,2,0));
        pos.push_back(lst(3,2,1));
        pos.push_back(lst(3,2,2));
        pos.push_back(lst(3,2,3));
        //N3LO - q qbar
        pos.push_back(lst(3,3,0));
        pos.push_back(lst(3,3,1));
        pos.push_back(lst(3,3,2));
        pos.push_back(lst(3,3,3));
        //N3LO - q q
        pos.push_back(lst(3,4,0));
        pos.push_back(lst(3,4,1));
        pos.push_back(lst(3,4,2));
        pos.push_back(lst(3,4,3));
        //N3LO - q Q2
        pos.push_back(lst(3,5,0));
        pos.push_back(lst(3,5,1));
        pos.push_back(lst(3,5,2));
        pos.push_back(lst(3,5,3));
        //*/
        
        
        pos2.push_back(lst(0,0,0));
        pos2.push_back(lst(1,0,0));
        pos2.push_back(lst(1,1,0));
        pos2.push_back(lst(1,2,0));
        pos2.push_back(lst(1,3,0));
        pos2.push_back(lst(2,0,0));
        pos2.push_back(lst(2,1,0));
        pos2.push_back(lst(2,2,0));
        pos2.push_back(lst(2,3,0));
        pos2.push_back(lst(2,4,0));
        pos2.push_back(lst(2,5,0));
        pos2.push_back(lst(3,0,0));
        pos2.push_back(lst(3,1,0));
        pos2.push_back(lst(3,2,0));
        pos2.push_back(lst(3,3,0));
        pos2.push_back(lst(3,4,0));
        pos2.push_back(lst(3,5,0));


    };
};

#endif
