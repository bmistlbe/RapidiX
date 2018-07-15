//
//  main.cpp
//  IXS
//
//  Created by Bernhard Mistlberger on 20/10/17.
//  Copyright © 2017 Bernhard Mistlberger. All rights reserved.
//

#include "includes/Higgs.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    cout<<setprecision(16);
    double val=0;
    if(argc<2)
    {
        cout<<"Usage: ./main.out scale"<<endl;
        return 0;
    }
    val=atof(argv[1]);
    
    
    /*Grider gr;
    gr.ReadGrid(4,0,0,2);
    cout<<gr.grid[0][0]<<endl;
    cout<<gr.grid[0][1]<<endl;
    cout<<gr.grid[1][0]<<endl;
    cout<<gr.grid[1][1]<<endl;
    if(argc==4)
        cout<<"GridValue at 1 1: "<<gr.GetValue(atof(argv[2]),atof(argv[3]))<<endl;
    for(double i=0.015;i<1;i+=0.015)
        cout<<gr.GetValue(1,i)<<",";
    cout<<endl;
    
    return 0;
    //*/
    
    Higgs xs;
    xs.SetMuf(val);
    xs.SetMur(val);
    xs.SetE(13000);
    xs.Setmt(162.7);
    
    //0=off,1=MSB,2=OS
    xs.SetWilsonCoefficientMode(1);
    xs.SetPDF(0,"MMHT2014nnlo68cl");
    //xs.SetPDF(0,"PDF4LHC15_nnlo_100");
    xs.SetVerbose(2);
    xs.SetPrecision(1e-2);
    xs.SetNumThreads(4);
    vector<int *> zbpowvec={&delcoefm2,&delcoefm1,&delcoef0,&delcoef1,&delcoef2,&delcoef3,&delcoef4,&delcoef5,&delcoef6};
    for(int j=6;j<zbpowvec.size();++j)
        (*zbpowvec[j])=0;

    vector<vector<double> > res,err;
    //xs.IntegrateCrossSection();
    //xs.IntegrateDistributions();
    //return 0;
    /*vector<int *> zbpowvec={&delcoefm2,&delcoefm1,&delcoef0,&delcoef1,&delcoef2,&delcoef3,&delcoef4,&delcoef5,&delcoef6};
    stringstream ss;
    for(int i=2;i<zbpowvec.size();++i)
    {
        cout<<"zb pow: "<<i<<endl;
        for(int j=0;j<zbpowvec.size();++j)
            if(j>i)
                (*zbpowvec[j])=0;
            else
                (*zbpowvec[j])=1;
        
        cout<<delcoefm2<<" "<<delcoefm1<<" "<<delcoef0<<" "<<delcoef6<<endl;
        ss.str("");
        ss<<"Results/NNLODistributions_Subtracted_zb"<<i<<"_625.txt";
        //ss<<"Results/NNLOExact_qQ2.txt";
        xs.SetOuputFile(ss.str());
        xs.IntegrateDistributions();
        cout<<"Back "<<endl;
    }
     //*/
    stringstream ss;
    ss<<"Results/Test.txt";
    xs.SetOuputFile(ss.str());
    xs.IntegrateCrossSection();
    //xs.IntegrateDistributions();
    return 0;
}
