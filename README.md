# Knapsack Problem – Problème du sac à dos 
Auteurs : Alexandre Combeau, Mohtadi Hammami, Ninette Hounkponou

Ce projet a été réalisé dans le cadre du cours d’algorithmique de M2DS.

Nous étudions ici le **problème classique du sac à dos**, en proposant **trois approches algorithmiques différentes**, implémentées à la fois en **C++** et en **R** dans le but de comparer leur **efficacité computationnelle selon le langage** utilisé.

---

##  Objectifs

- Implémenter plusieurs stratégies pour résoudre le problème du sac à dos :
  - méthode **naive / brut force** (parcours exhaustif)
  - méthode **gloutonne** (heuristique)
  - méthode par **programmation dynamique** (optimisation)
- Comparer les **temps d'exécution** selon la **taille des données** et le **langage** utilisé (C++ vs R)
- Observer les compromis entre **temps de calcul**, **qualité de la solution**, et **complexité algorithmique**

---

## Quick Start
### Pour développer et utiliser le paquet, installez les dépendances nécessaires :

```install.packages(c("Rcpp", "RcppArmadillo", "devtools", "roxygen2", "testthat"))```

**NB : Il faut que vous ayez la dernière version de Rcpp**

### Pour installer le package depuis GitHub, exécutez l'une des deux commandes ci-dessous

```devtools::install_github("Perseverantiah/Projet_algoritmique")```

```devtools::install_github("alexandre-combeau/knapsack")```

### Pour pouvoir l'utiliser :

```library(knapsack)```

## [Exemples ](#-exemples)
### [Algorithme Brut Force](#-algo)

```{r BRUT_FORCE}
poids     <- c(18, 7, 14, 4, 11, 17, 12, 10, 3, 6, 15, 16, 2, 5, 20)
valeurs   <- c(31, 38, 4, 6, 16, 7, 2, 50, 3, 10, 13, 29, 12, 8, 43)
poids_max <- 90
sac_a_dos(poids, valeurs, poids_max)
```

```
$combinaison
 [1] 1 1 0 0 1 0 0 1 0 1 0 1 1 0 1

$poids_total
[1] 90

$valeur_totale
[1] 229
```

![Execution_Time_Brut_Force](https://github.com/user-attachments/assets/c7af7f08-61a6-49aa-978b-49138eb45f10)
![Benchmark_Brut_Force](https://github.com/user-attachments/assets/23c9d5b2-d842-4ab3-8456-67027899e8ec)

### [Algorithme glouton](#glouton)

```{r GLOUTON}
n <- 1000000
poids     <- runif(n)
valeurs   <- runif(n)
poids_max <- 10000
sac_a_dos_glouton(poids, valeurs, poids_max)
```

```
$combinaison_glouton
   [1] 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  [37] 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1
  [73] 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 [109] 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 [145] 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1
 [181] 1 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
 [217] 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 [253] 0 0 0 0 1 1 0 0 0 0 1 0 1 0 1 0 0 0 1 0 0 0 0 0 0 0 1 0 1 0 1 0 0 1 0 0
 [289] 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 1 1 0 1
 [325] 0 1 0 1 0 1 0 0 1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0 0 0 1 0 1 0 0 0
 [361] 1 0 1 0 0 0 0 0 0 0 0 0 1 0 1 0 1 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0
 [397] 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
 [433] 0 0 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0 0 0 1 0 0 1 0 0 0 0 0
 [469] 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 0 0 0 0 1
 [505] 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0
 [541] 0 0 0 0 1 0 0 0 0 0 1 0 0 0 1 1 0 0 0 1 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 0
 [577] 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 [613] 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 1 0 0 1 0 1 0 0 0 0 1 1 1 0 0 0 0 0 0 0 0
 [649] 1 0 0 0 0 0 1 0 0 0 0 1 0 0 1 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
 [685] 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0
 [721] 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 [757] 0 0 1 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
 [793] 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0
 [829] 0 0 0 0 0 1 1 0 0 0 0 0 0 1 0 1 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 1
 [865] 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0
 [901] 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0
 [937] 0 0 0 0 0 0 0 0 0 1 0 1 0 0 0 0 1 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1
 [973] 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 1 1 1 0 0 1 0 0 0 0 0 0 0
 [ reached getOption("max.print") -- omitted 999000 entries ]

$poids_total
[1] 10000

$valeur_totale
[1] 81756.37
```

![Execution_Time_Glouton](https://github.com/user-attachments/assets/cfc297f7-ca78-499e-9a63-61abb88fddaf)
![Benchmark_Glouton](https://github.com/user-attachments/assets/e9fa16f2-3780-42ca-8150-7080012d247f)

### [Programmation Dynamique](#dyn)

```{r}
set.seed(42)
n = 100000
poids <- sample(n)
valeur <- sample(n)
poids_max <- 20
sac_a_dos_dp(poids, valeur, poids_max)

```
<img width="593" alt="Screenshot 2025-04-11 073227" src="https://github.com/user-attachments/assets/c7eec800-3290-466b-aeeb-d4f0f028cee3" />
