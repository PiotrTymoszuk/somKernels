#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myBhattacharyyaDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double dist = 0.0;

    for (int i = 0; i < n; i++) {

      dist += std::sqrt(data[i] * codes[i]);

    }

    dist = -1 * std::log(dist);

    return dist;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> bhattacharyya() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myBhattacharyyaDef));
}
