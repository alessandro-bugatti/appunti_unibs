#include <stdio.h>

int main(void) {
    int portata, peso, n_camion = 1;
    printf("Inserisci la portata del primo camion: ");
    scanf("%d", &portata);
    printf("Inserisci il peso di un oggetto: ");
    scanf("%d", &peso);
    while (peso != -1) {
        if (peso <= portata) {
            portata -= peso;
        }
        else {
            printf("Il camion non ha portata sufficiente a contenere il "
                " nuo oggetto, inserisci la portata di un nuovo camion: ");
            scanf("%d", &portata);
            n_camion++;
            portata -= peso;
        }
        printf("Inserisci il peso di un oggetto: ");
        scanf("%d", &peso);
    }
    printf("Sono stati utilizzati %d camion per caricare gli oggetti inseriti.\n", n_camion);
    return 0;
}