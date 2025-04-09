#include <Rcpp.h>
using namespace Rcpp;

//' Algorithme Dynamic Programmation using C++
//'
//' @param poids vecteur contenant les poids des objets
//' @param valeurs vecteur contenant les valeurs (numériques) des objets
//' @param poids_max représente le poids maximal autorisé dans le sac
//' @param precision represente la precision
//' @return La solution optimale
//' @export
// [[Rcpp::export]] //mandatory to export the function
List rcpp_sac_a_dos_dp(NumericVector poids, NumericVector valeurs, double poids_max, int precision = 1000) {
  int n = poids.size();
  
  // Convertir poids et capacité en entiers
  IntegerVector poids_entiers(n);
  for (int i = 0; i < n; ++i) {
    poids_entiers[i] = round(poids[i] * precision);
  }
  int W = round(poids_max * precision);
  
  // Initialiser la table DP
  std::vector<std::vector<double>> dp(n + 1, std::vector<double>(W + 1, 0.0));
  
  // Remplir la table
  for (int i = 1; i <= n; ++i) {
    int p = poids_entiers[i - 1];
    double v = valeurs[i - 1];
    for (int w = 0; w <= W; ++w) {
      if (p <= w) {
        dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - p] + v);
      } else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  
  // Reconstruction de la solution
  IntegerVector solution(n, 0);
  int w = W;
  for (int i = n; i >= 1; --i) {
    if (dp[i][w] != dp[i - 1][w]) {
      solution[i - 1] = 1;
      w -= poids_entiers[i - 1];
    }
  }
  
  double valeur_totale = dp[n][W];
  double poids_total = 0.0;
  for (int i = 0; i < n; ++i) {
    if (solution[i]) {
      poids_total += poids[i];
    }
  }
  
  return List::create(
    Named("meilleure_combinaison") = solution,
    Named("poids_total") = poids_total,
    Named("valeur_totale") = valeur_totale
  );
}
