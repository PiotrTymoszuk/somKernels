#include <Rcpp.h>
using namespace Rcpp;

typedef double (*DistanceFunctionPtr)(double *, double *, int, int);