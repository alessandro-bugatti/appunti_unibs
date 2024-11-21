#include <stdio.h>

#define N 200

int main(void)
{
    char frase[N];
    printf("Inserisci una frase: ");
    fgets(frase, N, stdin);
    printf("La frase inserita è : %s", frase);
    return 0;
}
