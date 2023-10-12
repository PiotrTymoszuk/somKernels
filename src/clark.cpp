#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myClarkDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += std::abs((data[i] - codes[i]))/std::pow((data[i] + codes[i]), 2);

    }

    dist = std::sqrt(dist);

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> clark() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myClarkDef));
}
