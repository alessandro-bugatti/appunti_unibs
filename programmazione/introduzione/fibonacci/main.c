#include <stdio.h>

int main(void) {
    int n, fn, fn_1, fn_2;
    printf("Indicami il numero di Fibonacci che ti interessa: ");
    scanf("%d", &n);
    fn_1 = 1;
    fn_2 = 0;
    if (n == 0) {
        printf("Il numero di indice 0 di Fibonacci vale 0\n");
    }else if (n == 1) {
        printf("Il numero di indice 1 di Fibonacci è 1\n");
    }else {
        for (int i = 0; i < n - 1; ++i) {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        printf("Il %d° numero di Fibonacci è %d", n, fn);
    }
    return 0;
}