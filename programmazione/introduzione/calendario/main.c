#include <stdio.h>

int main(void) {
    int mese, giorno, giorni_del_mese;
    printf("Inserisci il mese: ");
    scanf("%d", &mese);
    printf("Inserisci il giorno della settimana: ");
    scanf("%d", &giorno);
    //Assegno i giorni del mese
    if (mese == 2) {
        giorni_del_mese = 28;
    }
    else if (mese == 9 || mese == 11 || mese == 4 || mese == 6) {
        giorni_del_mese = 30;
    }
    else {
        giorni_del_mese = 31;
    }
    //Spazi per far iniziare correttamente il primo giorno
    for (int i = 0; i < giorno - 1; ++i) {
        printf("    ");
    }
    for (int i = 1; i <= giorni_del_mese; ++i) {
        printf("%4d", i);
        if ((i + giorno - 1)% 7 == 0)
            printf("\n");
    }
    return 0;
}
