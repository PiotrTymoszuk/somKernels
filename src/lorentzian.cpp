#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myLorentzianDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double lorentzian = 0.0;

    for (int i = 0; i < n; i++) {

      lorentzian += std::log(1 + std::abs(data[i] - codes[i]));

    }

    return lorentzian;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> lorentzian() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myLorentzianDef));
}
