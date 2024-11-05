#include <stdio.h>
//data di partenza: 1 gennaio 1970
int bisestile(int anno){
    if(anno%400==0)
        return 1;
    if(anno%100==0)
        return 0;
    if(anno%4==0)
        return 1;
    return 0;
}
int giorniAnno(int anno){
    return 365+bisestile(anno);
    }

int giorniAnni(int anno) {
    int totale=0;
    for (int i=1970; i<anno; i++) {
        totale+=giorniAnno(i);
    }
    return totale;
}
int giorniMese(int mese, int anno){
    if(mese==2)
        return 28 + bisestile(anno);
    if(mese==11 || mese==4 || mese==6 || mese==9)
        return 30;
    return 31;
}

int giorniMesi(int mese, int anno) {
    int totale=0;
    for (int i=1; i<mese; i++) {
        totale+=giorniMese(i, anno);
    }
    return totale;
}
int giorniTotali(int giorno, int mese, int anno){
    return giorniAnni(anno) + giorniMesi(mese, anno) + giorno;
}
int differenzaDate(int g1, int m1, int a1, int g2, int m2, int a2) {
    return giorniTotali(g1, m1, a1) - giorniTotali(g2, m2, a2);
}
int main(void) {
    printf("%d\n", giorniTotali(5, 11, 2024));
    printf("%d\n", differenzaDate(5, 11, 2024, 25, 9, 2023));
    return 0;
}
