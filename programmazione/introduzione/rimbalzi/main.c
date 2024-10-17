#include <stdio.h>

int main(void) {
    float altezza;
    int n_rimbalzi = 0;
    printf("Inserisci l'altezza di partenza in metri: ");
    scanf("%f", &altezza);
    while(altezza > 0.001) {
        altezza *= 0.99; //altezza = altezza * 0.99;
        n_rimbalzi++; //n_rimbalzi = n_rimbalzi + 1;
    }
    printf("Il numero di rimbalzi sarà %d\n", n_rimbalzi);
    return 0;
}
