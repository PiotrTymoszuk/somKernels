#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myHassebrookDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;
    double num = 0.0;
    double denom1 = 0.0;
    double denom2 = 0.0;

    for (int i = 0; i < n; i++) {

      num += data[i] * codes[i];
      denom1 += std::pow(data[i], 2);
      denom2 += std::pow(codes[i], 2);

    }

    dist = 1 - num/(denom1 + denom2 - num);

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> hassebrook() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myHassebrookDef));
}
