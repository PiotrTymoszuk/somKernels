#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myJaccardDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double num = 0.0;
    double denom1 = 0.0;
    double denom2 = 0.0;
    double jacc = 0.0;

    for (int i = 0; i < n; i++) {
        num += data[i] * codes[i];
        denom1 += std::pow(data[i], 2);
        denom2 += std::pow(codes[i], 2);
    }

    jacc = 1 - num/(denom1 + denom2 - num);

    return jacc;

}

// [[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> jaccard() {
    return Rcpp::XPtr<DistanceFunctionPtr>(
    new DistanceFunctionPtr(&myJaccardDef));
}
