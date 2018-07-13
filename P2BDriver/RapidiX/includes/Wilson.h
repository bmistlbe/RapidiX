#ifndef Wilson_h
#define Wilson_h

#include "../includes/GlobalDefs.h"

extern vector<double> beta;
vector<double> WilsonCoeff(double mt,double mut,int mode);
vector<double> MuREvolution(double Lfr,const vector<double> & xs);

#endif
