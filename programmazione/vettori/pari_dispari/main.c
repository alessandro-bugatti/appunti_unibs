#include <stdio.h>

#define MAX 100

int main(void) {
    int valori[MAX];
    int N;
    printf("Dimmi quanti valori vuoi inserire : ");
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        printf("Inserisci un valore: ");
        scanf("%d", &valori[i]);
    }
    for (int i = 0; i < N; ++i) {
        if (valori[i] % 2 == 0) {
            printf("%d ", valori[i]);
        }
    }
    printf("\n");
    for (int i = 0; i < N; ++i) {
        if (valori[i] % 2 == 1) {
            printf("%d ", valori[i]);
        }
    }
    return 0;
}
