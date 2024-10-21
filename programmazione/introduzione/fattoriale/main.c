#include <stdio.h>

int main(void) {
    int N, fattoriale = 1;
    printf("Inserisci N: ");
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        fattoriale = fattoriale * (i + 1);
    }
    printf("Il fattoriale è %d\n", fattoriale);
    return 0;
}
