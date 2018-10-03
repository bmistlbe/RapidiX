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
    path="";
    double val=0;
    
    if(argc<2)
    {
        cout<<"Usage: ./main.out scale zborder Y"<<endl;
        return 0;
    }
    val=atof(argv[1]);
    
    vector<int *> zbpowvec={&delcoefm2,&delcoefm1,&delcoef0,&delcoef1,&delcoef2,&delcoef3,&delcoef4,&delcoef5,&delcoef6};
    int zbpow=2;
    if(argc>2)
        zbpow=atoi(argv[2]);
    for(int j=zbpow;j<zbpowvec.size();++j)
        (*zbpowvec[j])=0;

    Higgs xs;
    xs.SetMuf(val);
    xs.SetMur(val);
    xs.SetE(13000);
    xs.Setmt(162.7);
    
    //0=off,1=MSB,2=OS
    xs.SetWilsonCoefficientMode(1);
    xs.SetPDF(0,"MMHT2014nnlo68cl");
    xs.SetVerbose(0);
    xs.SetPrecision(1e-3);
    xs.SetNumThreads(4);
    
    vector<vector<double> > res,err;
    stringstream ss;
    
    for(double i=0;i<4.5;i+=0.1)
    {
        if(argc==4)
            i=atof(argv[3])/10.0;
        
        cout<<"Treating Rapidity "<<i<<endl;
        xs.SetY(i+1e-10);
        ss.str("");
        //ss<<path<<"Results/Rapidity/Rapidity_NNLOExpMatched_Y"<<i<<"_mu"<<val<<"_zbpow"<<zbpow<<".txt";
        ss<<path<<"Results/Rapidity/RapidityNoGrid_NNLO_Y"<<i<<"_mu"<<val<<".txt";
        xs.IntegrateCrossSection();
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
        
        if(argc==4)
            return 0;
    }
    return 0;
}
