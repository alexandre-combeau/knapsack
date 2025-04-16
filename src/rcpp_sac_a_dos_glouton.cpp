#include <Rcpp.h>
#include <vector>
#include <algorithm>
using namespace Rcpp;

// Structure représentant un objet avec index, valeur, poids, et ratio
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
List rcpp_sac_a_dos_glouton(const NumericVector& poids,
                                  const NumericVector& valeurs,
                                  const double poids_max) {
  const int n = poids.size();
  std::vector<Objet> objets;
  objets.reserve(n);
  
  // Construction des objets avec ratio valeur/poids
  for (int i = 0; i < n; ++i) {
    double p = poids[i];
    double v = valeurs[i];
    double r = (p > 0.0) ? v / p : 0.0;
    objets.push_back({i, v, p, r});
  }
  
  // Tri décroissant des objets selon leur efficacité (ratio)
  std::sort(objets.begin(), objets.end(), [](const Objet& a, const Objet& b) {
    return a.ratio > b.ratio;
  });
  
  IntegerVector solution(n, 0);
  double poids_total = 0.0;
  double valeur_totale = 0.0;
  
  // Sélection gloutonne des objets
  for (const auto& obj : objets) {
    if (poids_total + obj.poids <= poids_max) {
      solution[obj.index] = 1;
      poids_total += obj.poids;
      valeur_totale += obj.valeur;
    }
  }
  
  // Conversion finale pour renvoi vers R
  return List::create(wrap(solution), poids_total, valeur_totale);
}
