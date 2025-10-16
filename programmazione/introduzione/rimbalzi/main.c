#include <stdio.h>

int main(void) {
    float H;
    int numero_rimbalzi = 0; //contatore
    printf("Inserisci l'altezza in metri: ");
    scanf("%f", &H);
    while (H > 0.001) {
        H = H * 0.99;
        numero_rimbalzi = numero_rimbalzi + 1;
    }
    printf("Il numero di rimbalzi dopo i quali si ferma è %d\n", numero_rimbalzi);
    return 0;
}