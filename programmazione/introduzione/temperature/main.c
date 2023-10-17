#include <stdio.h>

int main() {
    float temperaturaC,temperaturaF;
    int scelta;
    printf("Inserisci la tua scelta (1-Celsius Fahrenheit, 2-Fehrenheit Celsius): ");
    scanf("%d",&scelta );
    if(scelta==1){
        printf("Inserisci la temperatura in Celsius: ");
        scanf("%f",&temperaturaC);
        temperaturaF= temperaturaC*9/5+32;
        printf("La temperatura in Fehrenheit è: %f°",temperaturaF);
    }
    else {
        printf("Inserisci la temperatura in Fehrenheit: ");
        scanf("%f", &temperaturaF);
        temperaturaC = (temperaturaF - 32)* 5/9;
        printf("La temperatura in Celsius è: %f°", temperaturaC);
    }
    return 0;
}
