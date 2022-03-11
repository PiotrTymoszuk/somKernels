#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

 double mySMCdef(double *data, double *codes, int n, int nNA) {
     
     if (nNA > 0) return NA_REAL;

     double num = 0.0;
      
     for (int i = 0; i < n; i++) {
        num += std::abs(data[i] - codes[i]);
     }

     return num/n;
        
 }

// [[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> smc() {
    return Rcpp::XPtr<DistanceFunctionPtr>(
    new DistanceFunctionPtr(&mySMCdef));
}