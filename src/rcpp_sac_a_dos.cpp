#include <Rcpp.h>
using namespace Rcpp;

//' Algorithme Brut Force using C++
//'
//' @param poids vecteur contenant les poids des objets
//' @param valeurs vecteur contenant les valeurs (numériques) des objets
//' @param poids_max représente le poids maximal autorisé dans le sac
//' @return La solution optimale
//' @export
// [[Rcpp::export]] //mandatory to export the function
List rcpp_sac_a_dos(NumericVector poids, NumericVector valeurs, double poids_max) {
  int n = poids.size();

  double meilleure_valeur = 0.0;
  IntegerVector meilleure_combinaison(n, 0);

  long long total_combinaisons = 1LL << n;

  for (long long i = 0; i < total_combinaisons; ++i) {
    double poids_total = 0.0, valeur_totale = 0.0;
    IntegerVector combinaison(n, 0);

    for (int j = 0; j < n; ++j) {
      if (i & (1LL << j)) {
        combinaison[j] = 1;
        poids_total += poids[j];
        valeur_totale += valeurs[j];
      }
    }

    if (poids_total <= poids_max && valeur_totale > meilleure_valeur) {
      meilleure_valeur = valeur_totale;
      meilleure_combinaison = combinaison;
    }
  }

  double poids_final = 0.0;
  for (int i = 0; i < n; ++i) {
    poids_final += poids[i] * meilleure_combinaison[i];
  }

  return List::create(
    Named("meilleure_combinaison") = meilleure_combinaison,
    Named("poids_total") = poids_final,
    Named("valeur_totale") = meilleure_valeur
  );
}
