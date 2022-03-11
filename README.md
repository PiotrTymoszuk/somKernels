# somKernels
Extra distance calculation Rcpp pointers for the _kohonen_ package.

Enables generation of self-organizing maps (SOM) with additional distance measures provided as _dist.fcts_ argument to _som()_ and _supersom()_ functions. Run _get_kernel_info()_ to get available distance measures. The distance pointers are called by their name (_dist.fcts_ = _'dice'_).
