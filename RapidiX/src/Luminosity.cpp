#include "../includes/Luminosity.h"


double Luminosity::GetPDFValue(int parton,int side,bool limit)
{
    if(limit)
        return pdfvals[side][0];
    else
        return pdfvals[side][6+parton];
}

void Luminosity::StorePDFValues(double x1,double x2,double lb1,double lb2)
{
    pdfvals[0][0]=pdf->GetValue(lb1,0);
    pdfvals[1][0]=pdf->GetValue(lb2,0);
    
    for(int i=-5;i<=5;++i)
    {
        if(x1>lb1){
            pdfvals[0][6+i]=pdf->GetValue(lb1/x1,i);}
        else{
            pdfvals[0][6+i]=0;}
        
        if(x2>lb2){
            pdfvals[1][6+i]=pdf->GetValue(lb2/x2,i);}
        else{
            pdfvals[1][6+i]=0;}
    }
    return;
}

void Luminosity::SetLuminosity(double x1,double x2,double lb1,double lb2)
{
    StorePDFValues(x1,x2,lb1,lb2);
    Lgg00=Lgg(true,true);
    Lgg01=Lgg(true,false);
    Lgg10=Lgg(false,true);
    Lqg10=Lqg(true);
    Lgq01=Lgq(true);
    
    L[0]=Lgg(false,false);
    L[1]=Lqg(false);
    L[2]=Lgq(false);
    L[3]=Lqqbar();
    L[4]=Lqq();
    L[5]=LqQ2();
    
    /*L[0]=1;
    L[1]=1;
    L[2]=1;
    L[3]=1;
    L[4]=1;
    L[5]=1;
    Lgg00=1;
    Lgg01=1;
    Lgg10=1;
    Lqg10=1;
    Lgq01=1;
     //*/
    return;
}

double Luminosity::Lumi(int parton1,int parton2,bool lim1, bool lim2)
{
    return GetPDFValue(parton1,0,lim1)*GetPDFValue(parton2,1,lim2);
}


double Luminosity::Lgg(bool lim1,bool lim2)
{
    return Lumi(0,0,lim1,lim2);
}

double Luminosity::Lqg(bool lim2)
{
    double lumi=0;
    for(int i=-5;i<=5;i++)
    {
        if(i==0)
            continue;
        lumi+=Lumi(i,0,false,lim2);
    }
    return lumi;
}

double Luminosity::Lgq(bool lim1)
{
    double lumi=0;
    for(int i=-5;i<=5;i++)
    {
        if(i==0)
            continue;
        lumi+=Lumi(0,i,lim1,false);
    }
    return lumi;
}

double Luminosity::Lqqbar()
{
    double lumi=0;
    for(int i=1;i<=5;i++)
    {
        if(i==0)
            continue;
        lumi+=Lumi(-i,i,false,false)+Lumi(i,-i,false,false);
    }
    return lumi;
}

double Luminosity::Lqq()
{
    double lumi=0;
    for(int i=-5;i<=5;i++)
    {
        if(i==0)
            continue;
        lumi+=Lumi(i,i,false,false);
    }
    return lumi;
}

double Luminosity::LqQ2()
{
    double lumi=0;
    for(int i=-5;i<=5;i++)
    {
        for(int j=-5;j<=5;j++)
        {
            if(i==-j)
                continue;
            if(i==j)
                continue;
            if(i==0||j==0)
                continue;
            lumi+=Lumi(i,j,false,false);
        }
    }
    return lumi;
}
