#include <stdio.h>

int main(void) {
    //Dichiarazione
    float base, altezza, area;
    //Input
    printf("Inserisci la base: ");
    scanf("%f", &base);
    printf("Inserisci l'altezza: ");
    scanf("%f", &altezza);
    //elaborazione
    area = base * altezza;
    //output
    printf("L'area è %f", area);

    return 0;
}