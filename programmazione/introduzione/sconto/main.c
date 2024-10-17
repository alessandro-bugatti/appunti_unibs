#include <stdio.h>

int main(void){
    float costo_unitario, costo_totale;
    int qta;
    const float SCONTO = 10;
    printf("Inserisci il costo di un articolo: ");
    scanf("%f", &costo_unitario);
    printf("Inserisci il numero degli articoli: ");
    scanf("%d", &qta);
    /* Prima versione con solo if
    costo_totale = costo_unitario * qta;
    if (qta > 10) {
        costo_totale = costo_totale - costo_totale * (SCONTO/100);
    }
    */
    //Seconda versione
    if (qta > 10){
        costo_totale = costo_unitario * qta * (1 - SCONTO/100);
    }
    else{
        costo_totale = costo_unitario * qta;
    }
    printf("Il costo totale è %f", costo_totale);

    return 0;
}
