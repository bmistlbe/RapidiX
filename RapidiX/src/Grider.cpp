#include "../includes/Grider.h"



void Grider::ReadGrid(int state,int L1,int L2,int o)
{
    loaded=true;
    grid=vector<vector<double> > (gridsize,vector<double>(gridsize,0));
    if(o!=2)
    {
        cout<<"No grids for order "<<o<<endl;
        return;
    }
    
    vector<double> data;
    string buffer="";
    stringstream ss;
    if(o==2)
        ss<<"XS/NumericalNNLO/Grid_"<<state<<"_"<<L1<<"_"<<L2<<".txt";
    string inputf=ss.str();
    ss.str("");
    
    ifstream input;
    input.open(inputf.c_str());
    if(!input.is_open())
    {
        cout<<"Could not find GridFile! "<<inputf<<endl;
        exit(9);
    }
    
    ss.str("");
    while(!input.eof())
    {
        buffer="";
        input>>buffer;
        ss<<buffer;
    }
    buffer=ss.str();
    ss.str("");
    input.close();
    
    string locstr;
    for(int i=0;i<buffer.size();i++)
    {
        locstr=buffer[i];
        if(locstr.compare("{")==0)
        {
            data.clear();
            ss.str("");
        }
        else if(locstr.compare("}")==0)
        {
            data.push_back(atof(ss.str().c_str()));
            ss.str("");
        }
        else if(locstr.compare(",")==0)
        {
            data.push_back(atof(ss.str().c_str()));
            ss.str("");
        }
        else if(locstr.compare(" ")==0)
            continue;
        else if(locstr.compare("\n")==0)
            continue;
        else
            ss<<locstr;
    }
    for(int i=0;i<gridsize;i++)
        for(int j=0;j<gridsize;++j)
            grid[i][j]=data[gridsize*i+j];
    
    return;
}


double Grider::xVal(int bin)
{
    if(bin<100)
        return (bin)/100.0;
    else
        return 0.99+0.0005*(bin-99);
        
        
}


double Grider::GetValue(double x1, double x2)
{
    if(!loaded)
    {
        cout<<"Grid was not set! "<<endl;
        exit(0);
    }
    x1=1-x1;
    x2=1-x2;
    
    if(x1>=0.99)
    {
        bin1=(x1-0.99)*2*1000+99;
        if(bin1>116)
            bin1=116;
    }
    else
        bin1=100*x1;
    x11=xVal(bin1);
    x12=xVal(bin1+1);
    x13=xVal(bin1+2);
    
    if(x2>=0.99)
    {
        bin2=(x2-0.99)*2*1000+99;
        if(bin2>116)
            bin2=116;
    }
    else
        bin2=100*x2;
    //*/
    
    /*if(x1>0.997)
        bin1=997;
    else
        bin1=1000*x1;
    if(x2>0.997)
        bin2=997;
    else
        bin2=1000*x2;
    //*/
        
    x21=xVal(bin2);
    x22=xVal(bin2+1);
    x23=xVal(bin2+2);
    
//    cout<<"bin1 "<<bin1<<" x1 "<<x1<<" "<<grid[bin1][bin2]<<endl;
//    cout<<"bin2 "<<bin2<<" x2 "<<x2<<" "<<grid[bin1][bin2]<<endl;
    
    //Log Polynomial
    if(bin1!=0&&bin2!=0)
    {
        x1=log(x1);
        x2=log(x2);
        x11=log(x11);
        x12=log(x12);
        x13=log(x13);
        x21=log(x21);
        x22=log(x22);
        x23=log(x23);
    }
    else if(bin1!=0)
    {
        x1=log(x1);
        x11=log(x11);
        x12=log(x12);
        x13=log(x13);
    }
    else if(bin2!=0)
    {
        x2=log(x2);
        x21=log(x21);
        x22=log(x22);
        x23=log(x23);
    }
    //cout<<x11<<" "<<x12<<" "<<x13<<" "<<x21<<" "<<x22<<" "<<x23<<endl;
    //*/
    
    f1=grid[bin1][bin2];
    f2=grid[bin1][bin2+1];
    f3=grid[bin1+1][bin2];
    f4=grid[bin1+1][bin2+1];
    f5=grid[bin1][bin2+2];
    f6=grid[bin1+2][bin2];
    f7=grid[bin1+1][bin2+2];
    f8=grid[bin1+2][bin2+1];
    f9=grid[bin1+2][bin2+2];
    
    //cout<<f1<<" "<<f1<<" "<<f2<<" "<<f3<<" "<<f4<<" "<<f5<<" "<<f6<<" "<<grid[bin1][bin2]<<endl;
    
    double res=(f1*(x1 - x12)*(x1 - x13)*(x2 - x22)*(x2 - x23))/((x11 - x12)*(x11 - x13)*(x21 - x22)*(x21 - x23)) - (f3*(x1 - x11)*(x1 - x13)*(x2 - x22)*(x2 - x23))/((x11 - x12)*(x12 - x13)*(x21 - x22)*(x21 - x23)) - (f6*(x1 - x11)*(x1 - x12)*(x2 - x22)*(x2 - x23))/((x11 - x13)*(-x12 + x13)*(x21 - x22)*(x21 - x23)) - (f2*(x1 - x12)*(x1 - x13)*(x2 - x21)*(x2 - x23))/((x11 - x12)*(x11 - x13)*(x21 - x22)*(x22 - x23)) + (f4*(x1 - x11)*(x1 - x13)*(x2 - x21)*(x2 - x23))/((x11 - x12)*(x12 - x13)*(x21 - x22)*(x22 - x23)) + (f8*(x1 - x11)*(x1 - x12)*(x2 - x21)*(x2 - x23))/((x11 - x13)*(-x12 + x13)*(x21 - x22)*(x22 - x23)) - (f5*(x1 - x12)*(x1 - x13)*(x2 - x21)*(x2 - x22))/((x11 - x12)*(x11 - x13)*(x21 - x23)*(-x22 + x23)) + (f7*(x1 - x11)*(x1 - x13)*(x2 - x21)*(x2 - x22))/((x11 - x12)*(x12 - x13)*(x21 - x23)*(-x22 + x23)) + (f9*(x1 - x11)*(x1 - x12)*(x2 - x21)*(x2 - x22))/((x11 - x13)*(-x12 + x13)*(x21 - x23)*(-x22 + x23));
    //cout<<res<<endl;
    if(isinf(res)||isnan(res))
        return 0;
    return res;
}
