
#ifndef Vegas_h
#define Vegas_h


#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <iterator>
#include <sys/types.h>
#include <sys/stat.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <random>

extern std::random_device rd;
extern std::mt19937 mt;
extern std::uniform_real_distribution<double> myrand;
//#include "OMP.h"


using namespace std;


class VegasIntegrator{
private:
public:
    double ** grid_lowerbounds;
    double ** grid_upperbounds;
    double ** GridIntegral;
    double ** Distribution;
    double * GridIntegralSum;
    
    
    int randseed;
    int gridsize;
    int dimension;
    int components;
    
    double precision;
    double absprecision;
    int batchsize;
    int startsize;
    int maxpoints;
    
    int verbose;
    int totpoints;
    int mineval;
    
    bool adapt;
    
    bool GridExport;
    
    string ExportFile;
    int ExportComponents;
    vector<double *> StoredExportData;
    
    vector<double> StoredIntegrals;
    vector<double> StoredErrors;
    
    VegasIntegrator(){
        randseed=0;
        grid_lowerbounds=0;
        grid_upperbounds=0;
        GridIntegral=0;
        Distribution=0;
        GridIntegralSum=0;
        
        srand (time(NULL));
        
        adapt=true;
        mineval=10;
        verbose=0;
        dimension=1;
        components=1;
        totpoints=0;
        
        precision=1e-3;
        absprecision=0;
        maxpoints=1e9;
        startsize=5000;
        batchsize=1000;
        GridExport=false;
        gridsize=100;
        
        ExportComponents=0;
        ExportFile="dump.txt";
        
        
    };

    
    
    //Initiate Flat Distributions for Integration
    void InitiateIntegrationGrids();
    
    //Get the bin number of the grid with gridnr to which the point belongs
    int GetBin(const double & point,const int & gridnr);
    
    //Compute a random point according to the grid with gridnr from a flat random number why and also store the bin of the grid in bin.
    double InverseGrid(const int & gridnr,const double & y,int & bin);
    
    //Generate Random Numbers according to Grids
    void GetPoints(const int & numpoints,double ** points, int ** bins);
    void GetSinglePoint(double * point,int * bins);
    
    //Adjust the importance sampling distributions according to the previous integrations.
    void GridAdapt();
    
    //Sample the Integrand and compute Integral and Variance of one iteration
    void PerformSampling(int (*f)(const double * xx,double * ff,const void * userdata,double * ExportData),const int & numpoints,double * results,double * variances,const void * userdata);
    
    //Integrate a Function
    int Integrate(int (*f)(const double * xx,double * ff,const void * userdata,double * ExportData),double * & integral,double * & error,double * &chisq,const void *userdata);
    
    //Integrate a Function with existing Grids for a fixed number of points batchsize
    int ContinueIntegrate(int (*f)(const double * xx,double * ff,const void * userdata,double * ExportData),double * & integral,double * & error,double * &chisq,const void *userdata);
    
    //Export The Grids to File
    void ExportGrids(string file);
    
    //Import The Grids from File
    void ImportGrids(string file);
    
    //Export Vegas Components to File
    void SetFileExport(string file,int nrcomps)
    {
        ExportFile=file;
        ExportComponents=nrcomps;
        return;
    }
    void StoreExportData();


};

#endif



