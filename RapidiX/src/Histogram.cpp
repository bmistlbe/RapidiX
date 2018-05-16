#include "../includes/Histogram.h"


void Histogram::SetUpHistogram(string nomen,int bins,double rangemin,double rangemax)
{
    name=nomen;
    numbins=bins;
    BinBounds.clear();
    for(int i=0;i<bins;i++)
        BinBounds.push_back(i*(rangemax-rangemin)/(double)bins+rangemin);
    error=vector<double> (numbins,0);
    content=vector<double> (numbins,0);
    chisq=vector<double> (numbins,0);
    return;
}

string Histogram::Print()
{
    stringstream ss;
    ss<<name<<"={";
    for(int i=0;i<numbins;i++)
    {
        ss<<"{"<<BinBounds[i]<<","<<content[i]<<","<<error[i]<<","<<chisq[i]<<"}";
        if(i<numbins-1)
            ss<<",";
    }
    ss<<"};";
    return ss.str();
}


void Histogram::AddData(vector<double> weights,vector<int> bins,int numpoints)
{
    vector<double> newdata(numbins,0),newerror(numbins,0);
    for(int i=0;i<weights.size();i++)
    {
        if(bins[i]>=numbins||bins[i]<0)
            continue;
        if(std::isnan(weights[i])||std::isinf(weights[i]))
            continue;
        newdata[bins[i]]+=weights[i]*numpoints;
        newerror[bins[i]]+=weights[i]*weights[i]*numpoints*numpoints;
    }

    totpoints+=numpoints;
    
    
    integrals.push_back(newdata);
    variances.push_back(newerror);
    error=vector<double> (numbins,0);
    content=vector<double> (numbins,0);
    chisq=vector<double> (numbins,0);
    for(int i=0;i<integrals.size();i++)
    {
        for(int j=0;j<integrals[i].size();j++)
        {
            content[j]+=integrals[i][j]/totpoints;
            error[j]+=variances[i][j]/totpoints;
        }
    }
    for(int i=0;i<content.size();i++)
    {
        error[i]=sqrt(fabs(content[i]*content[i]-error[i])/(totpoints-1));
    }
    return;
}


void Histogramer::AddEvents(vector<MCEvent> Events,int numpoints)
{
    
    vector<int> bin;
    vector<double> data;
    vector<int> binloc;
    vector<double> dataloc;
    
    
    
    //**********************        InclusiveXS LO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetInclusiveXS(binloc,dataloc,0);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    InclusiveXS_LO.AddData(data,bin,numpoints);
    
    
    //**********************        InclusiveXS NLO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetInclusiveXS(binloc,dataloc,1);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    InclusiveXS_NLO.AddData(data,bin,numpoints);
    
    //**********************        InclusiveXS NNLO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetInclusiveXS(binloc,dataloc,2);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    InclusiveXS_NNLO.AddData(data,bin,numpoints);
    
    //**********************        InclusiveXS N3LO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetInclusiveXS(binloc,dataloc,3);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    InclusiveXS_N3LO.AddData(data,bin,numpoints);
    
    
    //**********************        Rapidity_LO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetRapidityBins(binloc,dataloc,0);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    Rapidity_LO.AddData(data,bin,numpoints);
    
    //**********************        Rapidity_NLO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetRapidityBins(binloc,dataloc,1);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    Rapidity_NLO.AddData(data,bin,numpoints);
    
    //**********************        Rapidity_NNLO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetRapidityBins(binloc,dataloc,2);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    Rapidity_NNLO.AddData(data,bin,numpoints);
    
    //**********************        Rapidity_N3LO
    bin.clear();
    data.clear();
    for(int i=0;i<Events.size();i++)
    {
        dataloc.clear();
        binloc.clear();
        Events[i].GetRapidityBins(binloc,dataloc,3);
        bin.insert(bin.end(),binloc.begin(),binloc.end());
        data.insert(data.end(),dataloc.begin(),dataloc.end());
    }
    Rapidity_N3LO.AddData(data,bin,numpoints);
    
    
    //**********************        Rapidity for each partonic channel
    for(int j=0;j<ChannelHistograms.size();++j)
    {
        bin.clear();
        data.clear();
        for(int i=0;i<Events.size();i++)
        {
            dataloc.clear();
            binloc.clear();
            Events[i].GetRapidityBins(binloc,dataloc,ChannelHistograms[j].order,ChannelHistograms[j].channel);
            bin.insert(bin.end(),binloc.begin(),binloc.end());
            data.insert(data.end(),dataloc.begin(),dataloc.end());
        }
        ChannelHistograms[j].AddData(data,bin,numpoints);
    }
    //*/
    return;
    
}



void Histogramer::Export(string file)
{
    stringstream ss;
    ss<<"totpoints="<<InclusiveXS_LO.totpoints<<";\n"<<endl<<endl;

    
    ss<<InclusiveXS_LO.Print()<<endl<<endl;
    ss<<InclusiveXS_NLO.Print()<<endl<<endl;
    ss<<InclusiveXS_NNLO.Print()<<endl<<endl;
    ss<<InclusiveXS_N3LO.Print()<<endl<<endl;
    
    ss<<Rapidity_LO.Print()<<endl<<endl;
    ss<<Rapidity_NLO.Print()<<endl<<endl;
    ss<<Rapidity_NNLO.Print()<<endl<<endl;
    ss<<Rapidity_N3LO.Print()<<endl<<endl;
    for(int i=0;i<ChannelHistograms.size();++i)
        ss<<ChannelHistograms[i].Print()<<endl<<endl;
    
    string output=ss.str();
    str_replace("e-","*10^-",output);
    ofstream out;
    out.open(file.c_str());
    if(!out.is_open())
        cout<<"Could not open Outputfile "<<file<<endl;
    out<<output;
    out.close();
    return;
}



