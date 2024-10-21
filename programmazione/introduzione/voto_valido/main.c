#include <stdio.h>

int main(void) {
    int voto, errori = 0;
    do {
        printf("Inserisci un voto compreso tra 1 e 10: ");
        scanf("%d", &voto);
        errori++;
    }while(voto < 1 || voto > 10); //finché il voto è sbagliato
    printf("Il voto inserito è %d e sono stati fatti %d errori",
        voto, errori - 1);

    return 0;
}
