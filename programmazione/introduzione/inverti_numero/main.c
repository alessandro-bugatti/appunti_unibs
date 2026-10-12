#include <stdio.h>

int main(void) {
    int N, inverso = 0;
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &N);
    /* Prima versione con stampa immediata, ha il problema
     * degli zeri iniziali
    while (N > 0) {
        int cifra = N % 10;
        printf("%d", cifra);
        N = N / 10; // N /= 10;
    }
    */
    while (N > 0) {
        //Estrai la cifra meno significativa di N
        int cifra = N % 10;
        //Creo spazio nelle unità per aggiungere l'ultima cifra estratta
        inverso = inverso * 10 + cifra;
        //Rimuove la cifra meno significativa di N
        N /= 10;
    }
    printf("%d\n", inverso);


    return 0;
}
