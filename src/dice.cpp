#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myDiceDef(double *data, double *codes, int n, int nNA) {
      
    if (nNA > 0) return NA_REAL;

    double num = 0.0;
    double denom1 = 0.0;
    double denom2 = 0.0;
    double dice = 0.0;
      
    for (int i = 0; i < n; i++) {
        num += (data[i] - codes[i]) * (data[i] - codes[i]);
        denom1 += data[i] * data[i];
        denom2 += codes[i] * codes[i];
    }
      
    dice = num/(denom1 + denom2);

    return dice;
        
}

// [[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> dice() {
    return Rcpp::XPtr<DistanceFunctionPtr>(
    new DistanceFunctionPtr(&myDiceDef));
}