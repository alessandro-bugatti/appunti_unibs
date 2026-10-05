#include <stdio.h>

int main(void) {
    int a = 1, b = 2, c;
    c = a + b;
    int d;
    d = a / b;
    float f;
    f = a / b; //Attenzione che f è sempre 0 anche in questo caso
    /*
     Il valore di f è zero perchè prima viene fatta la divisione intera
     tra a e b
     */
    c += 2; // c = c + 2;
    c++; // c = c + 1;

    return 0;
}
