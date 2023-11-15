#include <stdio.h>
#define N 10
int presente(int V[], int n, int cercato){
    for (int i = 0; i < n; ++i) {
        if(V[i] == cercato){
            return 1;
        }
    }
    return 0;
}
int main() {
    int A[N], B[N], C[2*N];
    printf("Inserisci 10 elementi compresi tra 0 e 20");
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", &B[i]);
    }
    int k = 0;
    for (int i = 0; i < N; ++i) {
        C[k] = A[i];
        k++;
    }
    for (int i = 0; i < N; ++i) {
        if(!presente(A, N, B[i])){
            C[k] = B[i];
            k++;
        }
    }
    for (int i = 0; i < k; ++i) {
        printf("%d", C[i]);
    }
    return 0;
}
