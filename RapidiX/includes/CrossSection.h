

#ifndef CrossSection_h
#define CrossSection_h



#include "GlobalDefs.h"
#include "PDF.h"
#include "Histogram.h"
#include "Luminosity.h"
#include "HPLs.h"
#include "Wilson.h"
#include "Vegas.h"
#include "Grider.h"
#include "Inclusive.h"

extern int N3LOExpansion;
class CrossSection{
private:
public:
    
    double x1,x2;
    double Lmx11, Lmx12, Lmx13, Lmx14, Lmx15, Lmx21, Lmx22, Lmx23, Lmx24, Lmx25, Lx11, Lx12, Lx13, Lx14, Lx15, Lx21, Lx22, Lx23, Lx24, Lx25;
    double x110,x111,x112,x113,x114,x115,x116,x117,x118,x119,x120, x12, x13, x14, x15, x16, x17, x18, x19, x210, x22, x23, x24, x25, x26, x27, x28, x29 ,x211,x212,x213,x214,x215,x216,x217,x218,x219,x220;
    double GNNLO1, GNNLO2, GNNLO3, GNNLO4, GNNLO5, GNNLO6, GNNLO7, GNNLO8, GNNLO9, GNNLO10, GNNLO11, GNNLO12, GNNLO13, GNNLO14, GNNLO15, GNNLO16, GNNLO17, GNNLO18, GNNLO19, GNNLO20, GNNLO21, GNNLO22, GNNLO23, GNNLO24, GNNLO25, GNNLO26, GNNLO27, GNNLO28, GNNLO29, GNNLO30, GNNLO31, GNNLO32, GNNLO33, GNNLO34, GNNLO35, GNNLO36, GNNLO37, GNNLO38, GNNLO39, GNNLO40, GNNLO41, GNNLO42, GNNLO43, GNNLO44, GNNLO45, GNNLO46, GNNLO47, GNNLO48, GNNLO49;
    double LogNNLO1, LogNNLO2, LogNNLO3, LogNNLO4, LogNNLO5, LogNNLO6, LogNNLO7, LogNNLO8;
    double MRRNNLO1, MRRNNLO2, MRRNNLO3, MRRNNLO4, MRRNNLO5, MRRNNLO6, MRRNNLO7, MRRNNLO8, MRRNNLO9, MRRNNLO10, MRRNNLO11, MRRNNLO12, MRRNNLO13, MRRNNLO14, MRRNNLO15, MRRNNLO16, MRRNNLO17, MRRNNLO18;
    
    
    vector<vector<vector<Grider> > > NNLOGrider;
    
    double L;
    double ar;
    double tau;
    double Q;
    double Lfr;
    double pref;
    vector<double> WC;
    Luminosity Lumi;
    double Y;
    
    vector<vector<double> > xs,error;
    vector<vector<vector<double> > > zero,values;
    vector<vector<int> > pos,pos2;
    
    double XSCoef[4][6][4][4];
    
    double MCPrecision;
    int MCVerbose;
    int NrThreads;
    
    void SetCoefs();
    void SetNNLO();
    void SetN3LO();
    void SetMRR();
    
    string ResultFile;
    Histogramer Histopheles;
    int RandomSeedOffset;
    void ReadGrids();
    
    
    InclusiveCoefficients IncCoefs;
    
    CrossSection()
    {
        Y=110;
        NNLOGrider=vector<vector<vector<Grider> > > (6,vector<vector<Grider> >(3,vector<Grider>(21)));
        ReadGrids();
        
        NrThreads=8;
        ResultFile="Output.txt";
        RandomSeedOffset=0;
        MCPrecision=1e-3;
        Lfr=0;
        L=0;
        ar=0;
        tau=0;
        Q=0;
        WC=vector<double> (4,0);
        WC[0]=1;
        pref=1;
        
        //Order , Initial Stat , Log Power, Distribution
        for(int i=0;i<4;i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<4;k++)
                    for(int l=0;l<4;l++)
                        XSCoef[i][j][k][l]=0;

        
        //Order , Initial Stat , Log Power
        zero=vector<vector<vector<double> > >  (4,vector<vector<double> > (6,vector<double>(4,0)));
        values=zero;
        
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
    
    void Integrate();
    void ParallelIntegrate();
    void ComputeDummyVariables();
    double ComputeTotalXS(const vector<vector<double > > & vec);
    vector<vector<double> >  Evaluate(double xx1,double xx2,double bound1,double bound2,double Jac);
    
};

int Integrand(const double * xx,double * ff,const void * userdata,double * ExportData);
int ParallelIntegrand(const double * xx,double * ff,const void * userdata,double * ExportData);

#endif
