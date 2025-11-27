#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x;
    float y;
} Punto2D; //Nuovo tipo di dato

typedef struct
{
    Punto2D a;
    Punto2D b;
}Segmento;

float lunghezza(Segmento s) {
    float dx = abs(s.a.x - s.b.x);
    float dy = abs(s.a.y - s.b.y);
    return sqrt(dx*dx + dy*dy);
}

int main(void) {
    Punto2D p1, p2;
    p1.x = 3.3;
    printf("Inserisci la y del punto: ");
    scanf("%f", &p1.y);
    p2 = p1; //L'assegnamento funziona perchè non è altro che una copia in memoria
    //Cosa non funziona
    //Gli operatori matematici
    //p1 = p1 + p2; SBAGLIATO
    //Gli operatori di confronto
    //if (p1 < p2) SBAGLIATO

    printf("P2 : (%f, %f)\n", p2.x, p2.y);
    p2.x += 2.3;
    p2.y += 5;
    //Utilizzo di strutture annidate
    Segmento s;
    s.a = p1;
    s.b = p2;
    printf("La lunghezza del segmento è %f", lunghezza(s));
    return 0;
}