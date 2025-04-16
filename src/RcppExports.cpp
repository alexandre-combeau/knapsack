// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// rcpp_hello_world
List rcpp_hello_world();
RcppExport SEXP _knapsack_rcpp_hello_world() {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    rcpp_result_gen = Rcpp::wrap(rcpp_hello_world());
    return rcpp_result_gen;
END_RCPP
}
// rcpp_sac_a_dos
List rcpp_sac_a_dos(NumericVector poids, NumericVector valeurs, double poids_max);
RcppExport SEXP _knapsack_rcpp_sac_a_dos(SEXP poidsSEXP, SEXP valeursSEXP, SEXP poids_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type poids(poidsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type valeurs(valeursSEXP);
    Rcpp::traits::input_parameter< double >::type poids_max(poids_maxSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_sac_a_dos(poids, valeurs, poids_max));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_sac_a_dos_dp
List rcpp_sac_a_dos_dp(NumericVector poids, NumericVector valeurs, int poids_max);
RcppExport SEXP _knapsack_rcpp_sac_a_dos_dp(SEXP poidsSEXP, SEXP valeursSEXP, SEXP poids_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type poids(poidsSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type valeurs(valeursSEXP);
    Rcpp::traits::input_parameter< int >::type poids_max(poids_maxSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_sac_a_dos_dp(poids, valeurs, poids_max));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_sac_a_dos_glouton
List rcpp_sac_a_dos_glouton(const NumericVector& poids, const NumericVector& valeurs, const double poids_max);
RcppExport SEXP _knapsack_rcpp_sac_a_dos_glouton(SEXP poidsSEXP, SEXP valeursSEXP, SEXP poids_maxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const NumericVector& >::type poids(poidsSEXP);
    Rcpp::traits::input_parameter< const NumericVector& >::type valeurs(valeursSEXP);
    Rcpp::traits::input_parameter< const double >::type poids_max(poids_maxSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_sac_a_dos_glouton(poids, valeurs, poids_max));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_knapsack_rcpp_hello_world", (DL_FUNC) &_knapsack_rcpp_hello_world, 0},
    {"_knapsack_rcpp_sac_a_dos", (DL_FUNC) &_knapsack_rcpp_sac_a_dos, 3},
    {"_knapsack_rcpp_sac_a_dos_dp", (DL_FUNC) &_knapsack_rcpp_sac_a_dos_dp, 3},
    {"_knapsack_rcpp_sac_a_dos_glouton", (DL_FUNC) &_knapsack_rcpp_sac_a_dos_glouton, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_knapsack(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
