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
    xs.SetWilsonCoefficientMode(0);
    //xs.SetPDF(0,"MMHT2014nnlo68cl");
    xs.SetPDF(0,"PDF4LHC15_nnlo_100");
    xs.SetVerbose(2);
    xs.SetPrecision(1e-3);
    xs.SetNumThreads(8);
    
    vector<vector<double> > res,err;
    //xs.IntegrateCrossSection();
    
    vector<int *> zbpowvec={&delcoefm2,&delcoefm1,&delcoef0,&delcoef1,&delcoef2,&delcoef3,&delcoef4};
    stringstream ss;
    for(int i=6;i<zbpowvec.size();++i)
    {
        for(int j=0;j<zbpowvec.size();++j)
            if(j>i)
                (*zbpowvec[j])=0;
            else
                (*zbpowvec[j])=1;
        
        ss.str("");
        ss<<"Results/Distributions_zb"<<i<<".txt";
        xs.SetOuputFile(ss.str());
        xs.IntegrateDistributions();
    }
        
    return 0;
}
