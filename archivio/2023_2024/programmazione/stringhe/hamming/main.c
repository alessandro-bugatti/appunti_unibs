#include <stdio.h>
#include <string.h>

int lunghezza(char s[]){
    int cont = 0;
    while (s[cont] != '\0')
        cont++;
    return cont;
}

int hamming(char s1[], char s2[]){
    if(lunghezza(s1) != lunghezza(s2)){
        return -1;
    }
    int cont = 0;
    for (int i = 0; s1[i] != '\0'/* i < lunghezza(s1)*/; ++i) {
        if(s1[i] != s2[i]){
            cont++;
        }
    }
    return cont;
}



int main() {
    char s1[20], s2[20];
    printf("Inserisci due parole ");
    scanf("%s", s1);
    scanf("%s", s2);
    printf("La distanza di Hamming tra %s e %s è: %d\n ", s1, s2,
           hamming(s1, s2));
    printf("La lunghezza di %s è %d ", s1, strlen(s1));
    return 0;
}
