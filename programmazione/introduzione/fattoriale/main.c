#include <stdio.h>

int main(void) {
    int N, fattoriale = 1;
    printf("Inserisci un numero intero >= 0: ");
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        fattoriale *= i;
    }
    printf("%d! = %d\n", N, fattoriale);
    return 0;
}
