#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myMotykaDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += std::min(data[i], codes[i])/(data[i] + codes[i]);

    }

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> motyka() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myMotykaDef));
}
