#include <stdio.h>

#define N 100

int main(void) {
    float numeri[N], media, somma = 0;
    int n_valori, quanti = 0;
    printf("Quanti numeri vuoi inserire (<=100):");
    scanf("%d", &n_valori);
    for (int i = 0; i < n_valori; ++i) {
        printf("Inserisci un numero: ");
        scanf("%f", &numeri[i]);
        somma += numeri[i];
    }
    media = somma / n_valori;
    for (int i = 0; i < n_valori; ++i) {
        if (numeri[i] > media) {
            quanti++;
        }
    }
    printf("I valori maggiori della media sono: %d\n",
            quanti);
    printf("Questi valori sono:\n");
    for(int i = 0; i < n_valori; ++i) {
        if (numeri[i] > media) {
            printf("%f\n", numeri[i]);
        }
    }
    return 0;
}
