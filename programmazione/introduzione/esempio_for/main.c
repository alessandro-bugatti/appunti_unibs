#include <stdio.h>

int main(void) {
    //++i equivalente a     i = i + 1
    //++i diverso da        i + 1
    for (int i = 0; i < 10; ++i) {
        printf("%d° giro, i = %d\n", i + 1, i);
    }
    return 0;
}