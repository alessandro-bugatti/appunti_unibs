//
// Created by alex on 28/11/2023.
//

#include <math.h>
#include <stdio.h>
#include "complessi.h"

ComplessoExp converti(Complesso c) {
    ComplessoExp result;
    result.modulo = sqrt(c.re * c.re + c.im * c.im);
    result.fase = atan2f(c.im, c.re);
    return result;
}

Complesso convertiExp(ComplessoExp ce){
    Complesso result;
    result.re = ce.modulo * cos(ce.fase);
    result.im = ce.modulo * sin(ce.fase);
    return result;
}

void stampaComplesso(Complesso c) {
    printf("%.2f + i%.2f\n", c.re, c.im);
}

void stampaEsponenziale(ComplessoExp ce) {
    printf("modulo: %.2f fase: %.2f\n", ce.modulo, ce.fase);
}

Complesso somma(Complesso a, Complesso b){
    Complesso result;
    result.re = a.re + b.re;
    result.im = a.im + b.im;
    return result;
}

Complesso differenza(Complesso a, Complesso b) {
    Complesso result;
    b.re = -b.re;
    b.im = -b.im;
    result = somma(a, b);
    return result;
}

Complesso prodotto(Complesso a, Complesso b) {
    Complesso result;
    ComplessoExp ae = converti(a);
    ComplessoExp be = converti(b);
    ComplessoExp c;
    c.modulo = ae.modulo * be.modulo;
    c.fase = ae.fase + be.fase;
    result = convertiExp(c);
    return result;
}




