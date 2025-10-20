#include <stdio.h>

int main(void) {
    int N = 4;
    for (int i = 0; i < N; ++i) {
        printf(" _    ");
    }
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("/ \\   ");
    }
    printf("\n");
    for (int i = 0; i < N; ++i) {
        printf("   \\_/");
    }
    return 0;
}