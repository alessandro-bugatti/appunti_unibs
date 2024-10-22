#include <iostream>

//Dato un intero positivo N, disegnare una scacchiera con
// N x N caselle in questo modo
// N = 6
/* x x x
 *  x x x
 * x x x
 *  x x x
 * x x x
 *  x x x
*/

int main() {
    int N;
    printf("Inserisci N:");
    scanf("%d", &N);

    for (int i = 0; i < N; ++i) {
        printf("\n");
        if (i % 2 == 1)
            printf("-");
        for(int j = 0; j < N/2; ++j) {
            printf("x-");
        }
        if (N % 2 == 1 && i % 2 == 0) {
            printf("x");
        }

    }

    printf("\nSoluzione più adatta\n");

    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
          int casella = 0;
            for (int j = 0; j < N; j++) {
                if (casella == 0) {
                    printf("x");
                    casella = 1;
                }
                else {
                    printf("-");
                    casella = 0;
                }
            }
        }
        else {
            int casella = 0;
            for (int j = 0; j < N; j++) {
                if (casella == 0) {
                    printf("-");
                    casella = 1;
                }
                else {
                    printf("x");
                    casella = 0;
                }

            }


        }
        printf("\n");
    }

    printf("\nSoluzione più compatta\n");

    for (int i = 0; i < N; ++i) {
            int casella = i % 2;
            for (int j = 0; j < N; j++) {
                if (casella == 0) {
                    printf("x");
                    casella = 1;
                }
                else {
                    printf("-");
                    casella = 0;
                }
            }
        printf("\n");
    }


    return 0;
}
