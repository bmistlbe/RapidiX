#include "../includes/Event.h"


void MCEvent::GetRapidityBins(vector<int> & bin, vector<double> & xs, int order)
{
    bin.clear();
    xs.clear();
    int locbin;
    //cout<<"Binning MC Event for Rapidity"<<endl;
    for(int i=0;i<Events.size();++i)
    {
        locbin=abs((4.5+Events[i].Y)/0.1);
        //cout<<"Rapidity: "<<Events[i].Y<<" locbin: "<<locbin<<" order "<<order<<" xs: "<<Events[i].xs[0]<<" "<<Events[i].xs[1]<<" "<<Events[i].xs[2]<<" "<<Events[i].xs[3]<<endl;
        for(int j=0;j<bin.size();++j)
            if(bin[j]==locbin)
            {
                for(int k=0;k<6;++k)
                    for(int l=0;l<=order;++l)
                        xs[j]+=Events[i].xs[k][l];
                locbin=110;
                break;
            }
        if(locbin==110)
            continue;
        bin.push_back(locbin);
        xs.push_back(0);
        for(int k=0;k<6;++k)
            for(int l=0;l<=order;++l)
                xs[xs.size()-1]+=Events[i].xs[k][l];
    }
    return;
}

void MCEvent::GetRapidityBins(vector<int> & bin, vector<double> & xs, int order,int channel)
{
    bin.clear();
    xs.clear();
    int locbin;
    for(int i=0;i<Events.size();++i)
    {
        locbin=abs((4.5+Events[i].Y)/0.1);
        for(int j=0;j<bin.size();++j)
            if(bin[j]==locbin)
            {
                xs[j]+=Events[i].xs[channel][order];
                locbin=110;
                break;
            }
        if(locbin==110)
            continue;
        bin.push_back(locbin);
        xs.push_back(Events[i].xs[channel][order]);
    }
    return;
}

vector<MCEvent> CreateEvents(const vector<double * > & Data)
{
    vector<vector<int> > pos2;
    
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

    
    vector<MCEvent> res;
    bool check=false;
    for(int i=0;i<Data.size();++i)
    {
        MCEvent mcev;
        vector<vector<double> > rrr(6,vector<double>(4,0));
        for(int j=0;j<pos2.size();++j)
            rrr[pos2[j][1]][pos2[j][0]]=Data[i][j+2];
        Event ev(Data[i][0],Data[i][1],rrr);
        mcev.Events.push_back(ev);
        res.push_back(mcev);
    }
    return res;
}




void MCEvent::GetInclusiveXS(vector<int> & bin, vector<double> & xs, int order)
{
    bin.clear();
    xs.clear();
    double loc=0;
    for(int i=0;i<Events.size();++i)
        for(int j=0;j<6;++j)
            for(int k=0;k<=order;++k)
                loc+=Events[i].xs[j][k];
    bin.push_back(0);
    xs.push_back(loc);
    return;
}
