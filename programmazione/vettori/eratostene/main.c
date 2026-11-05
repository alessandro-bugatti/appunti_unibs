#include <stdio.h>

#define N 2000

int main(void) {
    int crivello[N];
    //Riempio il vettore con i sassolini
    for (int i = 2; i < N; ++i) {
        crivello[i] = 1;
    }
    //Ciclo esterno per scorrere i numeri primi ed eliminare i loro multipli
    for (int i = 2; i < N / 2; ++i) {
        //COntrollo se il numero attuale è primo
        if (crivello[i] == 1) {
            for (int j = 2 * i; j < N ; j += i) {
                crivello[j] = 0;
            }
        }
    }
    int conta = 1;
    for (int i = 2; i < N; ++i) {
        if (crivello[i] == 1) {
            printf("%5d ", i);
            conta++;
        }
        if (conta % 10 == 0) {
            printf("\n");
            conta = 1;
        }
    }
    return 0;
}
