#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myCzekanowskiDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;
    double num = 0.0;
    double denom = 0.0;

    for (int i = 0; i < n; i++) {

      num += std::abs(data[i] - codes[i]);
      denom += std::abs(data[i] + codes[i]);

    }

    dist = num/denom;

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> czekanowski() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myCzekanowskiDef));
}
