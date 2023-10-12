# Tests if the kernels work smoothly with the kohonen tools

  library(kohonen)
  library(somKernels)

  test_data <- iris[c('Sepal.Length', 'Sepal.Width', 'Petal.Length', 'Petal.Width')]

  test_data <- purrr::map_dfc(test_data,
                              ~(.x - min(.x))/(max(.x) - min(.x)))

  test_grid <-  kohonen::somgrid(xdim = 5,
                                 ydim = 4,
                                 topo = 'hexagonal',
                                 neighbourhood.fct = 'gaussian',
                                 toroidal = FALSE)

  test_som <- list()

  test_dist <- get_kernel_info()

  test_som <- purrr::map(test_dist,
                         ~purrr::safely(kohonen::som)(as.matrix(test_data),
                                                      grid = test_grid,
                                                      rlen = 1000,
                                                      dist.fcts = .x))

  test_som <- rlang::set_names(test_som, test_dist)

  test_errors <- purrr::compact(purrr::map(test_som, ~.x$error))

  test_som <- purrr::compact(purrr::map(test_som, ~.x$result))

  plot(test_som$BrayCurtis, type = 'changes')
  plot(test_som$cosine, type = 'changes')
  plot(test_som$dice, type = 'changes')
  plot(test_som$jaccard, type = 'changes')
  plot(test_som$smc, type = 'changes')
  plot(test_som$canberra, type = 'changes')
  plot(test_som$chebyshev, type = 'changes')
  plot(test_som$soergel, type = 'changes')
  plot(test_som$kulczynski_d, type = 'changes')
  plot(test_som$lorentzian, type = 'changes')
  plot(test_som$intersection, type = 'changes')
  plot(test_som$wavehedges, type = 'changes')
  plot(test_som$czekanowski, type = 'changes')
  plot(test_som$motyka, type = 'changes')
  plot(test_som$ruzicka, type = 'changes')
  plot(test_som$inner_product, type = 'changes')
  plot(test_som$harmonic_mean, type = 'changes')
  plot(test_som$hassebrook, type = 'changes')
  plot(test_som$fidelity, type = 'changes')
  plot(test_som$bhattacharyya, type = 'changes')
  plot(test_som$squared_chord, type = 'changes')
  plot(test_som$squared_euclidean, type = 'changes')
  plot(test_som$pearson, type = 'changes')
  plot(test_som$squared_chi, type = 'changes')
  plot(test_som$prob_symm, type = 'changes')
  plot(test_som$divergence, type = 'changes')
  plot(test_som$clark, type = 'changes')
  plot(test_som$jensen_difference, type = 'changes')

# END ------
