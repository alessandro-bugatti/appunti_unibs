#include <stdio.h>
#include <tgmath.h>

typedef struct {
    float re;
    float im;
} Complesso;

typedef struct {
    float mod;
    float fase;
} ComplessoExp;

ComplessoExp convertiInExp(Complesso c) {
    ComplessoExp ce;
    ce.mod = sqrt(c.re * c.re + c.im * c.im);
    ce.fase = atan2f(c.im, c.re);
    return ce;
}

Complesso convertiInComplesso(ComplessoExp ce) {
    Complesso c;
    c.re = ce.mod * cos(ce.fase);
    c.im = ce.mod * sin(ce.fase);
    return c;
}

void stampa(Complesso c) {
    if (c.re == 0 && c.im == 0) {
        printf("0");
    }
    else if (c.re == 0) {
        if (c.im > 0) {
            printf("i%f\n", c.im);
        }
        else {
            printf("-i%f\n", -c.im);
        }
    }//Da finire le altre situazioni
    else {
        printf("%f + %fi\n", c.re, c.im);
    }
}

void stampaExp(ComplessoExp ce) {
    printf("mod: %f fase: %f\n", ce.mod, ce.fase);
}

Complesso somma(Complesso a, Complesso b) {
    Complesso c;
    c.re = a.re + b.re;
    c.im = a.im + b.im;
    return c;
}

Complesso differenza(Complesso a, Complesso b) {
    b.re = -b.re;
    b.im = -b.im;
    return somma(a, b);
}

Complesso prodotto(Complesso a, Complesso b) {
    Complesso c;
    c.re = a.re * b.re - a.im * b.im;
    c.im = a.re * b.im + a.im * b.re;
    return c;
}

Complesso rapporto(Complesso a, Complesso b) {
    Complesso c;
    float den = b.re * b.re + b.im * b.im;
    c.re = (a.re * b.re + a.im * b.im)/den;
    c.im = (b.re * a.im - a.re * b.im)/den;
    return c;
}


int main(void) {
    Complesso c = {2, 2}, d = {1, 3};
    ComplessoExp ce;
    ce = convertiInExp(c);
    stampa(c);
    stampaExp(ce);
    Complesso s = somma(c, d);
    stampa(s);
    s = differenza(c, d);

    return 0;
}