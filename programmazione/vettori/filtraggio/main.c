#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void) {
    float originale[N], filtrato[N];
    int k = 2;
    for(int i = 0; i < N; i++) {
        originale[i] = (rand()%5000 / 100.0) - 10;
    }
    for(int i = 0; i < N; ++i) {
        float somma = 0;
        int conta = 0;
        for(int j = i - k; j <= i + k ; ++j) {
            if (j >= 0 && j < N){
                somma += originale[j];
                conta++;
            }
        }

        filtrato[i] = somma / conta ;
    }

    for(int i = 0; i < N; ++i) {
        printf("%4.2f %4.2f\n", originale[i], filtrato[i]);
    }


    return 0;
}
