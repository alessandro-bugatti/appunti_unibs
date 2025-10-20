#include <stdio.h>

int main(void) {
    int N, n_asterischi = 1, n_spazi;
    printf("Inserisci il lato del rombo: ");
    scanf("%d", &N);
    n_spazi = N - 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < n_spazi; ++j) {
            printf(" ");
        }
        for (int j = 0; j < n_asterischi; ++j) {
            printf("*");
        }
        printf("\n");
        n_asterischi += 2;
        n_spazi--;
    }
    n_asterischi -= 4;
    n_spazi = 1;
    for (int i = 0; i < N - 1; ++i) {
        for (int j = 0; j < n_spazi; ++j) {
            printf(" ");
        }
        for (int j = 0; j < n_asterischi; ++j) {
            printf("*");
        }
        printf("\n");
        n_asterischi -= 2;
        n_spazi++;
    }
    return 0;
}