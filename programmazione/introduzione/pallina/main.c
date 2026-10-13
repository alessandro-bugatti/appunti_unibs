#include <stdio.h>
int main(void) {
    float H;
    int n_rimbalzi = 0;
    printf("Inserisci l'altezza in metri: ");
    scanf("%f", &H);
    while (H > 0.001) {
        n_rimbalzi++; //rimbalzi = rimbalzi + 1;
        H = H * 0.99;
    }
    printf("Il numero di rimbalzi effettuati prima di fermarsi è %d\n",
        n_rimbalzi);
    return 0;
}
