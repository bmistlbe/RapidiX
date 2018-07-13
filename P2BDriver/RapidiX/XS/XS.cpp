#include "../includes/CrossSection.h"


void CrossSection::SetCoefs()
{
    
    XSCoef[0][0][0][3]=1;
#include "../XS/NLO/xs_g_g.txt"
#include "../XS/NLO/xs_q_g.txt"
#include "../XS/NLO/xs_g_q.txt"
#include "../XS/NLO/xs_q_qbar.txt"
    SetNNLO();
    SetN3LO();
    return;
}


