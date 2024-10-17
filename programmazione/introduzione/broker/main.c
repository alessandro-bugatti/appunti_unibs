#include <stdio.h>

int main(void) {
    float importo, commissione;
    printf("Inserisci l'importo della transazione: ");
    scanf("%f", &importo);
    if (importo < 2500) {
        commissione = 30 + importo * 0.017;
    }else if (importo < 6250) {
        commissione = 56 + importo * 0.0066;
    }else if (importo < 20000) {
        commissione = 76 + importo * 0.0034;
    }
    else {
        commissione = 100 + importo * 0.0022;
    }

    if (commissione >= 39) {
        commissione = 39;
    }

    printf("La commissione dovuta al broker è di %f euro.", commissione);
    return 0;
}
