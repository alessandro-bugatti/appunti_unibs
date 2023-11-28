//
// Created by alex on 28/11/2023.
//

#ifndef COMPLESSI_COMPLESSI_H
#define COMPLESSI_COMPLESSI_H

typedef struct {
    float re;
    float im;
} Complesso;

typedef struct {
    float modulo;
    float fase;
} ComplessoExp;

ComplessoExp converti(Complesso c);

Complesso convertiExp(ComplessoExp ce);

void stampaComplesso(Complesso c);

void stampaEsponenziale(ComplessoExp ce);

Complesso somma(Complesso a, Complesso b);

Complesso differenza(Complesso a, Complesso b);

Complesso prodotto(Complesso a, Complesso b);
#endif //COMPLESSI_COMPLESSI_H
