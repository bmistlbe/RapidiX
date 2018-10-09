#include "../includes/CrossSection.h"



void CrossSection::SetNNLO()
{

    //NNLO XS and Grid Stuff
#include "../XS/NumericalNNLO/xs_g_g.txt"
#include "../XS/NumericalNNLO/xs_q_g.txt"
#include "../XS/NumericalNNLO/xs_g_q.txt"
#include "../XS/NumericalNNLO/xs_q_qbar.txt"
#include "../XS/NumericalNNLO/xs_q_q.txt"
#include "../XS/NumericalNNLO/xs_q_Q2.txt"
    
#include "../XS/NumericalNNLO/xs_g_g_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_g_GridPart.txt"
#include "../XS/NumericalNNLO/xs_g_q_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_qbar_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_q_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_Q2_GridPart.txt"
    //*/
    
    //NNLO XS Log Improved Approximation + exact factorisation scale logs
    //MuF Logs:
/*#include "../XS/NNLOLogImproved/xs_g_g.txt"
#include "../XS/NNLOLogImproved/xs_q_g.txt"
#include "../XS/NNLOLogImproved/xs_g_q.txt"
#include "../XS/NNLOLogImproved/xs_q_qbar.txt"
#include "../XS/NNLOLogImproved/xs_q_q.txt"
#include "../XS/NNLOLogImproved/xs_q_Q2.txt"
    
#include "../XS/NNLOLogImproved/xs_g_g_GridPart.txt"
#include "../XS/NNLOLogImproved/xs_q_g_GridPart.txt"
#include "../XS/NNLOLogImproved/xs_g_q_GridPart.txt"
#include "../XS/NNLOLogImproved/xs_q_qbar_GridPart.txt"
#include "../XS/NNLOLogImproved/xs_q_q_GridPart.txt"
#include "../XS/NNLOLogImproved/xs_q_Q2_GridPart.txt"
    //*/
    
/*#include "../XS/NNLOLogImproved/xs_LogImproved_g_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_g_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_qbar.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_Q2.txt"
     //*/
    
/*#include "../XS/NNLOLogImproved/xs_ThresholdOnly_g_g.txt"
#include "../XS/NNLOLogImproved/xs_ThresholdOnly_q_g.txt"
#include "../XS/NNLOLogImproved/xs_ThresholdOnly_g_q.txt"
#include "../XS/NNLOLogImproved/xs_ThresholdOnly_q_qbar.txt"
#include "../XS/NNLOLogImproved/xs_ThresholdOnly_q_q.txt"
#include "../XS/NNLOLogImproved/xs_ThresholdOnly_q_Q2.txt"
    //*/
    
    
/*#include "../XS/NNLOLogImproved/xs_THOnlyMatched_g_g.txt"
#include "../XS/NNLOLogImproved/xs_THOnlyMatched_q_g.txt"
#include "../XS/NNLOLogImproved/xs_THOnlyMatched_g_q.txt"
#include "../XS/NNLOLogImproved/xs_THOnlyMatched_q_qbar.txt"
#include "../XS/NNLOLogImproved/xs_THOnlyMatched_q_q.txt"
#include "../XS/NNLOLogImproved/xs_THOnlyMatched_q_Q2.txt"
    //*/

/*#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_g_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_g_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_qbar.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_Q2.txt"
    //*/
    
    
    //Approximated XS:
    /*auto subtraction = nnlo_subtraction(1-x1*x2);
    double JJJ=-(x1+x2)/2.0/(1-x1*x2);
    XSCoef[2][0][0][0]+=JJJ*subtraction[0];
    XSCoef[2][1][0][0]+=JJJ*subtraction[1];
    XSCoef[2][2][0][0]+=JJJ*subtraction[2];
    XSCoef[2][3][0][0]+=JJJ*subtraction[3];
    XSCoef[2][4][0][0]+=JJJ*subtraction[4];
    XSCoef[2][5][0][0]+=JJJ*subtraction[5];
    //*/
    return;
}

