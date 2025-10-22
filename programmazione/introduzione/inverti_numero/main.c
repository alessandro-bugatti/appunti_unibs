#include <stdio.h>

int main(void) {
    int N, cifra = 0, numero = 0;
    printf("Inserisci un intero positivo: ");
    scanf("%d", &N);
    while(N > 0) {
        if (N % 10 != 0 || cifra != 0) {
            printf("%d", N % 10);
            cifra = 1;
        }
        numero = numero * 10 + N % 10;
        N /= 10;
    }
    printf("\nUtilizzando il secondo modo: %d\n", numero);
    return 0;
}