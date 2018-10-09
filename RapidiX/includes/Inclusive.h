

#ifndef Inclusive_h
#define Inclusive_h

#include "../includes/GlobalDefs.h"



class InclusiveCoefficients{
private:
public:
    
    
    
    double ZExp[4][6][4][300][6];
    double ZbExp[4][6][4][300][6];
    double WExp[4][6][4][300][6];
    
    double sqrtz;
    
    void SetDistributionCoefs();
    void SetZCoefs();
    void SetWCoefs();
    void SetZbCoefs();
    vector<vector<int> > pos;
    vector<vector<vector<double> > > zero,values;
    
    void Initiate()
    {
        SetZCoefs();
        SetWCoefs();
        SetZbCoefs();
        return;
    };
    
    InclusiveCoefficients()
    {
        zero=vector<vector<vector<double> > >  (4,vector<vector<double> > (6,vector<double>(4,0)));
        values=vector<vector<vector<double> > >  (4,vector<vector<double> > (6,vector<double>(4,0)));
        
        //Order , Initial Stat , Log Power, x Power, x Log Power
        for(int i=0;i<4;i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<4;k++)
                    for(int l=0;l<300;l++)
                        for(int m=0;m<6;m++)
                        {
                            ZExp[i][j][k][l][m]=0;
                            ZbExp[i][j][k][l][m]=0;
                            WExp[i][j][k][l][m]=0;
                        }

        
        //N3LO - g g
        pos.push_back(lst(3,0,0));
//        pos.push_back(lst(3,0,1));
//        pos.push_back(lst(3,0,2));
//        pos.push_back(lst(3,0,3));
        //N3LO - q g
        pos.push_back(lst(3,1,0));
//        pos.push_back(lst(3,1,1));
//        pos.push_back(lst(3,1,2));
//        pos.push_back(lst(3,1,3));
        //N3LO - g q
        pos.push_back(lst(3,2,0));
//        pos.push_back(lst(3,2,1));
//        pos.push_back(lst(3,2,2));
//        pos.push_back(lst(3,2,3));
        //N3LO - q qbar
        pos.push_back(lst(3,3,0));
//        pos.push_back(lst(3,3,1));
//        pos.push_back(lst(3,3,2));
//        pos.push_back(lst(3,3,3));
        //N3LO - q q
        pos.push_back(lst(3,4,0));
//        pos.push_back(lst(3,4,1));
//        pos.push_back(lst(3,4,2));
//        pos.push_back(lst(3,4,3));
        //N3LO - q Q2
        pos.push_back(lst(3,5,0));
//        pos.push_back(lst(3,5,1));
//        pos.push_back(lst(3,5,2));
//        pos.push_back(lst(3,5,3));
        //*/
        
        Initiate();
        
    };

    
    void SetZb(vector<vector<vector<double> > > & values,const vector<double> & zbPows,const vector<double> & zbLogPows);
    void SetZbN3LO(vector<vector<vector<double> > > & values,const vector<double> & zbPows,const vector<double> & zbLogPows);
    void SetW(vector<vector<vector<double> > > & values,const vector<double> & wPows);
    void SetZ(vector<vector<vector<double> > > & values,const vector<double> & sqrtzPows,const vector<double> & zLogPows);
    
    void ComputeDummyVariables(double z);
    void ComputeCoefficients(double z);

};

#endif
