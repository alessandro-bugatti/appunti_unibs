#include <iostream>

int main() {
    int N, n_asterischi = 1, n_spazi;
    printf("Inserisci N: ");
    scanf("%d", &N);
    n_spazi = N - 1;
    //Righe della parte superiore del rombo
    for (int i = 0; i < N; ++i) {
        //Stampa gli spazi per spostare gli asterischi nel posto corretto
        for(int j = 0; j < n_spazi; ++j) {
            printf(" ");
        }
        //Stampa degli asterischi di ogni riga
        for(int j = 0; j < n_asterischi; ++j) {
            printf("*");
        }
        printf("\n");
        //Aumentiamo il numero di asterischi per il prossimo giro
        n_asterischi += 2;
        //Diminuiamo il numero di spazi
        n_spazi--;
    }
    n_asterischi -= 4;
    n_spazi = 1;
    //Righe della parte inferiore del rombo
    for (int i = 0; i < N - 1; ++i) {
        //Stampa gli spazi per spostare gli asterischi nel posto corretto
        for(int j = 0; j < n_spazi; ++j) {
            printf(" ");
        }
        //Stampa degli asterischi di ogni riga
        for(int j = 0; j < n_asterischi; ++j) {
            printf("*");
        }
        printf("\n");
        //Aumentiamo il numero di asterischi per il prossimo giro
        n_asterischi -= 2;
        //Diminuiamo il numero di spazi
        n_spazi++;
    }
    return 0;
}
