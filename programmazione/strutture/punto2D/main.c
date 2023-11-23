#include <stdio.h>

typedef struct {
    float x;
    float y;
}Punto2D;

typedef struct{
    Punto2D a;
    Punto2D b;
    Punto2D c;
} Triangolo;

typedef struct {
    Punto2D vertici[100];
    int n_vertici;
} Poligono;

Punto2D punto_medio(Punto2D a, Punto2D b){
    Punto2D risultato;
    risultato.x = (a.x + b.x)/2;
    risultato.y = (a.y + b.y)/2;
    return risultato;
}

int main() {
    Punto2D a, b, c;
    //Assegnamento
    a.x = 10.7;
    a.y = 8.56;
    //Input dell'utente
    printf("Inserisci la x: ");
    scanf("%f", &b.x);
    printf("Inserisci la y: ");
    scanf("%f", &b.y);
    //Output
    printf("(%f , %f)\n", b.x, b.y);
    //Copia
    c = b;
    //a = b + c; non sono definite le operazioni matematiche
    //if (a < b) non sono definite le operazioni di confronto
    c = punto_medio(a,b);

    Triangolo t;
    t.a.x = 0;

    Poligono p;
    p.vertici[0].x = 9;

    return 0;
}
