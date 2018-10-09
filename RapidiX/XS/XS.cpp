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
 //*/
    return;
}




void CrossSection::ReadGrids()
{
    NNLOGrider[0][0][0].ReadGrid(0,0,0,2);
    NNLOGrider[0][0][1].ReadGrid(0,0,1,2);
    NNLOGrider[0][0][2].ReadGrid(0,0,2,2);
    NNLOGrider[0][0][6].ReadGrid(0,0,6,2);
    NNLOGrider[0][0][7].ReadGrid(0,0,7,2);
    NNLOGrider[0][0][11].ReadGrid(0,0,11,2);
    NNLOGrider[0][1][0].ReadGrid(0,1,0,2);
    NNLOGrider[0][1][1].ReadGrid(0,1,1,2);
    NNLOGrider[0][1][6].ReadGrid(0,1,6,2);
    NNLOGrider[0][2][0].ReadGrid(0,2,0,2);
    
    NNLOGrider[1][0][0].ReadGrid(1,0,0,2);
    NNLOGrider[1][0][1].ReadGrid(1,0,1,2);
    NNLOGrider[1][0][2].ReadGrid(1,0,2,2);
    NNLOGrider[1][0][6].ReadGrid(1,0,6,2);
    NNLOGrider[1][0][7].ReadGrid(1,0,7,2);
    NNLOGrider[1][0][11].ReadGrid(1,0,11,2);
    NNLOGrider[1][1][0].ReadGrid(1,1,0,2);
    NNLOGrider[1][1][1].ReadGrid(1,1,1,2);
    NNLOGrider[1][1][6].ReadGrid(1,1,6,2);
    NNLOGrider[1][2][0].ReadGrid(1,2,0,2);
    
    NNLOGrider[2][0][0].ReadGrid(2,0,0,2);
    NNLOGrider[2][0][1].ReadGrid(2,0,1,2);
    NNLOGrider[2][0][2].ReadGrid(2,0,2,2);
    NNLOGrider[2][0][6].ReadGrid(2,0,6,2);
    NNLOGrider[2][0][7].ReadGrid(2,0,7,2);
    NNLOGrider[2][0][11].ReadGrid(2,0,11,2);
    NNLOGrider[2][1][0].ReadGrid(2,1,0,2);
    NNLOGrider[2][1][1].ReadGrid(2,1,1,2);
    NNLOGrider[2][1][6].ReadGrid(2,1,6,2);
    NNLOGrider[2][2][0].ReadGrid(2,2,0,2);
    
    NNLOGrider[3][0][0].ReadGrid(3,0,0,2);
    NNLOGrider[3][0][1].ReadGrid(3,0,1,2);
    NNLOGrider[3][0][2].ReadGrid(3,0,2,2);
    NNLOGrider[3][0][6].ReadGrid(3,0,6,2);
    NNLOGrider[3][0][7].ReadGrid(3,0,7,2);
    NNLOGrider[3][0][11].ReadGrid(3,0,11,2);
    NNLOGrider[3][1][0].ReadGrid(3,1,0,2);
    NNLOGrider[3][1][1].ReadGrid(3,1,1,2);
    NNLOGrider[3][1][6].ReadGrid(3,1,6,2);
    NNLOGrider[3][2][0].ReadGrid(3,2,0,2);
    
    NNLOGrider[4][0][0].ReadGrid(4,0,0,2);
    NNLOGrider[4][0][1].ReadGrid(4,0,1,2);
    NNLOGrider[4][0][2].ReadGrid(4,0,2,2);
    NNLOGrider[4][0][6].ReadGrid(4,0,6,2);
    NNLOGrider[4][0][7].ReadGrid(4,0,7,2);
    NNLOGrider[4][0][11].ReadGrid(4,0,11,2);
    NNLOGrider[4][1][0].ReadGrid(4,1,0,2);
    NNLOGrider[4][1][1].ReadGrid(4,1,1,2);
    NNLOGrider[4][1][6].ReadGrid(4,1,6,2);
    NNLOGrider[4][2][0].ReadGrid(4,2,0,2);
    
    NNLOGrider[5][0][0].ReadGrid(5,0,0,2);
    NNLOGrider[5][0][1].ReadGrid(5,0,1,2);
    NNLOGrider[5][0][2].ReadGrid(5,0,2,2);
    NNLOGrider[5][0][6].ReadGrid(5,0,6,2);
    NNLOGrider[5][0][7].ReadGrid(5,0,7,2);
    NNLOGrider[5][0][11].ReadGrid(5,0,11,2);
    NNLOGrider[5][1][0].ReadGrid(5,1,0,2);
    NNLOGrider[5][1][1].ReadGrid(5,1,1,2);
    NNLOGrider[5][1][6].ReadGrid(5,1,6,2);
    NNLOGrider[5][2][0].ReadGrid(5,2,0,2);
    //*/
    return;

}
