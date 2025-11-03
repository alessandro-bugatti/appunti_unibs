#include <stdio.h>

int n_cifre(int n) {
    int conta = 0;
    while (n > 0) {
        conta++;
        n = n / 10;
    }
    return conta;
}

//se n = 71234 e p = 2 allora ritorna 3
int digit(int n, int p) {
    if (p <= 0)
        return -1;
    if (p > n_cifre(n))
        return -1;
    if (n < 0)
        n = -n;
    int cifra;
    for (int i = 1; i <= p; i++) {
        cifra = n % 10;
        n = n / 10;
    }
    return cifra;
}

int main(void) {
    int n = 71204, p = 3;
    int cifra = digit(n , p);
    printf("La cifra in posizione %d di %d è %d\n",
        p, n, digit(n, p));
    return 0;
}