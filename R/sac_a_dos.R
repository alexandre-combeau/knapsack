##  GPL-3 License
## Copyright (c) 2025 Alexandre Combeau

#' Sac a dos : Algorithme Brut Force
#'
#' @description Algorithme naif testant toutes les combinaisons possibles
#' @param poids vecteur contenant les poids des objets
#' @param valeurs vecteur contenant les valeurs (numériques) des objets
#' @param poids_max représente le poids maximal autorisé dans le sac
#' @return La solution optimale
#' @export
sac_a_dos <- function(poids, valeurs, poids_max) {
  if (length(poids) != length(valeurs)) {
    stop("Les longueurs de 'poids' et 'valeurs' sont differentes.")
  }
  
  n <- length(poids)
  meilleure_valeur <- 0
  meilleure_combinaison <- rep(0, n)
  
  for (i in 0:(2^n - 1)) {
    combinaison <- as.integer(intToBits(i))[1:n]
    poids_total <- sum(poids * combinaison)
    valeur_totale <- sum(valeurs * combinaison)
    if (poids_total <= poids_max && valeur_totale > meilleure_valeur) {
      meilleure_valeur <- valeur_totale
      meilleure_combinaison <- combinaison
    }
  }
  
  return(list(sol_opti = meilleure_combinaison,
              poids_total = sum(poids * meilleure_combinaison),
              valeur_totale = meilleure_valeur))
}