#ifndef Grider_h
#define Grider_h

#include "../includes/GlobalDefs.h"





class Grider{

private:
public:
    
    
    int gridsize;
    vector<vector<double> > grid;
    bool loaded;
    int bin1,bin2;
    double x11,x12,x21,x22,x13,x23,f1,f2,f3,f4,f5,f6,f7,f8,f9;
    
    Grider(){
    
        gridsize=119;
        //gridsize=1000;
        loaded=false;
    };
    
    void ReadGrid(int state,int L1,int L2,int o);
    double GetValue(double x1,double x2);
    double xVal(int bin);
    
    ~Grider(){
        
    }
    
};


#endif