#include "../includes/Vegas.h"

std::random_device rd;
std::mt19937 mt(0);
std::uniform_real_distribution<double> myrand(0, 1.0);

//Get the bin number of the grid with gridnr to which the point belongs
int VegasIntegrator::GetBin(const double & point,const int & gridnr)
{
    for(int i=0;i<gridsize;++i)
        if(point<grid_lowerbounds[gridnr][i])
            return i-1;
    return 0;
}

//Compute a random point according to the grid with gridnr from a flat random number why and also store the bin of the grid in bin.
double VegasIntegrator::InverseGrid(const int & gridnr,const double & y,int & bin)
{
    
    double cumulant=0;
    for(int i=0;i<gridsize;++i)
    {
        if(cumulant+Distribution[gridnr][i]*(grid_upperbounds[gridnr][i]-grid_lowerbounds[gridnr][i])<y)
        {
            cumulant+=Distribution[gridnr][i]*(grid_upperbounds[gridnr][i]-grid_lowerbounds[gridnr][i]);
            continue;
        }
        bin=i;
        return (y-cumulant)/Distribution[gridnr][i]+grid_lowerbounds[gridnr][i];
    }
    return 0;
}


//Get a Single Vegas Point
void VegasIntegrator::GetSinglePoint(double * point,int * bins)
{
    for(int j=0;j<dimension;++j)
        point[j]=InverseGrid(j,myrand(mt),bins[j]);
    return;
}

//Generate Random Numbers according to Grids
void VegasIntegrator::GetPoints(const int & numpoints,double ** points, int ** bins)
{

//#pragma omp for
    for(int i=0;i<numpoints;++i)
    {
        for(int j=0;j<dimension;++j)
        {
            points[i][j]=InverseGrid(j,myrand(mt),bins[i][j]);
        }
    }
    return;
}

void VegasIntegrator::GridAdapt()
{
    int i,j;
    for(i=0;i<dimension;++i)
    {
        if(GridIntegralSum[i]==0)
            continue;

        double newdown[gridsize];
        double newup[gridsize];
        for(j=0;j<gridsize;j++)
        {
            newdown[j]=0;
            newup[j]=1;
        }
        int currbin=0;
        double locint=0;
        
        for(j=0;j<gridsize-1;++j)
        {
            if(newdown[j]>grid_lowerbounds[i][currbin])
            {
                //cout<<"if1"<<endl;
                if(locint+fabs(GridIntegral[i][currbin]*(grid_upperbounds[i][currbin]-newdown[j])/(grid_upperbounds[i][currbin]-grid_lowerbounds[i][currbin]))<GridIntegralSum[i]/(double)gridsize)
                {
                    //cout<<"1"<<endl;
                    locint+=fabs(GridIntegral[i][currbin]*(grid_upperbounds[i][currbin]-newdown[j])/(grid_upperbounds[i][currbin]-grid_lowerbounds[i][currbin]));
                    currbin++;
                    j--;
                    continue;
                }
            }
            else
            {
                //cout<<"else1"<<endl;
                if(locint+fabs(GridIntegral[i][currbin])<GridIntegralSum[i]/(double)gridsize)
                {
                    //cout<<"2"<<endl;
                    locint+=fabs(GridIntegral[i][currbin]);
                    currbin++;
                    j--;
                    continue;
                }
            }
            if(newdown[j]>grid_lowerbounds[i][currbin])
            {
                //cout<<"3"<<endl;
                newup[j]=(GridIntegralSum[i]/(double)gridsize-locint)/fabs(GridIntegral[i][currbin])*(grid_upperbounds[i][currbin]-grid_lowerbounds[i][currbin])+newdown[j];
                locint=0;
            }
            else
            {
                //cout<<"4 "<<locint<<endl;
                 newup[j]=(GridIntegralSum[i]/(double)gridsize-locint)/fabs(GridIntegral[i][currbin])*(grid_upperbounds[i][currbin]-grid_lowerbounds[i][currbin])+grid_lowerbounds[i][currbin];
                locint=0;
            }
            if(j<gridsize-1)
                newdown[j+1]=newup[j];
            //cout<<"new: "<<newdown[j]<<"  "<<newup[j]<<endl;
            continue;
        }
        for(j=0;j<gridsize;j++)
        {
            grid_lowerbounds[i][j]=newdown[j];
            grid_upperbounds[i][j]=newup[j];
            GridIntegral[i][j]=GridIntegralSum[i]/(double)gridsize;
        }
    }
    //Update Sampling Distribution
    for(i=0;i<dimension;++i)
        for(j=0;j<gridsize;++j)
            Distribution[i][j]=1/(double)gridsize/(grid_upperbounds[i][j]-grid_lowerbounds[i][j]);
    
    /*cout<<"New Grid: "<<endl;
    for(i=0;i<gridsize;++i)
    {
        cout<<i<<": "<<grid_lowerbounds[0][i]<<" - "<<grid_upperbounds[0][i]<<" Integral in Bin: "<<GridIntegral[0][i]<<endl;
    }
    //*/
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
    //#pragma omp parallel for private(i)
    for(i=0;i<numpoints;++i)
        for(j=0;j<dimension;++j)
        {
            if(j==0)
                weights[i]=1;
            weights[i]*=1.0/Distribution[j][bins[i][j]];
        }
    
    StoredExportData.clear();
    StoredExportData.resize(numpoints,0);
    
    //#pragma omp parallel for private(i)
    for(i=0;i<numpoints;++i)
    {
        //cout << "Evaluating Integrand: " << i/(double)numpoints*100.0 << "%\r" << std::flush;
        if(ExportComponents!=0)
        {
            StoredExportData[i]=new double [ExportComponents];
            for(int k=0;k<ExportComponents;++k)
                StoredExportData[i][k]=0;
        }
        while(true)
        {
            f(points[i],function_value[i],userdata,StoredExportData[i]);
            if(std::isnan((double)function_value[i][0])||std::isinf(function_value[i][0]))
            {
                //cout<<"Infinity!"<<endl;
                GetSinglePoint(points[i],bins[i]);
            }
            else
                break;
        }
        
        if(ExportComponents!=0)
            StoredExportData[i][0]=weights[i]/(double)numpoints;
    }
    
    
    //Compute Integral and Variance
    for(i=0;i<components;++i)
    {
        results[i]=0;
        variances[i]=0;
    }
    //#pragma omp parallel for private(j)
    for(j=0;j<components;++j)
    {
        for(i=0;i<numpoints;++i)
        {
            results[j]+=function_value[i][j]*weights[i]/(double)numpoints;
            variances[j]+=pow(function_value[i][j]*weights[i],2)/(double)numpoints;
        }
    }
    for(i=0;i<components;++i)
        variances[i]=fabs(variances[i]-results[i]*results[i])/(double)(numpoints-1);
    
    //Adapt integration Grids
    if(adapt)
    {
        //cout<<"Adapt!"<<endl;
        //Compute Integral per Grid Bin of this iteration
        double ** LocGridIntegral=new double * [dimension];
        double * LocGridIntegralSum=new double [dimension];
        for(i=0;i<dimension;++i)
        {
            LocGridIntegralSum[i]=0;
            LocGridIntegral[i]=new double [gridsize];
            for(j=0;j<gridsize;++j)
                LocGridIntegral[i][j]=0;
        }
        
        
        //        //#pragma omp parallel for private(j)
        //        for(j=0;j<dimension;++j)
        //        {
        //            for(i=0;i<numpoints;++i)
        //            {
        //                LocGridIntegral[j][bins[i][j]]+=fabs(function_value[i][0]*weights[i])/(double)numpoints;
        //                LocGridIntegralSum[j]+=fabs(function_value[i][0]*weights[i])/(double)numpoints;
        //            }
        //        }
        
        //#pragma omp parallel for private(j)
        for(j=0;j<dimension;++j)
            for(i=0;i<numpoints;++i)
                LocGridIntegral[j][bins[i][j]]+=function_value[i][0]*weights[i]/(double)numpoints;
        for(j=0;j<dimension;++j)
            for(i=0;i<gridsize;++i)
            {
                LocGridIntegral[j][i]=fabs(LocGridIntegral[j][i]);
                LocGridIntegralSum[j]+=LocGridIntegral[j][i];
            }
        
        
        //Update Grid Integrals
        //#pragma omp parallel for private(i)
        for(i=0;i<dimension;++i)
        {
            for(j=0;j<gridsize;++j)
                GridIntegral[i][j]=(GridIntegral[i][j]*totpoints+LocGridIntegral[i][j]*numpoints)/(double)(numpoints+totpoints);
            GridIntegralSum[i]=(GridIntegralSum[i]*totpoints+numpoints*LocGridIntegralSum[i])/(double)(numpoints+totpoints);
        }
        
        //Adapt
        GridAdapt();
        
        //Delete Allocated Arrays
        for(i=0;i<dimension;++i)
            delete LocGridIntegral[i];
        delete LocGridIntegral;
        delete LocGridIntegralSum;
    }
    
    totpoints+=numpoints;
    
    //Delete allocated doubles
    for(i=0;i<numpoints;++i)
    {
        delete points[i];
        delete bins[i];
        delete function_value[i];
    }
    delete points;
    delete bins;
    delete function_value;
    delete weights;
    return;
    
}


void VegasIntegrator::InitiateIntegrationGrids()
{
    if(verbose)
        cout<<"Initiating flat Grids!"<<endl;
    
    grid_lowerbounds=new double * [dimension];
    grid_upperbounds=new double * [dimension];
    GridIntegral=new double * [dimension];
    Distribution=new double * [dimension];
    GridIntegralSum=new double  [dimension];
    
    for(int i=0;i<dimension;++i)
    {
        GridIntegralSum[i]=0;
        grid_lowerbounds[i]=new double [gridsize];
        grid_upperbounds[i]=new double [gridsize];
        GridIntegral[i]=new double [gridsize];
        Distribution[i]=new double [gridsize];
        for(int j=0;j<gridsize;++j)
        {
            grid_lowerbounds[i][j]=j/(double)gridsize;
            grid_upperbounds[i][j]=(j+1)/(double)gridsize;
            GridIntegral[i][j]=0;
            Distribution[i][j]=1.0;
        }
    }
    return;
}

//Integrate a Function
int VegasIntegrator::Integrate(int (*f)(const double * xx,double * ff,const void * userdata,double * ExportData),double * & integral,double * & error,double * & chisq,const void *userdata)
{
    StoredIntegrals.clear();
    StoredErrors.clear();
    
    mt=std::mt19937(randseed+rd());
    int c=0;
    int i,j;
    
    if(verbose==1)
        cout<<"Starting Vegas Integration!"<<endl;
    totpoints=0;
    
    StoredExportData.clear();
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
    adapt=true;
    
    //Initial Sampling
    double * res=new double [components];
    double * var=new double [components];
    this->PerformSampling(f,startsize,res,var,userdata);
    delete var;
    delete res;
    vector<double *> variances,integrals;
    if(verbose>=1)
        cout<<"Initial Sampling done!"<<endl;
    vector<double > vs;
    while(true)
    {
        c++;
        res=new double [components];
        var=new double [components];
        this->PerformSampling(f,batchsize,res,var,userdata);
        variances.push_back(var);
        integrals.push_back(res);
        vs.push_back(var[0]*(batchsize-1)+res[0]*res[0]);
        //cout<<"This integration gave me "<<res[0]<<" +- "<<sqrt(var[0])<<" +- "<<sqrt(var[0])/res[0]*100<<" % "<<endl;
        
        if(c==mineval)
        {
            variances.clear();
            integrals.clear();
            variances.push_back(var);
            integrals.push_back(res);
            adapt=false;
            if(verbose>=1)
                cout<<endl<<"!!!!! MinEval Done! Starting Serious Integration !!!!!"<<endl<<endl;
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
        
        stringstream ss;
        ss<<"VegasGrids/Step"<<c<<".txt";
        if(GridExport)
            ExportGrids(ss.str());
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
    mt=std::mt19937(randseed+rd());
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
    
    //cout<<"Integral: "<<integral[0]<<" +- "<<error[0]/integral[0]*100<<" % ChiSq: "<<chisq[0]<<" Number of Points: "<<batchsize<<endl;
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
            Distribution[i][j]=1/(double)gridsize/(grid_upperbounds[i][j]-grid_lowerbounds[i][j]);
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

