
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include "cuba.h"

using namespace std;

#include "xs_NNLO_RegularFuncions.txt"
static int Integrand(const int *ndim, const double xx[], const int *ncomp, double ff[], void *userdata)
;
int global_initialstate=0;

double Integrate(double z)
{
    
    int NDIM=2;
 
    int NCOMP=1;
    int NVEC=1;
    double EPSREL= 1e-6;
    double EPSABS= 1e-18;
    int VERBOSE=2;
    int LAST=4;
    int SEED=0;
    int MINEVAL=1000;
    int MAXEVAL=500000000;
    int NSTART=1000;
    int NINCREASE=50000;
    int NBATCH=1000;
    int KEY=9;
    double res[NCOMP], err[NCOMP], chi[NCOMP];
    int comp, nregions, neval, fail,cuhre_key=9;
    
    
    Cuhre(NDIM, NCOMP, &Integrand, &z, NVEC,EPSREL, EPSABS, VERBOSE ,MINEVAL, MAXEVAL, KEY, NULL, NULL,&nregions, &neval, &fail, res,err,chi);
    return res[0];
}


static int Integrand(const int *ndim, const double xx[], const int *ncomp, double ff[], void *userdata)
{
    double  *z=(double*) userdata;
    double xb=xx[0];
    if(global_initialstate==0)
        ff[0]=NNLOReg_g_g(1-(*z),xb);
    if(global_initialstate==1)
        ff[0]=NNLOReg_q_g(1-(*z),xb);
    if(global_initialstate==2)
        ff[0]=NNLOReg_g_q(1-(*z),xb);
    if(global_initialstate==3)
        ff[0]=NNLOReg_q_qbar(1-(*z),xb);
    /*if(global_initialstate==4)
        ff[0]=NNLOReg_q_q(1-(*z),xb);
    if(global_initialstate==5)
        ff[0]=NNLOReg_q_Q2(1-(*z),xb);
    //*/
    
    cout<<(*z)<<" "<<xb<<" "<<ff[0]<<endl;

    return 0;
}

int main()
{
    global_initialstate=2;
    cout<<"Integrate Result: "<<Integrate(0.3)<<endl;
    
    return 0;
}
