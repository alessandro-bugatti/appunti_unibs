#include <stdio.h>

int main() {
    float costo_unitario;
    float costo_totale;
    int n_pezzi;
    printf("Inserisci costo unitario: ");
    scanf("%f", &costo_unitario);

    printf("Inserisci il numero di pezzi: ");
    scanf("%d" , &n_pezzi);

    if(n_pezzi > 10){
        costo_totale = costo_unitario * n_pezzi * 0.9;
    }
    else{
        costo_totale = costo_unitario * n_pezzi;
    }
    printf("Il costo totale è di %f euro", costo_totale);
    return 0;
}
