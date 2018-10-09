//
//  main.cpp
//  IXS
//
//  Created by Bernhard Mistlberger on 20/10/17.
//  Copyright © 2017 Bernhard Mistlberger. All rights reserved.
//

#include "Gs/Gs.h"

using namespace std;

int main(int argc, const char * argv[]) {

    cout<<argc<<endl;
    if(argc<=2)
        cout<<"Usage: GTest arg1 .. argn x"<<endl;
    if(argc==3)
        cout<<G(atof(argv[1]),atof(argv[2]))<<endl;;
    if(argc==4)
        cout<<G(atof(argv[1]),atof(argv[2]),atof(argv[3]))<<endl;;
    if(argc==5)
        cout<<G(atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]))<<endl;;
    if(argc==6)
        cout<<G(atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]))<<endl;;
    if(argc==7)
        cout<<G(atof(argv[1]),atof(argv[2]),atof(argv[3]),atof(argv[4]),atof(argv[5]),atof(argv[6]))<<endl;;


    return 0;
}
