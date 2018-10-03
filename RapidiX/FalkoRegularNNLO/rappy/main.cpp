#include <iostream>
#include "nnlo_sub.hpp"

auto main(int, char**)->int{
    // returns a 6-array of {gg, gq, qg, qqb, qq, Q2}
    // argument is zb!
    auto subtraction = nnlo_subtraction(.3);
    for(auto x : subtraction){
        std::cout << x << "\n";
    }
    subtraction = nnlo_subtraction(.99);
    for(auto x : subtraction){
        std::cout << x << "\n";
    }

    return 0;
}
