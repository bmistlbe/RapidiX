#ifndef Wilson_h
#define Wilson_h

#include "../includes/GlobalDefs.h"
#include "../includes/PDF.h"

vector<double> WilsonCoeff(double mt,double mut,int mode);
vector<double> MuREvolution(double Lfr,const vector<double> & xs);

#endif
