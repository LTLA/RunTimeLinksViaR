#include "Rcpp.h"
#include "R_ext/Rdynload.h"

extern "C" {

SEXP runner(SEXP a, SEXP b) {
    BEGIN_RCPP
    Rcpp::IntegerVector A(a), B(b);

    Rcpp::Environment thingy(Rcpp::Environment::namespace_env("packA"));
    Rcpp::Function found=thingy["blah"];

    int(*myCfun)(int, int);
    myCfun=(int(*)(int, int))R_GetCCallable("packA", "myCfun");

    return Rcpp::IntegerVector::create(myCfun(A[0], B[0]));
    END_RCPP
}

}


