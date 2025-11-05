#include <stdio.h>

void floyd(int N) {
    int x = 1;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i + 1 ; ++j) {
            printf("%6d", x);
            x++;
        }
        printf("\n");
    }
}

int main(void) {
    floyd(10);
    return 0;
}