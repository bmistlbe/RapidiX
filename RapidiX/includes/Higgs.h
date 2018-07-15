

#ifndef Higgs_h
#define Higgs_h



#include "GlobalDefs.h"
#include "Luminosity.h"
#include "CrossSection.h"
#include "Wilson.h"


class Higgs{
private:
public:
    
    int WCMode;
    int PDFMember;
    string PDFSet;
    
    double mh;
    double muf;
    double mur;
    double E;
    double mZ;
    double mt;
    double Gf;
    double conversion;
    double ar;
    double Born;
    
    double MCPrecision;
    int MCVerbose;
    
    Luminosity Lumi;
    CrossSection xs;
    
    vector<vector<vector<double> > > Integrals,Errors;
    
    bool integrated;
    
    Higgs()
    {
        Lumi.pdf=new PDFF;
        integrated=false;
        
        WCMode=1;
        ar=0.118/Pi;
        mh=125;
        muf=mh;
        mur=mh;
        E=13000;
        mZ=91.1876;
        mt=162.7;
        
        conversion=3.893793656e8;
        Gf=1.16637/100000.0;
        Born=Gf/sqrt(2.0)/288.0/Pi*conversion;
        xs.Lumi=Lumi;
        
        MCPrecision=1e-3;
        MCVerbose=1;
    };
    
    //Set Stuff
    void SetMuf(double Q){muf=Q;integrated=false;return;};
    void SetMur(double Q){mur=Q;return;};
    void SetE(double Q){E=Q;integrated=false;return;};
    void SetmZ(double Q){mZ=Q;return;};
    void Setmt(double Q){mt=Q;return;};
    void SetWilsonCoefficientMode(int i){WCMode=i;return;};
    void SetPDF(int mem,string set){PDFMember=mem;PDFSet=set;integrated=false;return;};
    void SetVerbose(int v){MCVerbose=v;return;};
    void SetPrecision(double prec){MCPrecision=prec;return;};
    void SetResultFile(string file){xs.ResultFile=file;return;};
    void SetOuputFile(string file){xs.ResultFile=file;return;};
    void SetNumThreads(int nrth){xs.NrThreads=nrth;return;};
    void SetY(double Y){xs.Y=Y;return;};
    
    
    //Do Stuff
    void IntegrateCrossSection();
    void IntegrateDistributions();


};




#endif
