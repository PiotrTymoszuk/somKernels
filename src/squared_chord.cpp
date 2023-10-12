#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double mySquaredChordDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += std::pow((std::sqrt(data[i]) - std::sqrt(codes[i])), 2);

    }

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> squared_chord() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&mySquaredChordDef));
}
