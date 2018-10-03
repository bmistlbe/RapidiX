

#ifndef HPLs_h
#define HPLs_h

#include "../includes/GlobalDefs.h"
#include <complex>


extern "C" {
    std::complex<double> hpl1_(int *n1, std::complex<double> *x);
    std::complex<double> hpl2_(int *n1, int *n2, std::complex<double> *x);
    std::complex<double> hpl3_(int *n1, int *n2, int *n3, std::complex<double> *x);
    std::complex<double> hpl4_(int *n1, int *n2, int *n3, int *n4,std::complex<double> *x);
}


double HPL(int n1, double x);
double HPL(int n1, int n2, double x);
double HPL(int n1, int n2, int n3, double x);
double HPL(int n1, int n2, int n3, int n4, double x);

double H(int n1, double x);
double H(int n1, int n2, double x);
double H(int n1, int n2, int n3, double x);
double H(int n1, int n2, int n3, int n4, double x);
double H(int a1,int a2,int a3,int a4,int a5,double zb);


#endif
