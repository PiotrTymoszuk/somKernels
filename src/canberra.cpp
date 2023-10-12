#include <Rcpp.h>
#include "somKernels_types.h"
using namespace Rcpp;

double myCanberraDef(double *data, double *codes, int n, int nNA) {

    if (nNA > 0) return NA_REAL;

    double num = 0.0;
    double denom = 0.0;
    double canberra = 0.0;

    for (int i = 0; i < n; i++) {

        num += std::abs(data[i] - codes[i]);
        denom += data[i] + data[i];

    }

    canberra = num/denom;

    return canberra;

}

//[[Rcpp::export]]
Rcpp::XPtr<DistanceFunctionPtr> canberra() {
    return Rcpp::XPtr<DistanceFunctionPtr>(new DistanceFunctionPtr(&myCanberraDef));
}
