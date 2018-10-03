#include "../includes/CrossSection.h"


vector<double> EvaluateNNLORegular(double x1,double x2)
{
    vector<double> reg(6,0);
#include "../XS/NNLOLogImproved/xs_NNLO_RegularVector.txt"
    return reg;
}

void CrossSection::AddSubtractRegularNNLO()
{
    double xb1=zb*xb;
    double xb2=(1-zb)*xb+zb;
    double J1=(x1+x2)/2.0/(1-zb*xb1);
    double J2=(x1+x2)/2.0/(1-zb*xb2);
    
    vector<double> reg=EvaluateNNLORegular(x1,x2);
    vector<double> regsubt1=EvaluateNNLORegular(zb*(1-xb1)/(1-xb1*zb),xb1*zb);
    vector<double> regsubt2=EvaluateNNLORegular(zb*(1-xb2)/(1-xb2*zb),xb2*zb);
    
    for(int i=0;i<reg.size();i++)
        XSCoef[2][i][0][0]+=reg[i]-J1*regsubt1[i]-J2*regsubt2[i];
    return;
}
