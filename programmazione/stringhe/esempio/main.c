#include <stdio.h>
#include <string.h>

const int DIM = 30;

int main(void) {
    //Dichiarazione di una stringa costante, ma che
    //può comunque variare il proprio contenuto, la
    //lunghezza è determinata dalla dimensione
    //della stringa assegnata
    char s[] = "Hello world";
    printf("%s\n", s);
    //Essendo un vettore di caratteri il meccamismo
    //dell'indice è uguale
    s[3] = 'k';
    printf("La parola è diventata %s\n", s);
    //char t[DIM];
    //printf("Inserisci una parola: ");
    //scanf("%s", t);
    //printf("Hai inserito la parola %s %s\n", t, s);
    //Per poter inserire frasi fgets è adeguata
    char r[DIM];
    printf("Inserisci una frase: ");
    fgets(r, DIM, stdin);
    printf("La frase inserita è: %s\n", r);
    for (int i = 0; i < strlen(r); ++i) {
        printf("%c %d\n", r[i], r[i]);
    }
    r[strlen(r)] = 'a';
    printf("%s\n", r);
    return 0;
}