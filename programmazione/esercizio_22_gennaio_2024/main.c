#include <stdio.h>

int main(void) {
    int altezza, ripetizioni,
    spazi_prima, spazi_mezzo, spazi_dopo;
    printf("Inserisci altezza:");
    scanf("%d", &altezza);
    printf("Inserisci ripetizioni:");
    scanf("%d", &ripetizioni);
    spazi_mezzo = 0;
    spazi_prima = spazi_dopo = altezza - 1;
    //Per la stampa di ogni riga
    for(int i = 0; i < altezza; ++i) {
        //Per le ripetizioni all'interno della stessa riga
        for(int j = 0; j < ripetizioni; ++j) {
            for(int k = 0; k < spazi_prima; ++k) {
                printf(" ");
            }
            printf("/");
            for(int k = 0; k < spazi_mezzo; ++k) {
                printf(" ");
            }
            printf("\\");
            for(int k = 0; k < spazi_dopo; ++k) {
                printf(" ");
            }
        }
        printf("\n");
        spazi_prima -= 1;
        spazi_dopo--;
        spazi_mezzo += 2;
    }
    return 0;
}
