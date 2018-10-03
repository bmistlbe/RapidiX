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
    //*/
 
    
#include "../XS/NumericalNNLO/xs_g_g_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_g_GridPart.txt"
#include "../XS/NumericalNNLO/xs_g_q_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_qbar_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_q_GridPart.txt"
#include "../XS/NumericalNNLO/xs_q_Q2_GridPart.txt"
    //*/
    
    
    
    //NNLO XS zb Expansion
/*#include "../XS/NNLOExp/xs_g_g.txt"
#include "../XS/NNLOExp/xs_q_g.txt"
#include "../XS/NNLOExp/xs_g_q.txt"
#include "../XS/NNLOExp/xs_q_qbar.txt"
#include "../XS/NNLOExp/xs_q_q.txt"
#include "../XS/NNLOExp/xs_q_Q2.txt"
    //*/
    

    //NNLO XS zb Expansion Regular Part - goes together with the first block of the Grid Stuff: Distribution valued stuff
/*#include "../XS/NNLOExp/xs_regular_g_g.txt"
#include "../XS/NNLOExp/xs_regular_q_g.txt"
#include "../XS/NNLOExp/xs_regular_g_q.txt"
#include "../XS/NNLOExp/xs_regular_q_qbar.txt"
#include "../XS/NNLOExp/xs_regular_q_q.txt"
#include "../XS/NNLOExp/xs_regular_q_Q2.txt"
    //*/
    
    //NNLO XS zb Expanded and matched to give exact inclusive cross section
/*#include "../XS/NNLOExpMatchedToInclusive/xs_g_g.txt"
#include "../XS/NNLOExpMatchedToInclusive/xs_q_g.txt"
#include "../XS/NNLOExpMatchedToInclusive/xs_g_q.txt"
#include "../XS/NNLOExpMatchedToInclusive/xs_q_qbar.txt"
#include "../XS/NNLOExpMatchedToInclusive/xs_q_q.txt"
#include "../XS/NNLOExpMatchedToInclusive/xs_q_Q2.txt"
//*/
    

    //NNLO XS zb Expanded Regular and matched to give exact inclusive cross section
/*#include "../XS/NNLOExpRegularMatchedToInclusive/xs_g_g.txt"
#include "../XS/NNLOExpRegularMatchedToInclusive/xs_q_g.txt"
#include "../XS/NNLOExpRegularMatchedToInclusive/xs_g_q.txt"
#include "../XS/NNLOExpRegularMatchedToInclusive/xs_q_qbar.txt"
#include "../XS/NNLOExpRegularMatchedToInclusive/xs_q_q.txt"
#include "../XS/NNLOExpRegularMatchedToInclusive/xs_q_Q2.txt"
    //*/
    return;
}
