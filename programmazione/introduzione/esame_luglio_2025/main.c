#include <stdio.h>

int main(void) {
    //Da completare
    int a, b, s1_max, s2_max, p1_min, p2_min;


    for (int i = 0; i < 100; ++i) {

        if (a + b > s1_max + s2_max) {
            s1_max = a;
            s2_max = b;
        }
    }

    return 0;
}