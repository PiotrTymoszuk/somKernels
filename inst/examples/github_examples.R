
# packages ------

  library(kohonen)
  library(somKernels)

# Testing the SOMs ------

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

