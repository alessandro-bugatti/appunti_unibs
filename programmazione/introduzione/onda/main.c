#include <stdio.h>

int main(void) {
    float altezza;
    int km = 0;
    printf("Inserisci l'altezza dell'onda: ");
    scanf("%f", &altezza);
    while(altezza > 0.01) {
        altezza = altezza * 0.9; //altezza *= 0.9;
        km++;
    }
    printf("L'onda sparisce dopo %d kilometri.\n", km);
    return 0;
}
