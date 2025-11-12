#include <stdio.h>

const int MAX = 1000;

int main(void) {
    int crivello[MAX];
    for (int i = 2; i < MAX; ++i) {
        crivello[i] = 1;
    }
    for (int i = 2; i < MAX; ++i) {
        if (crivello[i] == 1) {
            for (int j = 2 * i; j < MAX; j += i) {
                crivello[j] = 0;
            }
        }
    }
    for (int i = 2; i < MAX; ++i) {
        if (crivello[i] == 1) {
            printf("%d ", i);
        }
    }
    return 0;
}
