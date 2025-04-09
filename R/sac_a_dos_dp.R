##  GPL-3 License
## Copyright (c) 2025 Alexandre Combeau

#' Sac a dos Prog Dyn
#'
#' @description Algorithme Programmation Dynamique
#' @param poids vecteur de poids
#' @param valeurs vecteur des valeurs
#' @param poids_max représente le poids maximal autorisé
#' @return Une solution optimale ?
#' @export
sac_a_dos_dp <- function(poids, valeurs, poids_max) {
  if (length(poids) != length(valeurs)) {
    stop("Les longueurs de poids et valeurs doivent etre egales.")
  }
  
  n <- length(poids)
  W <- as.integer(poids_max)
  
  # Initialiser la matrice DP : (n+1) lignes, (W+1) colonnes
  dp <- matrix(0, nrow = n + 1, ncol = W + 1)
  
  for (i in 1:n) {
    for (w in 0:W) {
      if (poids[i] <= w) {
        # Choix : prendre ou ne pas prendre l objet i
        dp[i + 1, w + 1] <- max(dp[i, w + 1],
                                dp[i, w - poids[i] + 1] + valeurs[i])
      } else {
        # Pas assez de place, donc on garde la solution sans l objet i
        dp[i + 1, w + 1] <- dp[i, w + 1]
      }
    }
  }
  
  # Backtracking pour retrouver les objets choisis
  w <- W
  solution <- rep(0,n)
  for (i in n:1) {
    if (dp[i + 1, w + 1] != dp[i, w + 1]) {
      solution[i] <- 1
      w <- w - poids[i]
    }
  }
  
  return(list(
    valeur_totale = dp[n + 1, W + 1],
    meilleure_combinaison = solution
  ))
}
