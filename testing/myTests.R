##### Quelques tests #####
## Charger un des deux Github
devtools::install_github("Perseverantiah/Projet_algoritmique")
devtools::install_github("alexandre-combeau/knapsack")

## Charger le package
library(knapsack)


## Algorithme Brut Force

n <- 20
poids <- runif(n)
valeurs <- runif(n)
poids_max <- 10
sac_a_dos(poids, valeurs, poids_max)
rcpp_sac_a_dos(poids, valeurs, poids_max)

## Algorithme Glouton

n <- 1000000
poids <- runif(n)
valeurs <- runif(n)
poids_max <- 500
sac_a_dos_glouton(poids, valeurs, poids_max)
rcpp_sac_a_dos_glouton(poids, valeurs, poids_max)

## Algorithme Programmation Dynamique

n <- 100000
poids <- runif(n)
valeurs <- runif(n)
poids_max <- 5000
sac_a_dos_dp(poids, valeurs, poids_max)
rcpp_sac_a_dos_dp(poids, valeurs, poids_max)

