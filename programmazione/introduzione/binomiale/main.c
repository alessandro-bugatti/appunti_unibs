#include <stdio.h>

int main(void) {
    int n, k, f_n = 1, f_k = 1, f_n_k = 1, fattoriale = 1;
    printf("Inserisci n: ");
    scanf("%d", &n);
    printf("Inserisci k: ");
    scanf("%d", &k);
    for (int i = 1; i <= n; ++i) {
        f_n = f_n * i;
    }
    for (int i = 1; i <= k; ++i) {
        f_k = f_k * i;
    }
    for (int i = 1; i <= n - k; ++i) {
        f_n_k = f_n_k * i;
    }
    int coeff = f_n / (f_k * f_n_k);
    printf("Il binomiale di %d su %d vale %d\n", n, k,
        coeff);
    for (int i = 1; i <= n; ++i) {
        fattoriale = fattoriale * i;
        if (i == n) {
            f_n = fattoriale;
        }
        if (i == k) {
            f_k = fattoriale;
        }
        if (i == n - k) {
            f_n_k = fattoriale;
        }
    }
    coeff = f_n / (f_k * f_n_k);
    printf("Il binomiale di %d su %d vale %d\n", n, k,
        coeff);
    return 0;
}