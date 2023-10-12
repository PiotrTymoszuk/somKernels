# Available distance pointers

#' Available distance pointers.
#'
#' @description Returns a vector with currently available distance pointers
#' @export

  get_kernel_info <- function() {

    c('BrayCurtis',
      'cosine',
      'dice',
      'jaccard',
      'smc',
      'sumofsquares',
      'euclidean',
      'manhattan',
      'tanimoto',
      'canberra',
      'chebyshev',
      'soergel',
      'kulczynski_d',
      'lorentzian',
      'intersection',
      'wavehedges',
      'czekanowski',
      'motyka',
      'ruzicka',
      'inner_product',
      'harmonic_mean',
      'hassebrook',
      'fidelity',
      'bhattacharyya',
      'hellinger',
      'matusita',
      'squared_chord',
      'squared_euclidean',
      'pearson',
      'neyman',
      'squared_chi',
      'prob_symm',
      'divergence',
      'clark',
      'additive_symm',
      'jeffreys',
      'k_divergence',
      'topsoe',
      'jensen_difference',
      'taneja')

  }


