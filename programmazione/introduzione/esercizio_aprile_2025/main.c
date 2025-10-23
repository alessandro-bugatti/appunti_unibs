#include <stdio.h>

int main(void) {
    int ripetizioni, larghezza, altezza;
    printf("Inserisci il numero di ripetizioni: ");
    scanf("%d", &ripetizioni);
    printf("Inserisci la larghezza: ");
    scanf("%d", &larghezza);
    printf("Inserisci l'altezza: ");
    scanf("%d", &altezza);
    //Ciclo esterno per le ripetizioni
    for (int i = 0; i < ripetizioni; ++i) {
        //Prima linea orizzontale
        for (int j = 0; j < larghezza; ++j) {
            printf("-");
        }
        printf("\n");
        //Linea verticale destra
        for (int j = 0; j < altezza; ++j) {
            for (int k = 0; k < larghezza; ++k) {
                printf(" ");
            }
            printf("|\n");
        }
        //Seconda riga orizzontale
        for (int j = 0; j < larghezza; ++j) {
            printf("-");
        }
        printf("\n");
        //Riga verticale sinistra
        for (int j = 0; j < altezza; ++j) {
            printf("|\n");
        }
    }
    return 0;
}