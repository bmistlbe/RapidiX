#include "../includes/Inclusive.h"



//Order , Initial Stat , Log Power
void InclusiveCoefficients::ComputeDummyVariables(double z)
{
    sqrtz=sqrt(z);
    int i=0,j,k;

    for(i=0;i<pos.size();++i)
        values[pos[i][0]][pos[i][1]][pos[i][2]]=0;

    if(z>=0.75)
    {
        vector<double> zbPows(50,0);
        vector<double> zbLogPows(6,0);
        
#pragma omp parallel for private(i) schedule(dynamic)
        for(i=0;i<50;i++)
            zbPows[i]=pow(1.0-z,i);
        zbLogPows[0]=1;
        zbLogPows[1]=log(1-z);
        zbLogPows[2]=pow(log(1-z),2);
        zbLogPows[3]=pow(log(1-z),3);
        zbLogPows[4]=pow(log(1-z),4);
        zbLogPows[5]=pow(log(1-z),5);
        SetZb(values,zbPows,zbLogPows);
    }
    else if (z<0.75&&z>=0.0769231)
    {
        //cout<<"mid"<<endl;
        vector<double> wPows(201,0);
        
        
#pragma omp parallel for private(i) schedule(dynamic)
        for(i=0;i<wPows.size();i++)
            wPows[i]=pow(0.5-z,i);
        SetW(values,wPows);
    }
    else
    {
        //cout<<"low"<<endl;
        vector<double> zPows(101,0);
        vector<double> zLogPows(6,0);
        
#pragma omp parallel for private(i) schedule(dynamic)
        for(i=0;i<zPows.size();i++)
            zPows[i]=pow(z,i-1);
        zLogPows[0]=1;
        zLogPows[1]=log(z);
        zLogPows[2]=pow(log(z),2);
        zLogPows[3]=pow(log(z),3);
        zLogPows[4]=pow(log(z),4);
        zLogPows[5]=pow(log(z),5);
        SetZ(values,zPows,zLogPows);
    }
     //*/

    return;
}


void InclusiveCoefficients::SetZb(vector<vector<vector<double> > > & values,const vector<double> & zbPows,const vector<double> & zbLogPows)
{
    
    //Order , Initial Stat , Log Power, x Power, x Log Power
    int p;
#pragma omp parallel for private(p) schedule(dynamic)
    for(p=0;p<pos.size();++p)
    {
        for(int i=0;i<zbPows.size();++i)
        {
            for(int j=0;j<=2*pos[p][0]-1;++j)
            {
                if(ZbExp[pos[p][0]][pos[p][1]][pos[p][2]][i][j]==0)
                    continue;
                values[pos[p][0]][pos[p][1]][pos[p][2]]+=ZbExp[pos[p][0]][pos[p][1]][pos[p][2]][i][j]*zbPows[i]*zbLogPows[j];
            }
        }
    }
    return;
}


void InclusiveCoefficients::SetZ(vector<vector<vector<double> > > & values,const vector<double> & zPows,const vector<double> & zLogPows)
{
    
    //Order , Initial Stat , Log Power, x Power, x Log Power
    int p;
#pragma omp parallel for private(p) schedule(dynamic)
    for(p=0;p<pos.size();++p)
    {
        for(int i=0;i<zPows.size();++i)
        {
            for(int j=0;j<=2*pos[p][0]-1;++j)
            {
                if(ZExp[pos[p][0]][pos[p][1]][pos[p][2]][i][j]==0)
                    continue;
                values[pos[p][0]][pos[p][1]][pos[p][2]]+=ZExp[pos[p][0]][pos[p][1]][pos[p][2]][i][j]*zPows[i]*zLogPows[j];
            }
        }
    }
    return;
}



void InclusiveCoefficients::SetW(vector<vector<vector<double> > > & values,const vector<double> & wPows)
{
    
    //Order , Initial Stat , Log Power, x Power, x Log Power
    int p;
#pragma omp parallel for private(p) schedule(dynamic)
    for(p=0;p<pos.size();++p)
    {
        for(int i=0;i<wPows.size();++i)
        {
            for(int j=0;j<=2*pos[p][0]-1;++j)
            {
                if(WExp[pos[p][0]][pos[p][1]][pos[p][2]][i][j]==0)
                    continue;
                values[pos[p][0]][pos[p][1]][pos[p][2]]+=WExp[pos[p][0]][pos[p][1]][pos[p][2]][i][j]*wPows[i];
            }
        }
    }
    return;
}



//*/
