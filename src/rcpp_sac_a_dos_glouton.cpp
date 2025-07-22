#include <Rcpp.h>
#include <vector>
#include <numeric>   // pour iota
#include <algorithm> // pour sort
#include <iostream>

using namespace Rcpp;

//' Algorithme Glouton using C++
//'
//' @param poids Vecteur contenant les poids des objets
//' @param valeurs Vecteur contenant les valeurs (numériques) des objets
//' @param poids_max Entier représentant le poids maximal autorisé dans le sac
//' @return Une solution... optimale ?
//' @export
// [[Rcpp::export]]
List rcpp_sac_a_dos_glouton(const std::vector<double>& poids,
                            const std::vector<double>& valeurs,
                            const double poids_max) {
  size_t n = poids.size();
  
  // Calcul du ratio valeurs/ poids
  std::vector<double> efficacite(n);
  for (size_t i = 0; i < n; ++i) efficacite[i] = valeurs[i] / poids[i];
  
  // Tri du vecteur efficacite par ordre decroissant
  std::vector<size_t> indices(efficacite.size());
  std::iota(indices.begin(), indices.end(), 0); // indices[i]=i
  
  std::sort(indices.begin(), indices.end(), [&](size_t i, size_t j)
  {
    return efficacite[i] > efficacite[j]; // ordre decroissant
  });
  
  std::vector<double> solution(n, 0.0);
  double poids_total = 0.0;
  double valeur_totale = 0.0;

  for (size_t k = 0; k < n; k++)
  {
    size_t i = indices[k];
    if (poids_total + poids[i] <= poids_max)
    {
      solution[i] = 1;
      poids_total += poids[i];
      valeur_totale += valeurs[i];
    }
  }

  return List::create(
    Named("combinaison_glouton") = solution,
    Named("poids_total") = poids_total,
    Named("valeur_totale") = valeur_totale
  );
}
