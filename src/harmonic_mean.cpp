#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myHarmonicMeanDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += (data[i] * codes[i])/(data[i] + codes[i]);

    }

    dist = 2 * dist;

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> harmonic_mean() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myHarmonicMeanDef));
}
