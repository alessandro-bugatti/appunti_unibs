#include <stdio.h>
#include <math.h>

#define MAX_LATI 20

typedef struct{
    float x;
    float y;
} Punto;

typedef struct
{
    Punto a;
    Punto b;
    Punto c;
} Triangolo;

typedef struct
{
    Punto vertici[5];
} Pentagono;

typedef struct
{
    Punto vertici[MAX_LATI];
    int n_vertici;
} Poligono;

float distanza(Punto a, Punto b) {
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx*dx + dy*dy);
}

float perimetro(Triangolo t) {
    return distanza(t.a, t.b) + distanza(t.b, t.c)
        + distanza(t.c, t.a);
}

float perimetro_poligono(Poligono p) {
    float risultato = 0;
    for (int i = 0; i < p.n_vertici - 1; ++i) {
        risultato += distanza(p.vertici[i], p.vertici[i + 1]);
    }
    return risultato +
        distanza(p.vertici[0], p.vertici[p.n_vertici - 1]);
}

int main(void) {
    /*struct{
        float x;
        float y;
    } p, r;*/
    Punto p, r;
    printf("Inserisci la x e la y di un punto: ");
    scanf("%f", &p.x);
    scanf("%f", &p.y);
    printf("(%f, %f)\n", p.x, p.y);
    r = p;
    float risultato = distanza(p, r);
    printf("Distanza: %f", risultato);
    Triangolo t;
    t.a.x = 1;
    t.a.y = 3;
    t.b = p;
    t.c = r;
    Poligono esagono;
    esagono.vertici[0] = p;
    esagono.vertici[1] = r;
    esagono.vertici[2] = p;
    esagono.vertici[3] = p;
    esagono.vertici[4] = p;
    esagono.vertici[5] = p;
    esagono.n_vertici = 6;
    return 0;
}
