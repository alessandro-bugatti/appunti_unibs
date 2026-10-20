#include <stdio.h>

int maggiore(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int main(void) {
    int a, b;
    printf("Inserisci due numeri: ");
    scanf("%d", &a);
    scanf("%d", &b);
    int m = maggiore(a, b);
    printf("Il maggiore è %d\n", m);
    return 0;
}
