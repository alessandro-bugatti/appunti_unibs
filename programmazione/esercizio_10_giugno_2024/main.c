#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int segreto, n_giocatori, numero, vincente, numero_vincente, differenza;
    segreto = rand() % 100 + 1;
    printf("Inserisci il numero di giocatori:");
    scanf("%d", &n_giocatori);
    differenza = 1000;
    for (int i = 0; i < n_giocatori; ++i) {
        printf("Giocatore %d inserisci il tuo numero:", i + 1);
        scanf("%d", &numero);
        int distanza = numero - segreto;
        if (distanza < 0) {
            distanza = -distanza;
        }
        if (distanza < differenza) {
            vincente = i + 1;
            differenza = distanza;
            numero_vincente = numero;
        }
    }
    printf("Ha vinto il giocatore %d che ha scelto il %d e il numero da indovinare era %d\n",
        vincente, numero_vincente, segreto);
    return 0;
}
