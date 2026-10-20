#include <stdio.h>

int main(void) {
    int N, contatore = 0, sbagliato;
    do {
        printf("Inserisci un numero:");
        scanf("%d", &N);
        sbagliato = 0;
        contatore = 0;
        while (N > 0) {
            if (N % 10 == 1) {
                contatore ++;
            }
            if (N % 10 != 0 && N % 10 != 1) {
                printf("Numero inserito sbagliato");
                sbagliato =1;
                break; //Fa uscire dal ciclo in cui ci si trova
            }
            N = N / 10;
        }
        if (sbagliato == 0 && N == 0) {
            if (contatore % 2 == 0)
                printf("Parità pari\n");
            else
                printf("Parità dispari\n");
        }
    } while (N >= 0);
    return 0;
}
