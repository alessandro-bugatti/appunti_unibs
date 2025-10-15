#include <stdio.h>

int main(void) {
    int qta;
    float costo_unitario, totale;
    printf("Inserisci il costo unitario: ");
    scanf("%f", &costo_unitario);
    printf("Inserisci la quantità: ");
    scanf("%d", &qta);
    if (qta > 10) {
        totale = costo_unitario * qta * 0.9;
    }
    else {
        totale = costo_unitario * qta;
    }
    printf("Il costo totale è %f", totale);
    return 0;
}