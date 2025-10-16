#include <stdio.h>

int main(void) {
    int n_termini;
    double pi_greco = 0;
    int numeratore = 1;
    printf("Inserisci il numero di termini a cui sei interessato: ");
    scanf("%d", &n_termini);
    for (int n = 0; n < n_termini; ++n) {
        double nuovo_termine;
        nuovo_termine = (double)numeratore / (2 * n + 1);
        numeratore *= -1;
        pi_greco += nuovo_termine;
    }
    printf("Il valore del pi greco approssimato ai primi %d termini è %lf\n", n_termini, pi_greco * 4);
    return 0;
}