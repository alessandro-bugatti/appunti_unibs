#include <stdio.h>

int main(void) {
    int N;
    printf("Inserisci il lato del quadrato: ");
    scanf("%d", &N);
    //Stampa N linea ognuna composta da N asterischi
    for (int i = 0; i < N; ++i) {
        //Stampa una singola linea con N asterischi
        for (int j = 0; j < N; ++j) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
