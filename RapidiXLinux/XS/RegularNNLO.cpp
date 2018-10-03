#include "../includes/CrossSection.h"


vector<double> EvaluateNNLORegular(double x1,double x2)
{
    vector<double> reg(6,0);
#include "../XS/NNLOLogImproved/xs_NNLO_RegularVector.txt"
    return reg;
}

void CrossSection::AddSubtractRegularNNLO()
{
    double zb=1-x1*x2;
    double JJJ=(x1+x2)/2.0/(1-zb*xb);
    vector<double> reg=EvaluateNNLORegular(x1,x2);
    vector<double> regsubt=EvaluateNNLORegular(zb*(1-xb)/(1-xb*zb),xb*zb);
    
    for(int i=0;i<reg.size();i++)
        XSCoef[2][i][0][0]+=reg[i]-JJJ*regsubt[i];
    return;
}
