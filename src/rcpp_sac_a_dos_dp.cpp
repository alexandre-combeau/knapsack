#include <Rcpp.h>
using namespace Rcpp;

//' Algorithme Dynamic Programmation using C++
//'
//' @param poids vecteur contenant les poids des objets
//' @param valeurs vecteur contenant les valeurs (numériques) des objets
//' @param poids_max représente le poids maximal autorisé dans le sac
//' @return La solution optimale
//' @export
// [[Rcpp::export]] //mandatory to export the function
List rcpp_sac_a_dos_dp(NumericVector poids, NumericVector valeurs, int poids_max) {
  int n = poids.size();
  int W = poids_max;
  
  // Initialisation de la matrice DP
  std::vector<std::vector<double>> dp(n + 1, std::vector<double>(W + 1, 0.0));
  
  // Remplissage de DP
  for (int i = 1; i <= n; ++i) {
    int p = static_cast<int>(poids[i - 1]); // On suppose que les poids sont entiers
    double v = valeurs[i - 1];
    for (int w = 0; w <= W; ++w) {
      if (p <= w) {
        dp[i][w] = std::max(dp[i - 1][w], dp[i - 1][w - p] + v);
      }
      else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  
  // Reconstruction de la solution optimale
  IntegerVector solution(n, 0);
  int w = W;
  for (int i = n; i >= 1; --i) {
    if (dp[i][w] != dp[i - 1][w]) {
      solution[i - 1] = 1;
      w -= static_cast<int>(poids[i - 1]);
    }
  }
  
  // Calcul du poids total réel
  double poids_total = 0.0;
  for (int i = 0; i < n; ++i) {
    if (solution[i]) {
      poids_total += poids[i];
    }
  }
  
  return List::create(
    Named("meilleure_combinaison") = solution,
    Named("poids_total") = poids_total,
    Named("valeur_totale") = dp[n][W]
  );
}

