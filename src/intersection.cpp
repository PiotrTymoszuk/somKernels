#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myIntersectionDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double intersection = 0.0;

    for (int i = 0; i < n; i++) {

      intersection += std::min(data[i], codes[i]);

    }

    intersection = 1 - intersection;

    return intersection;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> intersection() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myIntersectionDef));
}
