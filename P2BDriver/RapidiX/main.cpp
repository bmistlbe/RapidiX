//
//  main.cpp
//  RapidiX
//
//  Created by Bernhard Mistlberger on 20/10/17.
//  Copyright © 2017 Bernhard Mistlberger. All rights reserved.
//

#include "includes/CrossSection.h"

int main(int argc, const char * argv[]) {
   
    
    //Test Values for the axis;
    double x1=0.3;
    double x2=0.1;
    
    CrossSection xs;
    xs.SetMH(125);
    xs.SetMuf(62.5);
    xs.SetMur(62.5);
    xs.SetE(13000);
    xs.SetmZ(91.1876);
    xs.SetAlphamZ(0.118);
    xs.Setmt(162.7);
    
    //Wilson Coefficient Modes: 0== Wilson Coef =1 ; 1== MSBar ; 2 == Onshel Scheme
    xs.SetWilsonCoefficientMode(1);
    xs.Initiate();
    
    //vector<vector<vector<double> > >  CrossSection::Evaluate(double x1,double x2)
    //Returns a std::vector [4][6][4]
    //First Index: Limit: {regular, x2 singular, x1 singular, both singular}
    //Second index: Initial state {gg,qg,gq,qqbar,qq,q Q2}
    //Third index: Order in as: {LO,NLO,NNLO,N3LO}
    vector<vector<vector<double> > >  result = xs.Evaluate(x1,x2);
    
    
    vector<string> chans={"g g","q g","g q","q qbar","q q","q Q2"};
    cout<<"Evaluating for point x1="<<x1<<" x2="<<x2<<endl;
    for(int i=0;i<result[0].size();++i)
        for(int j=0;j<result[0][i].size();++j)
            for(int k=0;k<result.size();++k)
                if(result[k][i][j]==0)
                    continue;
                else
                    cout<<"xs for initial state "<<chans[i]<<" at order "<<j<<" for limit "<<k<<" is "<<result[k][i][j]<<" pb/x1/x2."<<endl;
    
    return 0;
}
