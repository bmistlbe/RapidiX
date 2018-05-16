
#ifndef Bin_h
#define Bin_h



#include "../includes/GlobalDefs.h"




class Event{
private:
public:
    
    double weight;
    double xs[6][4];
    double Y;
    
    Event()
    {
        
    };
    Event(double w,double YY, const vector<vector<double> > & res)
    {
        weight=w;
        Y=YY;
        for(int i=0;i<res.size();++i)
            for(int j=0;j<res[i].size();++j)
                xs[i][j]=res[i][j]*weight;
    }
    
};

class MCEvent{
private:
public:
    
    vector<Event> Events;
    MCEvent()
    {
    }
    void GetRapidityBins(vector<int> & bin, vector<double> & xs, int order);
    void GetRapidityBins(vector<int> & bin, vector<double> & xs, int order,int channel);
    void GetInclusiveXS(vector<int> & bin, vector<double> & xs, int order);
};

vector<MCEvent> CreateEvents(const vector<double * > & Data);
    
#endif



