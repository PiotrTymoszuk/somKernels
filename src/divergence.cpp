#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myDivergenceDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += std::pow((data[i] - codes[i]), 2)/std::pow((data[i] + codes[i]), 2);

    }

    dist = 2 * dist;

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> divergence() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myDivergenceDef));
}
