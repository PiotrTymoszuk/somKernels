#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double mySquaredChiDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += std::pow((data[i] - codes[i]), 2)/(data[i] + codes[i]);

    }

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> squared_chi() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&mySquaredChiDef));
}
