#include <stdio.h>

int main(void) {
    int a, b, c, d;
    a = 7;
    b = 7;
    c = a++;
    d = ++b;
    printf("a = %d, b = %d, c = %d, d = %d", a, b, c, d);
    return 0;
}