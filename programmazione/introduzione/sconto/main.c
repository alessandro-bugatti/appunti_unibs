#include <stdio.h>

int main(void) {
    float costo_unitario, costo_totale;
    int qta;
    printf("Inserisci il costo unitario: ");
    scanf("%f", &costo_unitario);
    printf("Inserisci la quantità; ");
    scanf("%d", &qta);
    if (qta > 10) {
        costo_totale = costo_unitario * qta * 0.9;
    }
    else {
        costo_totale = costo_unitario * qta;
    }
    printf("Il totale che dovrai pagare è %f\n", costo_totale);
    return 0;
}
