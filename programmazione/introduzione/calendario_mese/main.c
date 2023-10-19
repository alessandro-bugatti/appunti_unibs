#include <stdio.h>

int main() {
    int mese, giorno, giorni_mese;
    printf("Inserisci il numero del mese (1-12): ");
    scanf("%d", &mese);
    printf("Inserisci il primo giorno della settimana (1-7): ");
    scanf("%d", &giorno);
    //Prima parte:calcolo del numero di giorni del mese
    //Versione con if
//    if (mese == 1)
//        giorni_mese = 31;
//    else if (mese == 2)
//        giorni_mese = 28;
    //Versione con lo switch
    switch (mese) {
        case 2:
            giorni_mese = 28;
            break;
        case 11:
        case 4:
        case 6:
        case 9:
            giorni_mese = 30;
            break;
        //Facoltativo
        default:
            giorni_mese = 31;
    }

    //Seconda parte
    for (int i = 0; i < giorno - 1; ++i) {
        printf("    ");
    }
    
    for (int i = giorno; i <= giorni_mese + (giorno - 1); ++i) {
        printf("%4d", i - giorno + 1);
        if (i % 7 == 0)
            printf("\n");
    }
    printf("\n");
    return 0;
}
