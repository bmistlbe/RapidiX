#include <complex>
#include <array>
#include "functions.hpp"

extern "C"{
    std::complex<double> hpl1_(int *n1, std::complex<double> *x);
    std::complex<double> hpl2_(int *n1, int *n2, std::complex<double> *x);
    std::complex<double> hpl3_(int *n1, int *n2, int *n3, std::complex<double> *x);
    std::complex<double> hpl4_(int *n1, int *n2, int *n3, int *n4, std::complex<double> *x);

}
double H(int n1, double x){
    std::complex<double> arg = x;
    std::complex<double> res = hpl1_(&n1,&arg);
    return res.real();
}
double H(int n1, int n2, double x){
    std::complex<double> arg = x;
    std::complex<double> res = hpl2_(&n1,&n2,&arg);
    return res.real();
}
double H(int n1, int n2, int n3, double x){
    std::complex<double> arg = x;
    std::complex<double> res = hpl3_(&n1,&n2,&n3,&arg);
    return res.real();
}
double H(int n1, int n2, int n3, int n4, double x){
    std::complex<double> arg = x;
    std::complex<double> res = hpl4_(&n1,&n2,&n3,&n4,&arg);
    return res.real();
}
std::complex<double> li2(std::complex<double> x){
    int n1 = 0;
    int n2 = 1;
    std::complex<double> res = hpl2_(&n1,&n2,&x);
    return res;
}
std::complex<double> li3(std::complex<double> x){
    int n1 = 0;
    int n2 = 0;
    int n3 = 1;
    std::complex<double> res = hpl3_(&n1,&n2,&n3,&x);
    return res;
}
std::array<double,ImCount> prepare_imag_parts(double zb){
    std::complex<double> im{0,1};
    std::array<double, ImCount> res;
    std::complex<double> xb = sqrt(1-zb);
    std::array<std::complex<double>, ImCount> tmp{log(1. - (1.*xb)/im),
        3.668533635067843 + li2(0.5*(1. - 1.*im)) - 1.*li2(1. - 1.*im) + 0.5*li2((0.5*(im - 1.*xb)*(-1. + xb))/((1. + im)*xb)) - 1.*li2((1. - 1.*im)/(1. + xb)) + li2(((-1. + im)*(-1. + xb))/((1. + im)*(1. + xb))) - 0.5*li2((0.5*(im - 1.*xb)*(1. + xb))/((-1. + im)*xb)) - 1.*li2(((1. + im)*xb)/(im + xb)) - 1.*li2((im*(1. + xb))/(im + xb)) + 0.5*li2(((im - 1.*xb)*(im + xb))/(-1. + pow(im,2))) + 3.4657359027997265*log(0.5*(1. - 1.*im)) + 3.*pow(log(0.5*(1. - 1.*im)),2) + 0.6931471805599453*log((4.*im)/pow(1. + im,2)) + log(0.5*(1. - 1.*im))*log((4.*im)/pow(1. + im,2)) - 0.6931471805599453*log(1. - 1.*pow(im,2)) - 2.*log(0.5*(1. - 1.*im))*log(1. - 1.*pow(im,2)) - 1.*log((4.*im)/pow(1. + im,2))*log(1. - 1.*pow(im,2)) - 1.*pow(log(1. - 1.*pow(im,2)),2) + 2.*log(1. - 1.*pow(im,2))*log(1. - (1.*pow(im,2))/pow(xb,2)) - 1.*pow(log(1. - (1.*pow(im,2))/pow(xb,2)),2) + 2.0794415416798357*log((-1. + xb)/(-1. + im)) + 4.*log(0.5*(1. - 1.*im))*log((-1. + xb)/(-1. + im)) + log((4.*im)/pow(1. + im,2))*log((-1. + xb)/(-1. + im)) - 4.*log(1. - 1.*pow(im,2))*log((-1. + xb)/(-1. + im)) + 2.*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1. + xb)/(-1. + im)) + 0.5*pow(log((-1. + xb)/(-1. + im)),2) - 2.*log(1. - 1.*pow(im,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) + 2.*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 3.*log((-1. + xb)/(-1. + im))*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 1.*pow(log((-1.*(im - 1.*xb))/(xb + im*xb)),2) - 1.*log(1. - 1.*pow(im,2))*log((im + im*xb)/(xb + im*xb)) + log(1. - (1.*pow(im,2))/pow(xb,2))*log((im + im*xb)/(xb + im*xb)) - 1.*log((-1.*(im - 1.*xb))/(xb + im*xb))*log((im + im*xb)/(xb + im*xb)) - 2.0794415416798357*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 2.5*log(0.5*(1. - 1.*im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 2.5*log(1. - 1.*pow(im,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 0.5*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.5*log((-1. + xb)/(-1. + im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 1.5*log((-1.*(im - 1.*xb))/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.*log((im + im*xb)/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + pow(log((-1. + pow(xb,2))/(-1. + pow(im,2))),2) + 3.141592653589793*im*(-1.*log((-1. + xb)/(-1. + im)) + log((-1. + pow(xb,2))/(-1. + pow(im,2)))),
        1.9218120556728056 + li2(0.5*(1. - 1.*im)) + 0.25*li2(pow(im,2)) - 0.5*li2((1. - 1.*xb)/(1. + im)) + 0.5*li2((0.5*(im - 1.*xb)*(-1. + xb))/((1. + im)*xb)) - 0.25*li2(pow(xb,2)) - 1.5*li2((1. - 1.*im)/(1. + xb)) + li2(((-1. + im)*(-1. + xb))/((1. + im)*(1. + xb))) - 0.5*li2((0.5*(im - 1.*xb)*(1. + xb))/((-1. + im)*xb)) - 0.5*li2(((1. + im)*xb)/(im + xb)) - 0.5*li2((im*(1. + xb))/(im + xb)) + 0.5*li2(((im - 1.*xb)*(im + xb))/(-1. + pow(im,2))) - 1.*li2((-1.*(im - 1.*xb))/(xb + im*xb)) + 4.1588830833596715*log(0.5*(1. - 1.*im)) + 2.5*pow(log(0.5*(1. - 1.*im)),2) - 2.772588722239781*log(1. - 1.*pow(im,2)) - 3.*log(0.5*(1. - 1.*im))*log(1. - 1.*pow(im,2)) + 0.5*pow(log(1. - 1.*pow(im,2)),2) + log(1. - 1.*pow(im,2))*log(1. - (1.*pow(im,2))/pow(xb,2)) - 0.5*pow(log(1. - (1.*pow(im,2))/pow(xb,2)),2) + 3.4657359027997265*log((-1. + xb)/(-1. + im)) + 4.*log(0.5*(1. - 1.*im))*log((-1. + xb)/(-1. + im)) - 3.5*log(1. - 1.*pow(im,2))*log((-1. + xb)/(-1. + im)) + log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1. + xb)/(-1. + im)) + 0.75*pow(log((-1. + xb)/(-1. + im)),2) - 1.*log(1. - 1.*pow(im,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) + log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 2.*log((-1. + xb)/(-1. + im))*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 0.5*pow(log((-1.*(im - 1.*xb))/(xb + im*xb)),2) + 0.6931471805599453*log((im + im*xb)/(xb + im*xb)) + log(0.5*(1. - 1.*im))*log((im + im*xb)/(xb + im*xb)) - 1.*log(1. - 1.*pow(im,2))*log((im + im*xb)/(xb + im*xb)) + 0.5*log(1. - (1.*pow(im,2))/pow(xb,2))*log((im + im*xb)/(xb + im*xb)) + log((-1. + xb)/(-1. + im))*log((im + im*xb)/(xb + im*xb)) - 1.5*log((-1.*(im - 1.*xb))/(xb + im*xb))*log((im + im*xb)/(xb + im*xb)) + 0.5*pow(log((im + im*xb)/(xb + im*xb)),2) - 2.772588722239781*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 2.5*log(0.5*(1. - 1.*im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 0.5*log((4.*im)/pow(1. + im,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 2.*log(1. - 1.*pow(im,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.5*log((-1. + xb)/(-1. + im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + log((-1.*(im - 1.*xb))/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.5*log((im + im*xb)/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 0.75*pow(log((-1. + pow(xb,2))/(-1. + pow(im,2))),2) + 3.141592653589793*im*(-1.*log((-1. + xb)/(-1. + im)) - 1.*log((im + im*xb)/(xb + im*xb)) + log((-1. + pow(xb,2))/(-1. + pow(im,2)))),
        -3.1880806211496413 - 1.*li2(0.5*(1. - 1.*im)) + li2(1. - 1.*im) + 0.5*li2(pow(im,2)) + li2((1. - 1.*xb)/(1. + im)) - 0.5*li2((0.5*(im - 1.*xb)*(-1. + xb))/((1. + im)*xb)) - 1.*li2(((-1. + im)*(-1. + xb))/((1. + im)*(1. + xb))) + 0.5*li2((0.5*(im - 1.*xb)*(1. + xb))/((-1. + im)*xb)) + li2(((1. + im)*xb)/(im + xb)) + li2((im*(1. + xb))/(im + xb)) + 0.5*li2(((im - 1.*xb)*(im + xb))/(-1. + pow(im,2))) - 2.0794415416798357*log(0.5*(1. - 1.*im)) - 2.*pow(log(0.5*(1. - 1.*im)),2) - 0.6931471805599453*log((4.*im)/pow(1. + im,2)) - 1.*log(0.5*(1. - 1.*im))*log((4.*im)/pow(1. + im,2)) + log(0.5*(1. - 1.*im))*log(1. - 1.*pow(im,2)) + log((4.*im)/pow(1. + im,2))*log(1. - 1.*pow(im,2)) + 1.5*pow(log(1. - 1.*pow(im,2)),2) - 2.*log(1. - 1.*pow(im,2))*log(1. - (1.*pow(im,2))/pow(xb,2)) + pow(log(1. - (1.*pow(im,2))/pow(xb,2)),2) - 2.0794415416798357*log((-1. + xb)/(-1. + im)) + 3.141592653589793*im*log((-1. + xb)/(-1. + im)) - 4.*log(0.5*(1. - 1.*im))*log((-1. + xb)/(-1. + im)) - 1.*log((4.*im)/pow(1. + im,2))*log((-1. + xb)/(-1. + im)) + 4.*log(1. - 1.*pow(im,2))*log((-1. + xb)/(-1. + im)) - 2.*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1. + xb)/(-1. + im)) - 1.*pow(log((-1. + xb)/(-1. + im)),2) + 2.*log(1. - 1.*pow(im,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 2.*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) + 3.*log((-1. + xb)/(-1. + im))*log((-1.*(im - 1.*xb))/(xb + im*xb)) + pow(log((-1.*(im - 1.*xb))/(xb + im*xb)),2) + log(1. - 1.*pow(im,2))*log((im + im*xb)/(xb + im*xb)) - 1.*log(1. - (1.*pow(im,2))/pow(xb,2))*log((im + im*xb)/(xb + im*xb)) + log((-1.*(im - 1.*xb))/(xb + im*xb))*log((im + im*xb)/(xb + im*xb)) + 1.5*log(0.5*(1. - 1.*im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + log((4.*im)/pow(1. + im,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.5*log(1. - 1.*pow(im,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 1.5*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 0.5*log((-1. + xb)/(-1. + im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.5*log((-1.*(im - 1.*xb))/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.*log((im + im*xb)/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 0.5*pow(log((-1. + pow(xb,2))/(-1. + pow(im,2))),2),
        -2.984505596056019 - 1.*li2(0.5*(1. - 1.*im)) + li2((1. - 1.*xb)/(1. + im)) - 1.*li2((0.5*(im - 1.*xb)*(-1. + xb))/((1. + im)*xb)) + li2((1. - 1.*im)/(1. + xb)) - 1.*li2(((-1. + im)*(-1. + xb))/((1. + im)*(1. + xb))) + li2(((1. + im)*xb)/(im + xb)) + li2((-1.*(im - 1.*xb))/(xb + im*xb)) - 3.4657359027997265*log(0.5*(1. - 1.*im)) - 1.5*pow(log(0.5*(1. - 1.*im)),2) + 2.0794415416798357*log(1. - 1.*pow(im,2)) + log(0.5*(1. - 1.*im))*log(1. - 1.*pow(im,2)) + 0.5*pow(log(1. - 1.*pow(im,2)),2) + 0.6931471805599453*log(1. - (1.*pow(im,2))/pow(xb,2)) + log(0.5*(1. - 1.*im))*log(1. - (1.*pow(im,2))/pow(xb,2)) - 2.*log(1. - 1.*pow(im,2))*log(1. - (1.*pow(im,2))/pow(xb,2)) + 0.5*pow(log(1. - (1.*pow(im,2))/pow(xb,2)),2) - 3.4657359027997265*log((-1. + xb)/(-1. + im)) - 4.*log(0.5*(1. - 1.*im))*log((-1. + xb)/(-1. + im)) + 4.*log(1. - 1.*pow(im,2))*log((-1. + xb)/(-1. + im)) - 1.*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1. + xb)/(-1. + im)) - 0.5*pow(log((-1. + xb)/(-1. + im)),2) + log(1. - (1.*xb)/im)*log(1. + xb/im) - 0.6931471805599453*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 2.*log(0.5*(1. - 1.*im))*log((-1.*(im - 1.*xb))/(xb + im*xb)) + 3.*log(1. - 1.*pow(im,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 2.*log(1. - (1.*pow(im,2))/pow(xb,2))*log((-1.*(im - 1.*xb))/(xb + im*xb)) + 2.*log((-1. + xb)/(-1. + im))*log((-1.*(im - 1.*xb))/(xb + im*xb)) + 1.5*pow(log((-1.*(im - 1.*xb))/(xb + im*xb)),2) - 0.6931471805599453*log((im + im*xb)/(xb + im*xb)) - 1.*log(0.5*(1. - 1.*im))*log((im + im*xb)/(xb + im*xb)) + log(1. - 1.*pow(im,2))*log((im + im*xb)/(xb + im*xb)) - 1.*log((-1. + xb)/(-1. + im))*log((im + im*xb)/(xb + im*xb)) + log((-1.*(im - 1.*xb))/(xb + im*xb))*log((im + im*xb)/(xb + im*xb)) - 0.5*pow(log((im + im*xb)/(xb + im*xb)),2) + 2.0794415416798357*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + 2.*log(0.5*(1. - 1.*im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 2.*log(1. - 1.*pow(im,2))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + log((-1. + xb)/(-1. + im))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 1.*log((-1.*(im - 1.*xb))/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) + log((im + im*xb)/(xb + im*xb))*log((-1. + pow(xb,2))/(-1. + pow(im,2))) - 0.5*pow(log((-1. + pow(xb,2))/(-1. + pow(im,2))),2) - 3.141592653589793*im*(log(0.5*(1. - 1.*im)) - 1.*log(1. - 1.*pow(im,2)) + log(1. - (1.*pow(im,2))/pow(xb,2)) - 1.*log((-1. + xb)/(-1. + im)) - 1.*log((-1.*(im - 1.*xb))/(xb + im*xb)) - 1.*log((im + im*xb)/(xb + im*xb)) + log((-1. + pow(xb,2))/(-1. + pow(im,2)))),
        0.5*pow(log(1. - (1.*xb)/im),2)};

    for(unsigned int i=0;i < ImCount;i++){
        res[i] = tmp[i].imag();
    }
    return res;
}
std::array<double,ReCount> prepare_real_parts(double zb){
    std::complex<double> im{0,1};
    std::array<double, ReCount> res;
    std::complex<double> xb = sqrt(1-zb);
    std::array<std::complex<double>, ReCount> tmp{
#include "reals.inc"
    };
    for(unsigned int i=0;i < ReCount;i++){
        res[i] = tmp[i].real();
    }
    return res;
}

