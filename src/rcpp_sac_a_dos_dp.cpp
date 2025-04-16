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
    for (int w = 1; w <= W; ++w) {
      if (p <= w) {
        dp[i][w] = std::max(dp[i - 1][w], valeurs[i - 1] + dp[i - 1][w - p]);
      }
      else {
        dp[i][w] = dp[i - 1][w];
      }
    }
  }
  
  // Backtracking pour retrouver les objets choisis et calcul du poids total obtenu
  int w = W;
  IntegerVector solution(n, 0);
  double poids_total = 0.0;
  for (int i = n; i >= 1; --i) {
    if (dp[i][w] != dp[i - 1][w]) {
      solution[i - 1] = 1;
      poids_total += poids[i - 1];
      w -= static_cast<int>(poids[i - 1]);
    }
  }
  
  return List::create(solution, poids_total, dp[n][W]);
}

