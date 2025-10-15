#include <stdio.h>

int main(void) {
    //Dichiarazione
    float base, altezza, area, perimetro;
    //Input
    printf("Inserisci la base: ");
    scanf("%f", &base);
    printf("Inserisci l'altezza: ");
    scanf("%f", &altezza);
    //elaborazione
    perimetro = (base + altezza) * 2;
    area = base * altezza;
    //output
    printf("L'area è %f e il perimetro è %f",
        area, perimetro);

    return 0;
}