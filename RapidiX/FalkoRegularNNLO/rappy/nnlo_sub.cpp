#include "nnlo_sub.hpp"
#include "functions.hpp"
#include <cmath>



std::array<double, 6> nnlo_subtraction(double zb){
    auto real_parts = prepare_real_parts(zb);
    auto imag_parts = prepare_imag_parts(zb);
    double  xb = sqrt(1-zb);
    double Z3 = 1.20205690315959428539973816151;
    double Pi = 3.14159265358979323846264338328;
    double L2 = log(2);
    auto gr = [&real_parts](unsigned int i) { return real_parts[i-1]; };
    auto gi = [&imag_parts](unsigned int i) { return imag_parts[i-1]; };

    std::array<double, 6> res{
#include "sub.inc"
    };
    return res;
}

