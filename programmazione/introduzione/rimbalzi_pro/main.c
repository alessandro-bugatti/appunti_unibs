#include <stdio.h>

#define LIMITE_RIMBALZO 0.001
#define PERCENTUALE_ELASTICA 0.999

int main(void) {
    float H;
    int numero_rimbalzi = 0; //contatore
    printf("Inserisci l'altezza in metri: ");
    scanf("%f", &H);
    while (H > LIMITE_RIMBALZO) {
        H *= PERCENTUALE_ELASTICA; //H = H * PERCENTUALE_ELASTICA;
        numero_rimbalzi++;
    }
    printf("Il numero di rimbalzi dopo i quali si ferma è %d\n", numero_rimbalzi);
    return 0;
}