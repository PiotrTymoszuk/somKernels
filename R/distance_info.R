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
      'tanimoto')

  }
