#include <stdio.h>

const int MAX = 1000;

int main(void) {
    int a;
    int v[MAX];
    int b;
    v[10] = 8;
    v[-1] = 4;
    v[1000] = 10;
    printf("%d %d\n", a, b);
    v[1050] = 100;
    return 0;
}