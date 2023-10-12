# somKernels
Extra distance Rcpp pointers for the _kohonen_ package.

Enables generation of self-organizing maps (SOM) with additional distance measures provided as the `dist.fcts` argument to `som()` and `supersom()` functions from _kohonen_ package. Run `get_kernel_info()` to get available distance measures. The distance pointers are called by their name (e.g. `dist.fcts = 'dice'`).

## Installation

You may easily fetch the package with `devtools`: 

```r
devtools::install_github('PiotrTymoszuk/somKernels')

```

## Terms of use

The package is available under a GPL-3 license.

## Contact

The package maintainer is [Piotr Tymoszuk](mailto:piotr.s.tymoszuk@gmail.com).

## Acknowledgements

`soucer` uses tools provided by [Rcpp](https://www.rcpp.org/). Many thanks to the developers, maintainers and contributors.

## Usage

We'll start with loading the packages needed to test functionality of the distance pointers:

```r
  library(kohonen)
  library(somKernels)
```
The available distances include most of distances covered by the R's [_philentropy_ package](https://cran.r-project.org/web/packages/philentropy/index.html). The distance list is returned by `get_kernel_info()`:

```r
> get_kernel_info()

 [1] "BrayCurtis"        "cosine"            "dice"              "jaccard"           "smc"               "sumofsquares"     
 [7] "euclidean"         "manhattan"         "tanimoto"          "canberra"          "chebyshev"         "soergel"          
[13] "kulczynski_d"      "lorentzian"        "intersection"      "wavehedges"        "czekanowski"       "motyka"           
[19] "ruzicka"           "inner_product"     "harmonic_mean"     "hassebrook"        "fidelity"          "bhattacharyya"    
[25] "hellinger"         "matusita"          "squared_chord"     "squared_euclidean" "pearson"           "neyman"           
[31] "squared_chi"       "prob_symm"         "divergence"        "clark"             "additive_symm"     "jeffreys"         
[37] "k_divergence"      "topsoe"            "jensen_difference" "taneja"  
```
Usage of the distance pointers is quite simple: you just pass the pointer name to the `dist.fcts` argument of the _kohonen's_ `som()` or `supesom()` function. We'll check them out with the popular `iris` data set. The data set will be clustered with $5 \times 4$ hexagonal SOM with Canberra and Ruzicka distance. Of importance, simirarity coefficients such as cosine or Ruzicka coefficient are donverted to distances with a simple $dist = 1 - simil$ formula.

```r
  test_data <-
    iris[c('Sepal.Length', 'Sepal.Width', 'Petal.Length', 'Petal.Width')]

  ## generating a SOM grid object required by `som()` and `supersom()`

  som_grid <- somgrid(xdim = 5,
                      ydim = 4,
                      topo = 'hexagonal',
                      neighbourhood.fct = 'gaussian',
                      toroidal = TRUE)

  ## fitting SOMs with Canberra and Ruzicka distances

  canberra_som <- som(as.matrix(test_data),
                      grid = som_grid,
                      rlen = 1000,
                      dist.fcts = 'canberra')

  ruzicka_som <- som(as.matrix(test_data),
                     grid = som_grid,
                     rlen = 1000,
                     dist.fcts = 'ruzicka')
```
Let's check if the distances worked by examining plots of their training process - mean distances to the SOM nodes at subsequent iterations. A decrease in mean distance with progressing iterations followed by a plateau indicates algorithm convergence:

```r
plot(canberra_som, type = 'changes')
```
![image](https://github.com/PiotrTymoszuk/somKernels/assets/80723424/69f67ba4-d92f-4fda-9712-44c8aba96e25)

```r
plot(ruzicka_som, type = 'changes')
```
![image](https://github.com/PiotrTymoszuk/somKernels/assets/80723424/df89821f-b941-4be1-a1c1-1a53b7f3f966)
