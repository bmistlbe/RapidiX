#ifndef PDF_h
#define PDF_h


#include "../includes/GlobalDefs.h"
#include "LHAPDF/GridPDF.h"

extern vector<double> beta;
int FindGridPoint(double x);
double Interpolator(double xx ,const vector<double> & x, const vector<double> & v);

class PDFF
{
    
private:
public:
    string setname;
    int member;
    LHAPDF::GridPDF * pdf;
    double mZ;
    double mT;
    double alphamZ;
    
    
    int n;
    bool gridmode;
    vector<vector<double> > grid_large,grid_mid,grid_small;
    double b1,b2,b3;
    double a1,a2,a3;
    int InterpolationPower;
    vector<double> pos;
    double gridmuf;
    
    

    
    PDFF()
    {
        beta[0]=1.9166666666666667;
        beta[1]=2.4166666666666665;
        beta[2]=2.826678240740741;
        beta[3]=18.85217316;
        beta[4]=0;
        
        member=0;
        setname="";
        mZ=0;
        pdf=NULL;
        alphamZ=0;
        mT=0;
        
        
        
        //Grid Related stuff
        b1=0.005;
        b2=0.2;
        b3=1.0;
        a1=1000;
        a2=10;
        a3=0.001;
        
        gridmuf=125;
        grid_large.resize(11);
        grid_mid.resize(11);
        grid_small.resize(11);
        gridmode=false;
        n=10000;
        InterpolationPower=3;
        pos.resize(InterpolationPower,0);
    };
    
    //Set Variables
    void SetMZ(double mz){mZ=mz; alphamZ=GetAlphaFromPDF(mz);};
    void SetMT(double mt){mT=mt;};
    void SetMuf(double muf){gridmuf=muf;return;};
    
    //PDF Functions
    void InitiatePDF(string sname,int setnr);
    double MyxfxQ2(double x,double Q,int flavour);
    double GetValue(double x, double Q,int parton);
    double GetValue(double x, int parton);
    double GetAlphaFromPDF(double mu);
    double GetAlpha(double mu);
    double GetMT(double mu);
    
    //Grids
    double GetX(int i,double a,double b,int n);
    void CreateGrid(double muf);
    double ReadFromGrid(double z,int flav);
    double ComputeValue(double x,int flav);
    
    
    
};


#endif
