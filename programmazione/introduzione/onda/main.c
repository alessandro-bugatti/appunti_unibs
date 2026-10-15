#include <stdio.h>

int main(void) {
    float h = 0;
    int km = 0;
    printf("inserisci altezza: ");
    scanf("%f", &h);
    while (h>0.01) {
        h=h*0.9;
        km++;
    }
    printf("L'onda sparisce dopo %d km", km);
    return 0;
}
