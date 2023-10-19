#include <stdio.h>

int main() {
    int N;
    int n_asterischi = 1, n_spazi;
    printf("Inserisci N: ");
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
    //Da completare con la parte sotto del rombo
    return 0;
}
