#include <stdio.h>

int main(void) {
    float base, altezza, volume, volume_max, taglio, taglio_max, lato_corto;
    printf("Inserisci la base del rettangolo: ");
    scanf("%f", &base);
    printf("Inserisci l'altezza del rettangolo: ");
    scanf("%f", &altezza);
    if (base > altezza) {
        lato_corto = altezza;
    }
    else {
        lato_corto = base;
    }
    taglio = 0;
    taglio_max = taglio;
    volume_max = 0;
    //Continuo a tagliare fino a quando il lato corto non ha più nulla da tagliare
    while (taglio < lato_corto / 2) {
        volume = (base - 2*taglio)*(altezza - 2*taglio)*taglio;
        if (volume > volume_max) {
            volume_max = volume;
            taglio_max = taglio;
        }
        taglio++; //Ipotizzo che l'unità di misura siano i millimetri e ogni taglio abbia quella precisione
    }
    printf("Il taglio che garantisce il volume maggiore è di %.1f mm, "
           "che produrrà un volume di %.0f mm cubici.\n", taglio_max, volume_max);
    return 0;
}
