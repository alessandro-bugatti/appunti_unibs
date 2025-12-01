#include <complex>
#include <iostream>
#include <cstdio>
#include <cmath>

typedef struct
{
    float x;
    float y;
} Punto;

typedef struct
{
    Punto a;
    Punto b;
} Segmento;

typedef struct
{
    Punto a;
    Punto b;
    Punto c;
} Triangolo;

float lunghezza(Segmento s) {
    return sqrt((s.a.x - s.b.x) * (s.a.x - s.b.x) +
    (s.a.y - s.b.y) * (s.a.y - s.b.y));
}

float perimetro(Triangolo t) {
    Segmento l1 = {t.a, t.b};
    Segmento l2 = {t.b, t.c};
    Segmento l3 = {t.a, t.c};
    return lunghezza(l1) + lunghezza(l2) + lunghezza(l3);
}

void stampa_punto(Punto p) {
    printf("(%.2f, %.2f)\n", p.x, p.y);
}

void stampa_triangolo(Triangolo t) {
    printf("I vertici del triangolo sono:\n");
    stampa_punto(t.a);
    stampa_punto(t.b);
    stampa_punto(t.c);
}

int main() {
    Punto p = {1.5, 7.3};
    Segmento s = {
        {2, 4},
        {5, -5}
    };
    Triangolo t = {
        {3, 4.5},
        {-1, -1},
        {8, 32}
    };
    printf("Dato il segmento di coordinate P1(%.2f, %.2f) e P2(%.2f, %.2f) la sua lunghezza è %.2f",
        s.a.x, s.a.y, s.b.x, s.b.y, lunghezza(s));
    stampa_triangolo(t);
    printf("Il suo perimetro è : %f\n", perimetro(t));
    return 0;
}