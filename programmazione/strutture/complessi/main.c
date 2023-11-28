#include <stdio.h>
#include "complessi.h"


int main() {
    Complesso c;
    ComplessoExp ce;
    c.re = 1;
    c.im = 1;
    ce = converti(c);
    stampaComplesso(c);
    stampaEsponenziale(ce);
    return 0;
}
