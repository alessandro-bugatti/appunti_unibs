#include <stdio.h>
#include <string.h>

int occorrenze(char s[], char cercata[]) {
    int conta = 0;
    int l = strlen(cercata);
    for (int i = 0; s[i + l - 1] != '\0' ; ++i) {
        int c = 0; //conta le lettere uguali tra la parola cercata e il posto dove stiamo cercando
        for (int j = 0; cercata[j] != '\0'; ++j) {
            if (cercata[j] == s[i + j]) {
                c++;
            }
        }
        if (c == strlen(cercata)) {
            conta++;
        }
    }
    return conta;
}

int occorrenze2(char s[], char cercata[]) {
    int conta = 0;
    int l = strlen(cercata);
    for (int i = 0; s[i + l - 1] != '\0' ; ++i) {
        if (strncmp(&s[i], cercata, l) == 0){ // oppure strncmp(s + i, cercata, l)
           conta++;
        }
    }
    return conta;
}

int main(void) {
    char s[] = "o la va o lago spalla";
    char cercata[] = "la";
    printf("%d\n", occorrenze(s, cercata));
    printf("%d\n", occorrenze2(s, cercata));
    return 0;
}
