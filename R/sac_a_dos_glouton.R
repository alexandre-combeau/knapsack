##  GPL-3 License
## Copyright (c) 2025 Alexandre Combeau

#' Sac a dos : Algorithme Glouton
#'
#' @description Algorithme prenant le meilleur rapport valeur/poids
#' @param poids vecteur contenant les poids des objets
#' @param valeurs vecteur contenant les valeurs (numériques) des objets
#' @param poids_max représente le poids maximal autorisé dans le sac
#' @return Une solution... optimale ?
#' @export
sac_a_dos_glouton <- function(poids, valeurs, poids_max) {
  
  efficacite <- valeurs / poids
  indices <- order(efficacite, decreasing = TRUE)
  
  poids_total <- 0
  valeur_totale <- 0
  solution <- rep(0,length(poids))
  
  for (i in indices) {
    if (poids_total + poids[i] <= poids_max) {
      solution[i] <- 1
      poids_total <- poids_total + poids[i]
      valeur_totale <- valeur_totale + valeurs[i]
    }
  }
  
  return(list(combinaison_glouton = solution,
              poids_total = poids_total,
              valeur_totale = valeur_totale))
}
