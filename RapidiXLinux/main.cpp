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

    int zbpow=200;
    vector<int *> zbpowvec={&delcoefm2,&delcoefm1,&delcoef0,&delcoef1,&delcoef2,&delcoef3,&delcoef4,&delcoef5,&delcoef6};
    if(argc>2)
        zbpow=atoi(argv[2]);
    for(int j=zbpow;j<zbpowvec.size();++j)
        (*zbpowvec[j])=0;

    Higgs xs;
    xs.SetMuf(val);
    xs.SetMur(val);
    xs.SetE(13000);
    xs.Setmt(162.7);
    //xs.Setmt(173.2);
    
    //0=off,1=MSB,2=OS
    xs.SetWilsonCoefficientMode(0);
    xs.SetPDF(0,"MMHT2014nnlo68cl");
    //xs.SetPDF(0,"PDF4LHC15_nnlo_mc");
    xs.SetVerbose(2);
    xs.SetPrecision(5e-3);
    xs.SetNumThreads(8);
    
    xs.xs.x1=0.9;
    xs.xs.x2=0.9;
    xs.xs.ComputeDummyVariables();
    xs.xs.SetCoefs();
    cout<<"xs: "<<xs.xs.XSCoef[2][0][0][0]<<endl;
    cout<<"xs: "<<xs.xs.XSCoef[2][0][0][1]<<endl;
    cout<<"xs: "<<xs.xs.XSCoef[2][0][0][2]<<endl;
    cout<<"xs: "<<xs.xs.XSCoef[2][0][0][3]<<endl;
    
    stringstream ss;
    ss.str("");
    ss<<path<<"Results/Rapidity/CrossSection_N3LOExpMatched_mu"<<val<<"_zbpow"<<zbpow<<".txt";

    xs.IntegrateCrossSection();
    /*
    string file=ss.str();
    ss.str("");
    ss<<"{";
    for(int j=0;j<xs.xs.xs.size();++j)
    {
        for(int k=0;k<xs.xs.xs[j].size();++k)
        {
            ss<<"{"<<xs.xs.xs[j][k]<<","<<xs.xs.error[j][k]<<"},";
        }
    }
    ss<<"}";
    ofstream out;
    out.open(file.c_str());
    out<<ss.str()<<endl;
    out.close();
     //*/

    return 0;
}
