#include "../includes/Wilson.h"

vector<double> beta={
    1.9166666666666667,
    2.4166666666666665,
    2.826678240740741,
    18.85217316,
    0,
    0
};

vector<double> MuREvolution(double Lfr,const vector<double> & xs)
{
    vector<double> evolved;
    evolved.push_back(xs[0]);
    evolved.push_back(-2*Lfr*beta[0]*xs[0] + xs[1]);
    evolved.push_back((pow(Lfr,2)*pow(beta[0],2) + 2*(pow(Lfr,2)*pow(beta[0],2) - Lfr*beta[1]))*xs[0] - 3*Lfr*beta[0]*xs[1] + xs[2]);
    evolved.push_back((-2*Lfr*beta[0]*(pow(Lfr,2)*pow(beta[0],2) - Lfr*beta[1]) + 2*(-(pow(Lfr,3)*pow(beta[0],3)) + (5*pow(Lfr,2)*beta[0]*beta[1])/2. - Lfr*beta[2]))*xs[0] + (pow(Lfr,2)*pow(beta[0],2) - Lfr*beta[1])*xs[1] + (pow(Lfr,2)*pow(beta[0],2) + 2*(pow(Lfr,2)*pow(beta[0],2) - Lfr*beta[1]))*xs[1] - 2*Lfr*beta[0]*xs[2] - 2*Lfr*beta[0]*(-(Lfr*beta[0]*xs[1]) + xs[2]) + xs[3]);
    return evolved;
}



vector<double> WilsonCoeff(double mt,double mut, int mode)
{
    vector<double> coef;
    if(mode==0)
    {
        coef.push_back(1);
        coef.push_back(0);
        coef.push_back(0);
        coef.push_back(0);
        return coef;
    }//MSBAR
    else if(mode==1)
    {
        double Lft=2*log(mt/mut);
        double nf=5;
        coef.push_back(1);
        coef.push_back(2.75);
        coef.push_back(9.64236111111111 - 1.1875*Lft - 0.6979166666666666*nf - 0.3333333333333333*Lft*nf);
        coef.push_back(47.37038527373312 - 6.017361111111111*Lft + 3.265625*pow(Lft,2) - 7.689669777810332*nf - 1.0185185185185186*Lft*nf + 0.71875*pow(Lft,2)*nf -
                       0.22071116255144033*pow(nf,2) - 0.04456018518518518*Lft*pow(nf,2) - 0.05555555555555555*pow(Lft,2)*pow(nf,2));        
        return Multiply(coef,coef);
    }//ONSHELL
    else if(mode==2)
    {
        vector<double> coef;
        double L=-2*log(mt/mut);
        double nf=5;
        double z3=1.202056903159594;
        coef.push_back(1);
        coef.push_back(2.75);
        coef.push_back(2777./288. - nf * 67./96.+ L * (19./16.+nf/3.));
        coef.push_back((-16567986
                        + 2088288*L
                        + 812592*pow(L,2)
                        + 704676*nf
                        + 419328*L*nf
                        + 178848*pow(L,2)*nf
                        - 54920*pow(nf,2)
                        + 11088*L*pow(nf,2)
                        - 13824*pow(L,2)*pow(nf,2)
                        + 24244461*z3
                        - 1994022*nf*z3)/248832.);
        return Multiply(coef,coef);
    }
    
    
}
//*/
