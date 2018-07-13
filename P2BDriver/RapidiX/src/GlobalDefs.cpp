#include "../includes/GlobalDefs.h"


double Pi=3.1415926535897932;

//zb expansion coefficients. 
int delcoefm2=1;
int delcoefm1=1;
int delcoef0=1;
int delcoef1=1;
int delcoef2=1;
int delcoef3=1;
int delcoef4=1;
int delcoef5=1;
int delcoef6=1;

//stupid list function.
vector<int> lst(int a1,int a2,int a3)
{
    vector<int>loc(3,0);
    loc[0]=a1;
    loc[1]=a2;
    loc[2]=a3;
    return loc;
}

//Add two vectors.
vector<double> Add(const vector<double> & a,const vector<double> & b)
{
    if(a.size()!=b.size())
    {
        cout<<"Trying to add to vectors of unequal length!"<<endl;
        exit(0);
    }

    vector<double> res(a.size(),0);
    for(int i=0;i<a.size();++i)
        res[i]=a[i]+b[i];
    
    return res;
}


//Product of two power series given in the form of two vectors (a0+ep a1+ep^2 a2+...)* (b0+ep b1+ep^2 b2+...)
vector<double> Multiply(const vector<double> & a,const vector<double> & b)
{
    vector<double> res;
    double loc=0;
    double size=a.size();
    if(a.size()>b.size())
        size=b.size();
    
    for(int i=0;i<a.size();++i)
    {
        loc=0;
        for(int j=0;j<=i;j++)
        {
            loc+=a[j]*b[i-j];
        }
        res.push_back(loc);
    }
    return res;
}

//Replace string of characters in a string
void str_replace(string rep, string wit, string & in) {
    int pos=0;
    if(rep.compare(wit)==0)
    return;
    while (true) {
        pos = (int)in.find(rep);
        if (pos == -1) {
            break;
        } else {
            in.erase(pos, rep.length());
            in.insert(pos, wit);
        }
    }
}
