#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myKulczynskiDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double num = 1.0;
    double denom = 1.0;
    double kulczynski = 0.0;

    for (int i = 0; i < n; i++) {

      num += std::abs(data[i] - codes[i]);
      denom += std::min(data[i], codes[i]);

    }

    kulczynski = num/denom;

    return kulczynski;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> kulczynski_d() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myKulczynskiDef));
}
