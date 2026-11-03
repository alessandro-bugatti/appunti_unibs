#include <stdio.h>
#include <stdlib.h>

//Produce un numero casuale da 1 a n
int random_dado(int n) {
    return rand() % n + 1;
}

//Produce un numero casuale compreso in un intervallo [a, b]
int random_intervallo(int a, int b) {
    return rand() % (b - a + 1) + a;
}

int main() {

    printf("%d\n", random_dado(6));
    printf("%d\n", random_intervallo(-898, 100));
    return 0;
}
