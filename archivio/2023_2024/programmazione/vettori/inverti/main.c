#include <stdio.h>

#define N 15

void inverti(int v[], int n){
    int j = n - 1;
    for (int i = 0; i < n/2; ++i) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        j--;
    }
}

void inverti2(int v[], int l, int r) {
    int j = r - 1;
    for (int i = l; i < (r - l) / 2; ++i) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        j--;
    }
}

int main() {
    int v[N];
    for (int i = 0; i < N; ++i) {
        v[i] = i + 1;
    }
    inverti(v, N-3);
    for (int i = 0; i < N; ++i) {
        printf("%d ", v[i]);
    }
    return 0;
}
