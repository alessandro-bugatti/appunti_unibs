#include <math.h>
#include <stdio.h>

#define MAX_VERTICI 100
//const int MAX_VERTICI = 100;


typedef struct
{
    float x;
    float y;
} Punto;

typedef struct
{
    Punto vertici[MAX_VERTICI];
    int n_vertici;
} Poligono;

float lunghezza(Punto a, Punto b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

/**
 * Questa funzione utilizza i puntatori perché deve modificare
 * il poligono che le viene passato, e quindi deve essere
 * passato per indirizzo
 * @param p Il puntatore (o l'indirizzo) del poligono da modificare
 * @param dx
 * @param dy
 */
void trasla(Poligono *p, float dx, float dy) {
    for (int i = 0; i < p->n_vertici; ++i) {
        p->vertici[i].x += dx;
        p->vertici[i].y += dy;
    }
}

/**
 * Stampa un poligono, in questo caso il passaggio per
 * indirizzo non è strettamente necessario, poichè il
 * poligono non viene modificato, ma migliora le prestazioni
 * perchè non c'è di mezzo la copia del poligono
 * @param p
 */
void stampa(const Poligono *p) {
    for (int i = 0; i < p->n_vertici; ++i) {
        printf("(%f, %f)\n", p->vertici[i].x, p->vertici[i].y);
    }
}

float perimetro(Poligono p) {
    float somma = 0;
    //Soluzione più elegante
    for (int i = 0; i < p.n_vertici; ++i) {
        somma += lunghezza(p.vertici[i], p.vertici[(i + 1) % p.n_vertici]);
    }
    return somma;
    //Più meccanica
    for (int i = 0; i < p.n_vertici - 1; ++i) {
        somma += lunghezza(p.vertici[i], p.vertici[i + 1]);
    }
    return somma + lunghezza(p.vertici[0], p.vertici[p.n_vertici - 1]);
}

Punto punto_medio(Punto a, Punto b) {
    Punto p;
    p.x = (a.x + b.x) / 2;
    p.y = (a.y + b.y) / 2;
    return p;
}

int main(void) {
    Poligono p;
    printf("Quanti vertici ha questo poligono?");
    scanf("%d", &p.n_vertici);
    for (int i = 0; i < p.n_vertici; ++i) {
        printf("x: ");
        scanf("%f", &p.vertici[i].x );
        printf("y: ");
        scanf("%f", &p.vertici[i].y);
    }
    stampa(&p);
    printf("Il perimetro del poligono è : %f\n", perimetro(p) );
    trasla(&p, 1, 1);
    stampa(&p);

    //Esempio con il punto medio per vedere come funziona il valore di ritorno
    Punto a = {1,3}, b = {7, 13}, c;
    c = punto_medio(a, b);

    return 0;
}