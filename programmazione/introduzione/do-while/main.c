#include <stdio.h>

int main(void) {
    int scelta;
    float H;
    int n_rimbalzi;
    do {
        n_rimbalzi = 0;
        printf("Inserisci l'altezza in metri: ");
        scanf("%f", &H);
        while (H > 0.001) {
            n_rimbalzi++; //rimbalzi = rimbalzi + 1;
            H = H * 0.99;
        }
        printf("Il numero di rimbalzi effettuati prima di fermarsi è %d\n",
            n_rimbalzi);
        printf("Vuoi ripetere il programma (1- SI, 2 - NO)?");
        scanf("%d", &scelta);
    }while (scelta == 1);
    return 0;
}
