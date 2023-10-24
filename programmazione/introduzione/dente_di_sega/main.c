#include <stdio.h>


int main() {
   int A = 3, N = 5;
   int prima = A - 1;
   int dentro = 0;

    for (int i = 0; i < A; ++i) {
        //Stampa del singolo "piano" del triangolo
        for (int k = 0; k < N; ++k) {
            for (int j = 0; j < prima; ++j) {
                printf(" ");
            }
            printf("/");
            for (int j = 0; j < dentro; ++j) {
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
        prima--;
        dentro++;
    }
   return 0;
}
