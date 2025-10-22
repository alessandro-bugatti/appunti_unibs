#include <stdio.h>

int main(void) {
    int N, conta = 0;
    printf("Inserisci un numero intero positivo: ");
    scanf("%d", &N);
    for (int a = 1; a < N; ++a) {
        for (int b = a + 1; b < N; ++b) {
            for (int c = b + 1; c < N; ++c) {
                if (a*a + b*b == c*c) {
                    printf("[%d, %d, %d]\n", a, b, c);
                    conta++;
                }
            }
        }
    }
    printf("Sono state trovate %d terne pitagoriche.\n", conta);
    return 0;
}