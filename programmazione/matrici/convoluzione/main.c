#include <stdio.h>

#define N 200

void convoluzione(int m[][N], int conv[][N], int kernel[][3], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            int valore = 0;
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    valore += m[i + x - 1][j + y - 1] * kernel[x][y];
                }
            }
            conv[i][j] = valore;

        }
    }
}



int main(void) {
    printf("Hello, World!\n");
    return 0;
}
