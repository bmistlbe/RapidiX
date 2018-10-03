#include "../includes/CrossSection.h"



void CrossSection::SetNNLO()
{

    //NNLO XS and Grid Stuff
/*#include "../XS/NumericalNNLO/xs_g_g.txt"
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
#include "../XS/NNLOLogImproved/xs_g_g.txt"
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
    
    //Approximated XS:
#include "../XS/NNLOLogImproved/xs_LogImproved_g_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_g_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_qbar.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImproved_q_Q2.txt"
    AddSubtractRegularNNLO();
    //*/
    
/*#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_g_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_g.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_g_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_qbar.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_q.txt"
#include "../XS/NNLOLogImproved/xs_LogImprovedUnmatched_q_Q2.txt"
    //*/
    return;
}

