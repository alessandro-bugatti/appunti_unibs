#include <stdio.h>

int conta_cifre(int n) {
    int conta = 0;
    while (n > 0) {
        conta++;
        n /= 10;
    }
    return conta;
}

int digit(int n, int k) {
    if (k <= 0) {
        return -1;
    }
    if (k > conta_cifre(n)) {
        return -1;
    }
    int cifra, n_cifre = conta_cifre(n);
    for (int i = 0; i < n_cifre - k + 1; ++i) {
        cifra = n % 10;
        n /= 10;
    }
    return cifra;

}

int main(void) {
    printf("%d\n", conta_cifre(12345));
    printf("%d\n", digit(12345, 3));
    return 0;
}
