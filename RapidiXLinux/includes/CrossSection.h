

#ifndef CrossSection_h
#define CrossSection_h



#include "GlobalDefs.h"
#include "PDF.h"
#include "Histogram.h"
#include "Luminosity.h"
#include "HPLs.h"
#include "../Gs/Gs.h"
#include "Wilson.h"
#include "Vegas.h"
#include "Grider.h"
#include "Inclusive.h"
#include "../FalkoRegularNNLO/nnlo_sub.hpp"

vector<double> EvaluateNNLORegular(double x1,double x2);

double SG(int a,double z);

extern int N3LOExpansion;
class CrossSection{
private:
public:
    
    double xb,zb;
    double x1,x2;
    double Lmx11, Lmx12, Lmx13, Lmx14, Lmx15, Lmx21, Lmx22, Lmx23, Lmx24, Lmx25, Lx11, Lx12, Lx13, Lx14, Lx15, Lx21, Lx22, Lx23, Lx24, Lx25;
    double x110,x111,x112,x113,x114,x115,x116,x117,x118,x119,x120,x121,x122,x123,x124,x125,x126,x127, x12, x13, x14, x15, x16, x17, x18, x19, x210, x22, x23, x24, x25, x26, x27, x28, x29 ,x211,x212,x213,x214,x215,x216,x217,x218,x219,x220,x221,x222,x223,x224,x225,x226,x227;
    double GNNLO1, GNNLO2, GNNLO3, GNNLO4, GNNLO5, GNNLO6, GNNLO7, GNNLO8, GNNLO9, GNNLO10, GNNLO11, GNNLO12, GNNLO13, GNNLO14, GNNLO15, GNNLO16, GNNLO17, GNNLO18, GNNLO19, GNNLO20, GNNLO21, GNNLO22, GNNLO23, GNNLO24, GNNLO25, GNNLO26, GNNLO27, GNNLO28, GNNLO29, GNNLO30, GNNLO31, GNNLO32, GNNLO33, GNNLO34, GNNLO35, GNNLO36, GNNLO37, GNNLO38, GNNLO39, GNNLO40, GNNLO41, GNNLO42, GNNLO43, GNNLO44, GNNLO45, GNNLO46, GNNLO47, GNNLO48, GNNLO49;
    double LogNNLO1, LogNNLO2, LogNNLO3, LogNNLO4, LogNNLO5, LogNNLO6, LogNNLO7, LogNNLO8;
    double N3LOTwoVarG1,N3LOTwoVarG2,N3LOTwoVarG3,N3LOTwoVarG4,N3LOTwoVarG5;
    double N3LOG1,N3LOG2,N3LOG3,N3LOG4,N3LOG5,N3LOG6,N3LOG7,N3LOG8,N3LOG9,N3LOG10,N3LOG11,N3LOG12,N3LOG13,N3LOG14,N3LOG15,N3LOG16,N3LOG17,N3LOG18,N3LOG19,N3LOG20,N3LOG21,N3LOG22,N3LOG23,N3LOG24,N3LOG25,N3LOG26,N3LOG27,N3LOG28,N3LOG29,N3LOG30,N3LOG31,N3LOG32,N3LOG33,N3LOG34,N3LOG35,N3LOG36,N3LOG37,N3LOG38,N3LOG39,N3LOG40,N3LOG41,N3LOG42,N3LOG43,N3LOG44,N3LOG45,N3LOG46,N3LOG47,N3LOG48,N3LOG49,N3LOG50,N3LOG51,N3LOG52,N3LOG53,N3LOG54,N3LOG55,N3LOG56,N3LOG57,N3LOG58,N3LOG59,N3LOG60,N3LOG61,N3LOG62,N3LOG63,N3LOG64,N3LOG65,N3LOG66,N3LOG67,N3LOG68,N3LOG69,N3LOG70,N3LOG71,N3LOG72,N3LOG73,N3LOG74,N3LOG75,N3LOG76,N3LOG77,N3LOG78,N3LOG79,N3LOG80,N3LOG81,N3LOG82,N3LOG83,N3LOG84,N3LOG85,N3LOG86,N3LOG87,N3LOG88,N3LOG89,N3LOG90,N3LOG91,N3LOG92,N3LOG93,N3LOG94,N3LOG95,N3LOG96,N3LOG97,N3LOG98,N3LOG99,N3LOG100,N3LOG101,N3LOG102,N3LOG103,N3LOG104,N3LOG105,N3LOG106,N3LOG107,N3LOG108,N3LOG109,N3LOG110,N3LOG111,N3LOG112,N3LOG113,N3LOG114,N3LOG115,N3LOG116,N3LOG117,N3LOG118,N3LOG119,N3LOG120,N3LOG121,N3LOG122,N3LOG123,N3LOG124,N3LOG125,N3LOG126,N3LOG127,N3LOG128,N3LOG129,N3LOG130,N3LOG131,N3LOG132,N3LOG133,N3LOG134,N3LOG135,N3LOG136,N3LOG137,N3LOG138,N3LOG139,N3LOG140,N3LOG141,N3LOG142,N3LOG143,N3LOG144,N3LOG145,N3LOG146,N3LOG147,N3LOG148,N3LOG149,N3LOG150,N3LOG151,N3LOG152,N3LOG153,N3LOG154,N3LOG155,N3LOG156,N3LOG157,N3LOG158,N3LOG159,N3LOG160,N3LOG161,N3LOG162,N3LOG163,N3LOG164,N3LOG165,N3LOG166,N3LOG167,N3LOG168,N3LOG169,N3LOG170,N3LOG171,N3LOG172,N3LOG173,N3LOG174,N3LOG175,N3LOG176,N3LOG177,N3LOG178,N3LOG179,N3LOG180,N3LOG181,N3LOG182,N3LOG183,N3LOG184,N3LOG185,N3LOG186,N3LOG187,N3LOG188,N3LOG189,N3LOG190,N3LOG191,N3LOG192,N3LOG193,N3LOG194,N3LOG195,N3LOG196,N3LOG197,N3LOG198,N3LOG199,N3LOG200,N3LOG201,N3LOG202,N3LOG203,N3LOG204,N3LOG205,N3LOG206,N3LOG207,N3LOG208,N3LOG209,N3LOG210,N3LOG211,N3LOG212,N3LOG213,N3LOG214,N3LOG215,N3LOG216,N3LOG217,N3LOG218,N3LOG219,N3LOG220,N3LOG221,N3LOG222,N3LOG223,N3LOG224,N3LOG225,N3LOG226,N3LOG227,N3LOG228,N3LOG229,N3LOG230,N3LOG231,N3LOG232,N3LOG233,N3LOG234,N3LOG235,N3LOG236,N3LOG237,N3LOG238,N3LOG239,N3LOG240,N3LOG241,N3LOG242,N3LOG243,N3LOG244,N3LOG245,N3LOG246,N3LOG247,N3LOG248,N3LOG249,N3LOG250,N3LOG251,N3LOG252,N3LOG253,N3LOG254,N3LOG255,N3LOG256,N3LOG257,N3LOG258,N3LOG259,N3LOG260,N3LOG261,N3LOG262,N3LOG263,N3LOG264,N3LOG265,N3LOG266,N3LOG267,N3LOG268,N3LOG269,N3LOG270,N3LOG271,N3LOG272,N3LOG273,N3LOG274,N3LOG275,N3LOG276,N3LOG277,N3LOG278,N3LOG279,N3LOG280,N3LOG281,N3LOG282,N3LOG283,N3LOG284,N3LOG285,N3LOG286,N3LOG287,N3LOG288,N3LOG289,N3LOG290,N3LOG291,N3LOG292,N3LOG293,N3LOG294,N3LOG295,N3LOG296,N3LOG297,N3LOG298,N3LOG299,N3LOG300,N3LOG301,N3LOG302,N3LOG303,N3LOG304,N3LOG305,N3LOG306,N3LOG307,N3LOG308,N3LOG309,N3LOG310,N3LOG311,N3LOG312,N3LOG313,N3LOG314,N3LOG315,N3LOG316,N3LOG317,N3LOG318,N3LOG319,N3LOG320,N3LOG321,N3LOG322,N3LOG323,N3LOG324,N3LOG325,N3LOG326,N3LOG327,N3LOG328,N3LOG329,N3LOG330;
    
    
    double xsregRRgg,xsregRRqg,xsregRRgq,xsregRRqqbar;
    
    vector<vector<vector<Grider> > > NNLOGrider;
    
    double L;
    double ar;
    double tau;
    double Q;
    double Lfr;
    double pref;
    vector<double> WC;
    Luminosity Lumi;
    double Y;
    
    vector<vector<double> > xs,error;
    vector<vector<vector<double> > > zero,values;
    vector<vector<int> > pos,pos2;
    
    double XSCoef[4][6][4][4];
    
    double MCPrecision;
    int MCVerbose;
    int NrThreads;
    
    void SetCoefs();
    void SetNNLO();
    void SetN3LO();
    void SetSpecialGs();
    
    string ResultFile;
    Histogramer Histopheles;
    int RandomSeedOffset;
    void ReadGrids();
    
    
    InclusiveCoefficients IncCoefs;
    
    CrossSection()
    {
        Y=110;
        NNLOGrider=vector<vector<vector<Grider> > > (6,vector<vector<Grider> >(3,vector<Grider>(21)));
        ReadGrids();
        
        NrThreads=8;
        ResultFile="Output.txt";
        RandomSeedOffset=0;
        MCPrecision=1e-3;
        Lfr=0;
        L=0;
        ar=0;
        tau=0;
        Q=0;
        WC=vector<double> (4,0);
        WC[0]=1;
        pref=1;
        
        //Order , Initial Stat , Log Power, Distribution
        for(int i=0;i<4;i++)
            for(int j=0;j<6;j++)
                for(int k=0;k<4;k++)
                    for(int l=0;l<4;l++)
                        XSCoef[i][j][k][l]=0;

        
        //Order , Initial Stat , Log Power
        zero=vector<vector<vector<double> > >  (4,vector<vector<double> > (6,vector<double>(4,0)));
        values=zero;
        
        //order , initial stat , Log Power
        pos.push_back(lst(0,0,0));
        //NLO
        pos.push_back(lst(1,0,0));
        pos.push_back(lst(1,0,1));
        pos.push_back(lst(1,1,0));
        pos.push_back(lst(1,1,1));
        pos.push_back(lst(1,2,0));
        pos.push_back(lst(1,2,1));
        pos.push_back(lst(1,3,0));
        pos.push_back(lst(1,3,1));
        //NNLO - g g
        pos.push_back(lst(2,0,0));
        pos.push_back(lst(2,0,1));
        pos.push_back(lst(2,0,2));
        //NNLO - g q
        pos.push_back(lst(2,1,0));
        pos.push_back(lst(2,1,1));
        pos.push_back(lst(2,1,2));
        //NNLO - g q
        pos.push_back(lst(2,2,0));
        pos.push_back(lst(2,2,1));
        pos.push_back(lst(2,2,2));
        //NNLO - q qbar
        pos.push_back(lst(2,3,0));
        pos.push_back(lst(2,3,1));
        pos.push_back(lst(2,3,2));
        //NNLO - q q
        pos.push_back(lst(2,4,0));
        pos.push_back(lst(2,4,1));
        pos.push_back(lst(2,4,2));
        //NNLO - q Q2
        pos.push_back(lst(2,5,0));
        pos.push_back(lst(2,5,1));
        pos.push_back(lst(2,5,2));
        //*/
        //N3LO - g g
        pos.push_back(lst(3,0,0));
        pos.push_back(lst(3,0,1));
        pos.push_back(lst(3,0,2));
        pos.push_back(lst(3,0,3));
        //N3LO - q g
        pos.push_back(lst(3,1,0));
        pos.push_back(lst(3,1,1));
        pos.push_back(lst(3,1,2));
        pos.push_back(lst(3,1,3));
        //N3LO - g q
        pos.push_back(lst(3,2,0));
        pos.push_back(lst(3,2,1));
        pos.push_back(lst(3,2,2));
        pos.push_back(lst(3,2,3));
        //N3LO - q qbar
        pos.push_back(lst(3,3,0));
        pos.push_back(lst(3,3,1));
        pos.push_back(lst(3,3,2));
        pos.push_back(lst(3,3,3));
        //N3LO - q q
        pos.push_back(lst(3,4,0));
        pos.push_back(lst(3,4,1));
        pos.push_back(lst(3,4,2));
        pos.push_back(lst(3,4,3));
        //N3LO - q Q2
        pos.push_back(lst(3,5,0));
        pos.push_back(lst(3,5,1));
        pos.push_back(lst(3,5,2));
        pos.push_back(lst(3,5,3));
        //*/
        
        
        pos2.push_back(lst(0,0,0));
        pos2.push_back(lst(1,0,0));
        pos2.push_back(lst(1,1,0));
        pos2.push_back(lst(1,2,0));
        pos2.push_back(lst(1,3,0));
        pos2.push_back(lst(2,0,0));
        pos2.push_back(lst(2,1,0));
        pos2.push_back(lst(2,2,0));
        pos2.push_back(lst(2,3,0));
        pos2.push_back(lst(2,4,0));
        pos2.push_back(lst(2,5,0));
        pos2.push_back(lst(3,0,0));
        pos2.push_back(lst(3,1,0));
        pos2.push_back(lst(3,2,0));
        pos2.push_back(lst(3,3,0));
        pos2.push_back(lst(3,4,0));
        pos2.push_back(lst(3,5,0));


    };
    
    void Integrate();
    void IntegrateCuba();
    void ParallelIntegrate();
    void ComputeDummyVariables();
    double ComputeTotalXS(const vector<vector<double > > & vec);
    vector<vector<double> >  Evaluate(double xx1,double xx2,double bound1,double bound2,double Jac);
    
    
    //NNLORegular Subtraction + Addition
    void AddSubtractRegularNNLO();
    
};

int Integrand(const double * xx,double * ff,const void * userdata,double * ExportData);
int ParallelIntegrand(const double * xx,double * ff,const void * userdata,double * ExportData);
static int CubaIntegrand(const int *ndim, const double xx[], const int *ncomp, double ff[], void *userdata);

#endif
