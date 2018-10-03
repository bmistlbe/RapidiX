
#ifndef GlobDef_h
#define GlobDef_h


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
#include <stdio.h>
#include <string.h>

using namespace std;

extern double Pi;
extern string path;

void str_replace(string rep, string wit, string & in);
vector<double> Multiply(const vector<double> & a,const vector<double> & b);
vector<double> Add(const vector<double> & a,const vector<double> & b);


vector<int> lst(int a1,int a2,int a3);
extern int delcoefm2,delcoefm1,delcoef0,delcoef1,delcoef2,delcoef3,delcoef4,delcoef5,delcoef6;


#endif
