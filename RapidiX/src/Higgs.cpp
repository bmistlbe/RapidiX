#include "../includes/Higgs.h"

void Higgs::IntegrateCrossSection()
{
    
    //PDF stuff
    Lumi.pdf->InitiatePDF(PDFSet,PDFMember);
    Lumi.pdf->SetMZ(mZ);
    Lumi.pdf->SetMT(mt);
    Lumi.pdf->SetMuf(muf);
    //Lumi.pdf->CreateGrid(muf);
    ar=Lumi.pdf->GetAlpha(mur)/Pi;
    
    //Parameters
    xs.Lfr=2*log(muf/mur);
    xs.L=2*log(mh/muf);
    xs.ar=ar;
    xs.tau=mh*mh/E/E;
    xs.Q=muf;
    xs.MCPrecision=MCPrecision;
    xs.MCVerbose=MCVerbose;
    xs.pref=ar*ar*Pi*Pi*Born;
    
    //Wilson Coefficient
    double topmass=mt;
    if(WCMode==1)
        topmass=Lumi.pdf->GetMT(mur);
    xs.WC=WilsonCoeff(topmass,mur,WCMode);
    
    
    cout<<"Integrate!"<<endl;
    xs.Integrate();
    integrated=true;
    
    vector<vector<double> > result=xs.xs;
    vector<vector<double> > error=xs.error;
    
    
    
    vector<string> chans={"g g","q g","g q","q qbar","q q","q Q2"};
    cout<<"The inclusive cross section integral yields: "<<endl;
    for(int i=0;i<result.size();i++)
        for(int j=0;j<result[i].size();j++)
            cout<<"channel "<<chans[i]<<" order "<<j<<" ="<<result[i][j]<<" +- "<<error[i][j]<<" +- "<<fabs(error[i][j]/result[i][j])*100<<" %"<<endl;
    
    return;
}



void Higgs::IntegrateDistributions()
{
    
    //PDF stuff
    Lumi.pdf->InitiatePDF(PDFSet,PDFMember);
    Lumi.pdf->SetMZ(mZ);
    Lumi.pdf->SetMT(mt);
    Lumi.pdf->SetMuf(muf);
    //Lumi.pdf->CreateGrid(muf);
    ar=Lumi.pdf->GetAlpha(mur)/Pi;
    
    //Parameters
    xs.Lfr=2*log(muf/mur);
    xs.L=2*log(mh/muf);
    xs.ar=ar;
    xs.tau=mh*mh/E/E;
    xs.Q=muf;
    xs.MCPrecision=MCPrecision;
    xs.MCVerbose=MCVerbose;
    xs.pref=ar*ar*Pi*Pi*Born;
    
    //Wilson Coefficient
    double topmass=mt;
    if(WCMode==1)
        topmass=Lumi.pdf->GetMT(mur);
    xs.WC=WilsonCoeff(topmass,mur,WCMode);
    
    
    cout<<"Integrate!"<<endl;
    xs.ParallelIntegrate();
    return;
}

