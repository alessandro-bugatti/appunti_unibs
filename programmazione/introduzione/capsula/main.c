#include <ctype.h>
#include <stdio.h>

int main(void) {
    int N, spazi_iniziali, spazi_centrali = 1;
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &N);
    spazi_iniziali = N - 1;
    for (int i = 0; i < N; ++i) {
        printf(" ");
    }
    printf("_\n");
    //for esterno per la stampa delle prime N righe
    for (int i = 0; i < N; ++i) {
        //for interno per la stampa della singola riga
        for (int j = 0; j < spazi_iniziali; ++j) {
            printf(" ");
        }
        printf("/");
        for (int j = 0; j < spazi_centrali; ++j) {
            printf(" ");
        }
        printf("\\\n");
        spazi_iniziali--;
        spazi_centrali += 2;
    }
    spazi_centrali -= 2;
    //Disegno della parte centrale
    for (int i = 0; i < N; ++i) {
        printf("|");
        for (int j = 0; j < spazi_centrali; ++j) {
            printf(" ");
        }
        printf("|\n");
    }
    //disegno della parte finale
    spazi_iniziali = 0;
    for (int i = 0; i < N; ++i) {
        //for interno per la stampa della singola riga
        for (int j = 0; j < spazi_iniziali; ++j) {
            printf(" ");
        }
        printf("\\");
        for (int j = 0; j < spazi_centrali; ++j) {
            if (spazi_centrali != 1)
                printf(" ");
            else
                printf("_");
        }
        printf("/\n");
        spazi_iniziali++;
        spazi_centrali -= 2;
    }
    return 0;
}