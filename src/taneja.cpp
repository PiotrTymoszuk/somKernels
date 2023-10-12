#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myTanejaDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += (data[i] + codes[i])/2 * std::log((data[i] + codes[i])/(2 * std::log(data[i] * codes[i])));

    }

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> taneja() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myTanejaDef));
}
