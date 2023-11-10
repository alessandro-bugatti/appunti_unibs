#include <stdio.h>
#include <stdlib.h>

#define N 10

int rimuovi_elemento(int v[], int n, int pos){
    if (pos < 0 || pos > n - 1)
        return -1;
    for (int i = pos; i < n - 1; ++i) {
        v[i] = v[i + 1];
    }
    return n - 1; //La nuova dimensione del vettore dopo la rimozione
}

int rimuovi_elemento_perde_ordine(int v[], int n, int pos) {
    if (pos < 0 || pos > n - 1)
        return -1;
    v[pos] = v[n-1];
    return n - 1;
}

int rimuovi_elemento_per_valore(int v[], int n, int valore){
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] == valore) {
            rimuovi_elemento(v, n, i);
            n--;
            i--;
        }
    }
    return n;
}

int rimuovi_elemento_per_valore_efficente(int v[], int n, int valore) {

}




int main() {
    int v[N], n = N;
    for (int i = 0; i < n; ++i) {
        v[i] = rand()%20;
        printf("%3d", v[i]);
    }
    printf("\n");
    if (rimuovi_elemento(v, n, 5) != -1){
        n--;
    }
    for (int i = 0; i < n; ++i) {
        printf("%3d", v[i]);
    }
    printf("\n");
    if (rimuovi_elemento_perde_ordine(v, n, 2) != -1){
        n--;
    }
    for (int i = 0; i < n; ++i) {
        printf("%3d", v[i]);
    }
    printf("\n");
    n = rimuovi_elemento_per_valore(v, n, 18);
    for (int i = 0; i < n; ++i) {
        printf("%3d", v[i]);
    }

    return 0;
}
