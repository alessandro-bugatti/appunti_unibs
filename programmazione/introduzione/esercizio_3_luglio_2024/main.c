#include <math.h>
#include <stdio.h>

int main(void) {
    int punto, p1 = 0, p2 = 0;

    while() {
        printf("Inserisci la squadra che ha fatto punto (1-2): ");
        scanf("%d", &punto);
        if (punto == 1) {
            p1++;
        }
        else {
            p2++;
        }
        printf("Punteggio %d - %d\n", p1, p2);
    }
    printf("Punteggio finale %d - %d\n", p1, p2);
    if (p1 > p2) {
        printf("Ha vinto la squadra 1\n");
    }
    else {
        printf("Ha vinto la squadra 2\n");
    }


    return 0;
}
