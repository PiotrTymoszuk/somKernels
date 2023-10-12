#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myChebyshevDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    NumericVector d (n);
    double chebyshev = 0;

    for (int i = 0; i < n; i++) {

        d[i] = std::abs(data[i] - codes[i]);

    }

    chebyshev = *std::max_element(d.begin(), d.end());

    return chebyshev;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> chebyshev() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myChebyshevDef));
}
