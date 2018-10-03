
#ifndef Histogram_h
#define Histogram_h


#include "../includes/GlobalDefs.h"
#include "../includes/Event.h"


class Histogram{
private:
public:
    
    int order;
    int channel;
    string name;
    int numbins;
    double totpoints;
    vector<double> BinBounds;
    vector<vector<double> > integrals;
    vector<vector<double> > variances;
    vector<double> error;
    vector<double> content;
    vector<double> chisq;
    
    Histogram()
    {
        totpoints=0;
    };
    void SetUpHistogram(string nomen,int bins,double rangemin,double rangemax);
    void AddData(vector<double> weights,vector<int> bins,int numpoints);
    string Print();
    
};


class Histogramer{
private:
public:
    Histogram InclusiveXS_LO,InclusiveXS_NLO,InclusiveXS_NNLO,InclusiveXS_N3LO;
    Histogram Rapidity_LO,Rapidity_NLO,Rapidity_NNLO,Rapidity_N3LO;
    vector<Histogram> ChannelHistograms;
    
    void SetUpHistogram(string nomen,int bins,double rangemin,double rangemax);
    
    Histogramer()
    {
        InclusiveXS_LO.SetUpHistogram("InclusiveXSLO",1,0,100);
        InclusiveXS_NLO.SetUpHistogram("InclusiveXSNLO",1,0,100);
        InclusiveXS_NNLO.SetUpHistogram("InclusiveXSNNLO",1,0,100);
        InclusiveXS_N3LO.SetUpHistogram("InclusiveXSN3LO",1,0,100);
        
        Rapidity_LO.SetUpHistogram("RapidityLO",90,-4.5,4.5);
        Rapidity_NLO.SetUpHistogram("RapidityNLO",90,-4.5,4.5);
        Rapidity_NNLO.SetUpHistogram("RapidityNNLO",90,-4.5,4.5);
        Rapidity_N3LO.SetUpHistogram("RapidityN3LO",90,-4.5,4.5);
        
        vector<string> partons={"gg","qg","gq","qqbar","qq","qQ2"};
        vector<string> order={"LO","NLO","NNLO","N3LO"};
        ChannelHistograms.clear();
        stringstream ss;
        for(int o=0;o<4;o++)
        {
            for(int p=0;p<partons.size();++p)
            {
                if(o==0&&p!=0)
                    continue;
                if(o==1&&p>=4)
                    continue;
                ss.str("");
                ss<<"Rapidity"<<order[o]<<partons[p];
                Histogram newhist;
                newhist.order=o;
                newhist.channel=p;
                newhist.SetUpHistogram(ss.str(),90,-4.5,4.5);
                ChannelHistograms.push_back(newhist);
            }
        }
    };
    
    void AddEvents(vector<MCEvent> Events,int numpoints);
    void Export(string file);
    
};

#endif
