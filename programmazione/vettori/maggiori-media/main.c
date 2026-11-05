#include <stdio.h>

#define N 100

int main(void) {
    float v[N], media = 0;
    int n, conta = 0;
    printf("quanti valori vuoi inserire? ");
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        printf("Inserisci un dato: ");
        scanf("%f", &v[i]);
        media += v[i];
    }
    media /= n;
    for (int i = 0; i < n; i++) {
        if (v[i] > media) {
            conta++;
        }
    }
    printf("I valori maggiori della media sono %d\n", conta);
    for (int i = 0; i < n; ++i) {
        if (v[i] > media) {
            printf("%f\n", v[i]);
        }
    }

    return 0;
}
