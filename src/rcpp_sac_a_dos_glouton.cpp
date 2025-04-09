#include <Rcpp.h>
using namespace Rcpp;


// Structure pour représenter un objet avec son index
struct Objet {
  int index;
  double valeur;
  double poids;
  double ratio;
};

//' Algorithme Glouton using C++
//'
//' @param poids vecteur contenant les poids des objets
//' @param valeurs vecteur contenant les valeurs (numériques) des objets
//' @param poids_max représente le poids maximal autorisé dans le sac
//' @return Une solution... optimale ?
//' @export
// [[Rcpp::export]] //mandatory to export the function
List rcpp_sac_a_dos_glouton(NumericVector poids, NumericVector valeurs, double poids_max) {
  int n = poids.size();
  std::vector<Objet> objets(n);
  
  for (int i = 0; i < n; ++i) {
    objets[i] = {i, valeurs[i], poids[i], valeurs[i] / poids[i]};
  }
  
  // Tri décroissant selon valeur/poids
  std::sort(objets.begin(), objets.end(), [](const Objet& a, const Objet& b) {
    return a.ratio > b.ratio;
  });
  
  NumericVector solution(n, 0.0);
  double poids_total = 0.0;
  double valeur_totale = 0.0;
  
  for (const auto& obj : objets) {
    if (poids_total + obj.poids <= poids_max) {
      solution[obj.index] = 1.0;
      poids_total += obj.poids;
      valeur_totale += obj.valeur;
    }
  }
  
  return List::create(
    Named("meilleure_combinaison") = solution,
    Named("poids_total") = poids_total,
    Named("valeur_totale") = valeur_totale
  );
}
