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
    if(argc!=2)
    {
        cout<<"Usage: ./main.out scale"<<endl;
        return 0;
    }
    val=atof(argv[1]);
    
    Higgs xs;
    xs.SetMuf(val);
    xs.SetMur(val);
    xs.SetE(13000);
    xs.Setmt(162.7);
    
    //0=off,1=MSB,2=OS
    xs.SetWilsonCoefficientMode(1);
    //xs.SetPDF(0,"MMHT2014nnlo68cl");
    xs.SetPDF(0,"PDF4LHC15_nnlo_100");
    xs.SetVerbose(2);
    xs.SetPrecision(1e-2);
    xs.SetNumThreads(8);
    
    vector<vector<double> > res,err;
    xs.SetOuputFile("Output.txt");
    xs.IntegrateCrossSection();
    xs.IntegrateDistributions();
        
    return 0;
}
