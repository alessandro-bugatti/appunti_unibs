#include <stdio.h>

void floyd(int N) {
    int n = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            printf("%4d", n);
            n++;
        }
        printf("\n");
    }
}

int main(void) {
    floyd(15);
    return 0;
}
