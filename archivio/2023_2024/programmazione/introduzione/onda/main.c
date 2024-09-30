#include <stdio.h>

int main() {
    float altezza;
    int km;
    km=0;
    printf("inserisci l'altezza iniziale: ");
    scanf("%f",&altezza);
    while(altezza>0.01){
        altezza *= 0.9;//altezza=altezza*0.9;
        km++;
    }
    printf("l'onda scompare dopo %d km.",km);
    return 0;
}
