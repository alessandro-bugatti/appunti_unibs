#include <stdio.h>

#define MAX 100
//const int MAX = 100;

int main(void) {
    int v[MAX];
    int N; //numero effettivo di valori
    printf("QUanti valori vuoi inserire? ");
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        printf("INserisci un valore: ");
        scanf("%d", &v[i]);
    }
    //ciclo per la stampa dei pari
    for (int i = 0; i < N; ++i) {
        if (v[i] % 2 == 0 ) {
            printf("%d\n", v[i]);
        }
    }
    //ciclo per la stampa dei numeri dispari
    for (int i = 0; i < N; ++i) {
        if (v[i] % 2 != 0) {
            printf("%d\n", v[i]);
        }
    }
    //Versione alternativa con la copia in due vettori
    //distinti, più difficile
    int pari[MAX], dispari[MAX];
    int ip = 0, id = 0; //indici per l'inserimento nei due vettori
    for (int i = 0; i < N; ++i) {
        if (v[i] % 2 == 0) {
            pari[ip] = v[i];
            ip++;
        } else {
          dispari[id] = v[i];
            id++;
        }
    }
    for (int i = 0; i < ip; ++i) {
        printf("%d\n", pari[i]);
    }
    for (int i = 0; i < id; ++i) {
        printf("%d\n", dispari[i]);
    }

    return 0;
}