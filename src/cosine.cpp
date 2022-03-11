#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myCosineDef(double *data, double *codes, int n, int nNA) {
    
    if (nNA > 0) return NA_REAL;

    double num = 0.0;
    double denom1 = 0.0;
    double denom2 = 0.0;
    double cosine = 0.0;
      
    for (int i = 0; i < n; i++) {
        num += data[i] * codes[i];
        denom1 += data[i] * data[i];
        denom2 += codes[i] * codes[i];
    }
      
    cosine = 1 - num/(sqrt(denom1) + sqrt(denom2));

    return cosine;
        
}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> cosine() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myCosineDef));
}