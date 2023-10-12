#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myJeffreysDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += (data[i] - codes[i]) * std::log(data[i]/codes[i]);

    }

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> jeffreys() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myJeffreysDef));
}
