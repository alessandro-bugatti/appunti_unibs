#include <stdio.h>
#include <tgmath.h>

//Verifica se un numero è primo, ritorna 1 se lo è, 0 altrimenti
int primo(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int quanti_primi(int a, int b) {
    int conta = 0;
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    for (int i = a; i < b; ++i) {
        if (primo(i)) {
            conta++;
        }
    }
    return conta;
}


int main(void) {
    int a, b;
    printf("Inserisci gli estremi dell'intervallo.\n");
    scanf("%d", &a);
    scanf("%d", &b);
    int quanti = quanti_primi(a, b);
    printf("I primi compresi nell'intervallo [%d, %d) sono %d\n",
        a, b, quanti);
    return 0;
}
