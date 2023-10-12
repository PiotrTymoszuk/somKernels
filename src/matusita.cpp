#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myMatusitaDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += std::sqrt(data[i] * codes[i]);

    }

    dist = std::sqrt(2 - 2*dist);

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> matusita() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myMatusitaDef));
}
