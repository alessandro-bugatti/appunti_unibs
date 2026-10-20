#include <stdio.h>

int primo(int n) {
    for (int i = 2; i < n / 2; ++i) {
        if (n % i == 0) {
            return 0; // in C lo zero è interpretato come falso
        }
    }
    return 1;
}

int quanti_primi(int a, int b) {
    int contatore = 0;
    for (int i = a; i < b; ++i) {
        //Versione compatta
        //contatore += primo(i);
        //Versione più lineare
        if (primo(i)) {
            contatore++;
        }
    }
    return contatore;
}

int main(void) {
    printf("%d %d\n", primo(8), primo(97));
    printf("I primi compresi tra 8 e 100 sono: %d\n",
        quanti_primi(8, 100));
    return 0;
}
