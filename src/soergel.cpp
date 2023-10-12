#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double mySoergelDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double num = 1.0;
    double denom = 1.0;
    double soergel = 0.0;

    for (int i = 0; i < n; i++) {

      num += std::abs(data[i] - codes[i]);
      denom += std::max(data[i], codes[i]);

    }

    soergel = num/denom;

    return soergel;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> soergel() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&mySoergelDef));
}
