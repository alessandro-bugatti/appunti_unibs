#include <stdio.h>
#include <math.h>

int main() {
    int N, primo = 1;
    printf("Inserisci un numero maggiore di due: ");
    scanf("%d", &N);
    for (int i = 2; i < sqrt(N) ; ++i) {
        if (N % i == 0){
            primo = 0;
            break;
        }
    }
    if(primo){
        printf("Il numero %d è primo\n", N);
    }else{
        printf("Il numero %d non è primo\n", N);
    }
    return 0;
}
