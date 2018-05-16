


#ifndef Lumi_h
#define Lumi_h


#include "GlobalDefs.h"
#include "PDF.h"

class Luminosity{


private:
public:
    
    
    PDFF * pdf;
    double pdfvals[2][12];
    double L[6];
    double Lgg00;
    double Lgg01;
    double Lgg10;
    double Lgg11;
    double Lgq01;
    double Lqg10;
    
    Luminosity()
    {
        for(int i=0;i<6;++i)
            L[i]=0;
    };
    double GetPDFValue(int parton,int side,bool limit);
    void StorePDFValues(double x1,double x2,double lb1,double lb2);
    void SetLuminosity(double x1,double x2,double lb1,double lb2);
    
    double Lumi(int parton1,int parton2,bool lim1, bool lim2);
    double Lgg(bool lim1,bool lim2);
    double Lqg(bool lim2);
    double Lgq(bool lim1);
    double Lqqbar();
    double Lqq();
    double LqQ2();
    
};



#endif
