#include "../includes/Vegas.h"

std::random_device rd;


void VegasIntegrator::SetRandomSeed(int ranseed)
{
    mt=std::mt19937(ranseed+rd());
    //cout<<"First Rand: "<<myrand(mt)<<endl;
    return;
}

//Average the Bins
void AverageDistribution(vector<double> & dist)
{
    vector<double> newdist=dist;
    for(int i=2;i<dist.size()-2;++i)
        dist[i]=(newdist[i-2]+newdist[i-1]+newdist[i]+newdist[i+1]+newdist[i+5])/5.0;
    return;
}

//Get the bin number of the grid with gridnr to which the point belongs
int VegasIntegrator::GetBin(const double & point,const int & gridnr)
{
    for(int i=1;i<gridsize;++i)
        if(point<grid_lowerbounds[gridnr][i])
            return i-1;
    return gridsize-1;
}

int VegasIntegrator::GetBin(const double & point,const double * upperbounds)
{
    for(int i=0;i<gridsize;++i)
        if(point<upperbounds[i])
            return i;
    return 0;
}

//Compute a random point according to the grid with gridnr from a flat random number y and also store the bin of the grid in bin.
double VegasIntegrator::InverseGrid(const int & gridnr,const double & y,int & bin)
{
    
    double cumulant=0.0;
    for(int i=0;i<gridsize;++i)
    {
        if(cumulant+1.0/(double)gridsize<y)
        {
            cumulant+=1.0/(double)gridsize;
            continue;
        }
        bin=i;
        return (y-cumulant)*(grid_upperbounds[gridnr][i]-grid_lowerbounds[gridnr][i])*gridsize+grid_lowerbounds[gridnr][i];
    }
    return 0;
}


//Get a Single Vegas Point
void VegasIntegrator::GetSinglePoint(double * point,int * bins)
{
    for(int j=0;j<dimension;++j)
    {
        point[j]=InverseGrid(j,myrand(mt),bins[j]);
    }
    return;
}


//Generate Random Numbers according to Grids
void VegasIntegrator::GetPoints(const int & numpoints,double ** points, int ** bins)
{
    int i;
    int c=0;
//#pragma omp parallel for private(i) schedule(dynamic)
    for( i=0;i<numpoints;++i)
        for(int j=0;j<dimension;++j)
        {
            points[i][j]=InverseGrid(j,myrand(mt),bins[i][j]);
            
            //Technical Cut
            if(points[i][j]<1e-8||points[i][j]>(1-1e-8))
            {
                j--;
                c++;
            }
        }
    if(c>numpoints/100.0)
        cout<<"Hit the technical cut in more than a percent of all Vegas points \vec{x}."<<endl;
    return;
}


//Update the the current grid given the data and xval vectors.
void VegasIntegrator::UpdateGrid(const vector<double> & xval, const vector<double> & fval, double * LowerBounds, double * UpperBounds)
{
    int i,j;
    vector<double> hist(gridsize,0);

    //Create positive definite Histogram
    for(i=0;i<fval.size();++i)
    {
        hist[GetBin(xval[i],UpperBounds)]+=fval[i];
    }
    for(i=0;i<hist.size();++i)
        hist[i]=fabs(hist[i]);
    //AverageDistribution(hist);
    
    
    
    //Create CDF - normalise
    double totxs=0;
    for(int i=0;i<hist.size();++i)
        totxs+=hist[i];
    for(int i=0;i<hist.size();++i)
        hist[i]*=1.0/totxs/(UpperBounds[i]-LowerBounds[i]);
    double target=1.0/((double)gridsize);
    
    //Adjust to new Histogram
    double pos=0;
    double content=0;
    int c=0,d=1;
    while(d<gridsize)
    {
        if(content+(UpperBounds[c]-pos)*hist[c]<target)
        {
            content+=(UpperBounds[c]-pos)*hist[c];
            pos=UpperBounds[c];
            c++;
            continue;
        }
        else
        {
            LowerBounds[d]=(target-content)/hist[c]+pos;
            pos=LowerBounds[d];
            d++;
            content=0;
            continue;
        }
    }
    for(i=0;i<gridsize-1;++i)
        UpperBounds[i]=LowerBounds[i+1];

    return;
}


void VegasIntegrator::PerformSampling(int (*f)(const double * xx,double * ff,const void * userdata,double * ExportData),const int & numpoints,double * results,double * variances,const void * userdata)
{
    int i,j;
    //Get Random Values
    double ** points=new double * [numpoints];
    double ** function_value=new double * [numpoints];
    int ** bins=new int * [numpoints];
    for(i=0;i<numpoints;++i)
    {
        points[i]= new double [dimension];
        bins[i]= new int [dimension];
        function_value[i]=new double[components];
    }
    this->GetPoints(numpoints,points,bins);

    //Compute Weights for every point
    double * weights=new double [numpoints];
//#pragma omp parallel for private(i) schedule(dynamic)
    for(i=0;i<numpoints;++i)
        for(j=0;j<dimension;++j)
        {
            if(j==0)
                weights[i]=1.0/(double)numpoints;
            weights[i]*=gridsize*(grid_upperbounds[j][bins[i][j]]-grid_lowerbounds[j][bins[i][j]]);
        }

    StoredExportData.clear();
    StoredExportData.resize(numpoints,0);
    
//Could be parallelised if the function called is parallelisable.
    for(i=0;i<numpoints;++i)
    {
        //Set the data vector to zero. This part could be done smarter.
        if(ExportComponents!=0)
        {
            StoredExportData[i]=new double [ExportComponents];
            for(int k=0;k<ExportComponents;++k)
                StoredExportData[i][k]=0;
        }
        
        while(true)
        {
            f(points[i],function_value[i],userdata,StoredExportData[i]);
            //If the function returns an infinite value retry another point.
            //That should'nt happen too ofton to maintain statistical meaning of stuff.
            if(fabs(function_value[i][0])>1e20)
                cout<<"Very Large Point (VLP) detected!"<<endl;
            
            if(std::isnan((double)function_value[i][0])||std::isinf(function_value[i][0]))
            {
                cout<<"Another Point!"<<endl;
                GetSinglePoint(points[i],bins[i]);
            }
            else
                break;
        }
        //Give back the Vegas weight for the Export data.
        if(ExportComponents!=0)
            StoredExportData[i][0]=weights[i];
    }
    

    //Compute Integral and Variance
    for(i=0;i<components;++i)
    {
        results[i]=0;
        variances[i]=0;
    }
//#pragma omp parallel for private(j) schedule(dynamic)
    for(j=0;j<components;++j)
    {
        for(i=0;i<numpoints;++i)
        {
            //cout<<"w:"<<weights[i]<<" x: "<<points[i][0]<<" f: "<<function_value[i][0]<<endl;
            results[j]+=function_value[i][j]*weights[i];
            variances[j]+=pow(function_value[i][j],2)*weights[i];
        }
    }
    for(i=0;i<components;++i)
        variances[i]=fabs(variances[i]-results[i]*results[i])/(double)(numpoints-1);
    
    
    
    
    //Adapt integration Grids
    if(adapt)
    {
        vector<double> LocNewValues(numpoints,0);
        vector<vector<double> > LocNewPoints(dimension,vector<double>(numpoints,0));
        for(i=0;i<numpoints;++i)
        {
            LocNewValues[i]=function_value[i][0]*weights[i];
//            if(fabs(function_value[i][0])>1e20)
//            {
//                cout<<"Ignoring Point!"<<endl;
//                LocNewValues[i]=0;
//            }
            
            for(j=0;j<dimension;++j)
                LocNewPoints[j][i]=points[i][j];
        }
        
        //Reset the grids for the first 5 iterations then accumulate data
        if(totpoints/numpoints<7)
        {
            GridSamplingValues.clear();
            for(j=0;j<dimension;++j)
                GridSamplingPoints[j].clear();
        }
        
        GridSamplingValues.insert(GridSamplingValues.end(),LocNewValues.begin(),LocNewValues.end());
        for(j=0;j<dimension;++j)
            GridSamplingPoints[j].insert(GridSamplingPoints[j].end(),LocNewPoints[j].begin(),LocNewPoints[j].end());
        
//#pragma omp parallel for private(i) schedule(dynamic)
        for(int i=0;i<dimension;++i)
        {
            //adjust twice, binning sucks.
            for(int j=0;j<5;++j)
                UpdateGrid(GridSamplingPoints[i],GridSamplingValues,grid_lowerbounds[i],grid_upperbounds[i]);
        }
    }

    //well:
    totpoints+=numpoints;
    
    //Delete allocated doubles
    for(i=0;i<numpoints;++i)
    {
        delete[] points[i];
        delete[] bins[i];
        delete[] function_value[i];
    }
    delete[] points;
    delete[] bins;
    delete[] function_value;
    delete[] weights;
    return;
    
}


void VegasIntegrator::InitiateIntegrationGrids()
{
    if(verbose)
        cout<<"Initiating flat Grids of size: "<<gridsize<<"!"<<endl;
    
    grid_lowerbounds=new double * [dimension];
    grid_upperbounds=new double * [dimension];
    
    for(int i=0;i<dimension;++i)
    {
        grid_lowerbounds[i]=new double [gridsize];
        grid_upperbounds[i]=new double [gridsize];
        for(int j=0;j<gridsize;++j)
        {
            grid_lowerbounds[i][j]=j/(double)gridsize;
            grid_upperbounds[i][j]=(j+1)/(double)gridsize;
        }
    }
    return;
}

//Integrate a Function
int VegasIntegrator::Integrate(int (*f)(const double * xx,double * ff,const void * userdata,double * ExportData),double * & integral,double * & error,double * & chisq,const void *userdata)
{
    StoredIntegrals.clear();
    StoredErrors.clear();

    int c=0;
    int i,j;
    
    if(verbose==1)
        cout<<"Starting Vegas Integration!"<<endl;
    totpoints=0;
    
    StoredExportData.clear();
    GridSamplingValues.clear();
    GridSamplingPoints.clear();
    GridSamplingPoints.resize(dimension,vector<double>(0));
    
    //Initiate Output Variables
    integral=new double[components];
    error=new double[components];
    chisq=new double[components];
    for(i=0;i<components;++i)
    {
        integral[i]=0;
        error[i]=1;
        chisq[i]=0;
    }
    InitiateIntegrationGrids();
    //adapt=true;
    
    //Initial Sampling
    double * res=new double [components];
    double * var=new double [components];
    this->PerformSampling(f,startsize,res,var,userdata);
    delete var;
    delete res;
    vector<double *> variances,integrals;
    
    if(verbose==1)
        cout<<"Initial Sampling done!"<<endl;
    
    
    //Start to integrate until you hit the target precision!
    while(true)
    {
        c++;
        res=new double [components];
        var=new double [components];
        this->PerformSampling(f,batchsize,res,var,userdata);
        variances.push_back(var);
        integrals.push_back(res);
        
        //cout<<"This Iteration gave: "<<res[0]<<" +- "<<sqrt(var[0])<<" +- "<<sqrt(var[0])/res[0]*100 <<" %"<<endl;
        
        if(c==mineval)
        {
            variances.clear();
            integrals.clear();
            variances.push_back(var);
            integrals.push_back(res);
            adapt=false;
            if(verbose==1)
                cout<<endl<<"!!!!! MinEval Done! Starting Serious Integration !!!!!"<<endl<<endl;
            GridSamplingValues.clear();
            GridSamplingPoints.clear();
            GridSamplingPoints.resize(dimension,vector<double>(0));
        }
        
        for(i=0;i<components;++i)
        {
            error[i]=0;
            integral[i]=0;
            chisq[i]=0;
        }
        //Original Lepage Variance:
        for(i=0;i<components;++i)
        {
            for(int j=0;j<variances.size();j++)
            {
                error[i]+=1.0/variances[j][i];
                integral[i]+=integrals[j][i]/variances[j][i];
            }
            error[i]=1.0/sqrt(error[i]);
            integral[i]=error[i]*error[i]*integral[i];
            for(int j=0;j<variances.size();j++)
                chisq[i]+=pow(integral[i]-integrals[j][i],2)/variances[j][i];
        }
        
        //Export Sampling Grids
        if(GridExport)
        {
            stringstream ss;
            ss<<"VegasGrids/Step"<<c<<".txt";
            ExportGrids(ss.str());
        }
        
        if(verbose>=1)
            cout<<"Integral: "<<integral[0]<<" +- "<<error[0]<<" +- "<<fabs(error[0]/integral[0])*100<<" % ChiSq: "<<chisq[0]/(double)integrals.size()<<" Number of Points: "<<totpoints<<" Iteration: "<<c<<endl;
        if(fabs(error[0]/integral[0])<precision&&c>mineval)
            break;
        if(fabs(error[0]/integral[0])<absprecision&&c>mineval)
            break;
        if(totpoints>maxpoints)
            break;

            
    }
    StoredIntegrals.push_back(integral[0]);
    StoredErrors.push_back(error[0]);
    return 0;
}


//Integrate a Function with existing Grids for a fixed number of points batchsize
int VegasIntegrator::ContinueIntegrate(int (*f)(const double * xx,double * ff,const void * userdata,double * ExportData),double * & integral,double * & error,double * & chisq,const void *userdata)
{
    StoredExportData.clear();
    int c=0;
    int i,j;
    
    adapt=false;
    totpoints=0;
    
    //Initiate Output Variables
    integral=new double[components];
    error=new double[components];
    chisq=new double[components];
    for(i=0;i<components;++i)
    {
        integral[i]=0;
        error[i]=1;
        chisq[i]=0;
    }
    
    //Perform Integral
    this->PerformSampling(f,batchsize,integral,error,userdata);
    for(i=0;i<components;i++)
        error[i]=sqrt(error[i]);
    
    StoredIntegrals.push_back(integral[0]);
    StoredErrors.push_back(error[0]);
    
    double locres=0,locerr=0,locchisq=0;
    for(j=0;j<StoredIntegrals.size();++j)
    {
        locerr+=1.0/StoredErrors[j]/StoredErrors[j];
        locres+=StoredIntegrals[j]/StoredErrors[j]/StoredErrors[j];
    }
    locerr=1.0/sqrt(locerr);
    locres=locerr*locerr*locres;
    for(j=0;j<StoredIntegrals.size();++j)
        locchisq+=pow(locres-StoredIntegrals[j],2)/StoredErrors[j]/StoredErrors[j]/(double)StoredIntegrals.size();
    
    integral[0]=locres;
    error[0]=locerr;
    chisq[0]=locchisq;
    
    return 0;
}


void VegasIntegrator::ExportGrids(string file)
{
    ofstream out;
    out<<setprecision(16);
    out.open(file.c_str());
    if(!out.is_open())
    {
        cout<<"Could not write file: "<<file<<endl;
        exit(0);
    }
    out<<"{";
    for(int i=0;i<dimension;++i)
    {
        out<<"{";
        for(int j=0;j<gridsize;++j)
        {
            out<<"{"<<grid_lowerbounds[i][j]<<","<<grid_upperbounds[i][j]<<"}";
            if(j<gridsize-1)
                out<<",";
        }
        out<<"}";
        if(i<dimension-1)
            out<<",";
    }
    out<<"}";
    out.close();
    return;
    
}



void VegasIntegrator::ImportGrids(string file)
{
    ifstream input;
    input.open(file.c_str());
    if(!input.is_open())
    {
        cout<<"Could not read file: "<<file<<endl;
        exit(0);
    }
    
    stringstream ss;
    string buffer="";
    while(!input.eof())
    {
        buffer="";
        input>>buffer;
        ss<<buffer;
    }
    input.close();
    buffer=ss.str();
    
    vector<vector<double> > low,high;
    vector<double>   low1,high1;
    ss.str("");
    string loc;
    int in=0;
    for(int i=0;i<buffer.size();i++)
    {
        loc=buffer[i];
        if(in==0&&loc.compare("{")==0)
        {
            in++;
            continue;
        }
        if(in==1&&loc.compare("{")==0)
        {
            in++;
            low1.clear();
            high1.clear();
            continue;
        }
        if(in==2&&loc.compare("{")==0)
        {
            in++;
            continue;
        }
        if(in==3&&loc.compare(",")==0)
        {
            low1.push_back(atof(ss.str().c_str()));
            ss.str("");
            continue;
        }
        if(in==3&&loc.compare("}")==0)
        {
            in--;
            high1.push_back(atof(ss.str().c_str()));
            ss.str("");
            continue;
        }
        if(in==2&&loc.compare("}")==0)
        {
            in--;
            low.push_back(low1);
            high.push_back(high1);
            continue;
        }
        if(in==2&&loc.compare(",")==0)
        {
            continue;
        }
        if(in==1&&loc.compare(",")==0)
        {
            continue;
        }
        if(in==1&&loc.compare("}")==0)
        {
            in--;
            continue;
        }
        ss<<loc;
    }
    gridsize=high[0].size();
    dimension=high.size();
    InitiateIntegrationGrids();
    for(int i=0;i<dimension;++i)
    {
        for(int j=0;j<gridsize;++j)
        {
            grid_lowerbounds[i][j]=low[i][j];
            grid_upperbounds[i][j]=high[i][j];
        }
    }
    return;
    
}


void VegasIntegrator::StoreExportData()
{
    ofstream out;
    out.open(ExportFile.c_str());
    if(!out.is_open())
    {
        cout<<"Could not open Vegas Outputfile!"<<endl;
        cout<<ExportFile<<endl;
        return;
    }
    double test=0;
    out<<std::setprecision(16)<<scientific <<"{";
    for(int i=0;i<StoredExportData.size();++i)
    {
        out<<"{";
        for(int j=0;j<ExportComponents;j++)
        {
            out<<StoredExportData[i][j];
            if(j<ExportComponents-1)
                out<<",";

        }
        test+=StoredExportData[i][0]*StoredExportData[i][7];
        out<<"}";
        if(i<StoredExportData.size()-1)
            out<<",";
    }
    cout<<"Total XS exported: "<<test<<endl;
    out<<"}";
    out.close();
    return;
}

