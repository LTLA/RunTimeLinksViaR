#include "Rcpp.h"
#include "R_ext/Rdynload.h"

extern "C" {

int myCfun (int a, int b) {
    return a + b;
}

void R_init_packA(DllInfo *info) {
    R_RegisterCCallable("packA", "myCfun", (DL_FUNC)myCfun);
}

}
