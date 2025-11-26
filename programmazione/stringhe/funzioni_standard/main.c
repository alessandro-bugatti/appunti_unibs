#include <stdio.h>
#include <string.h>

const int MAX = 100;

void my_strncpy(char dest[], char src[], int n) {
    int i;
    for ( i = 0; i < n && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}


int main(void) {
    char s[] = "Ciao mondo";
    char t[MAX];
    //Copio la stringa s all'interno di t
    //t = s; NON si può fare
    strncpy(t, s, MAX); //Copia s in t, ma non più di MAX caratteri
    printf("La stringa contenuta in t è %s\n", t);
    //Verifichiamo che s sia uguale a t
    //if (s == t) NON si può
    if (strncmp(s, t, MAX) == 0) {//sono uguali
        printf("%s e %s sono uguali\n", s, t);
    }
    t[0] = 'c';
    if (strncmp(s, t, MAX) < 0) { //s < t
        printf("%s viene prima di %s\n", s, t);
    }else {
        printf("%s viene dopo %s\n", s, t);
    }
    strncat(t, " ", MAX);
    strncat(t, s, MAX);
    printf("Il nuovo contenuto di t è %s\n", t);
    t[5] = '\0';
    printf("Dopo essere stata tagliata t diventa %s\n", t);
    char r[MAX];
    my_strncpy(r, s, MAX);
    printf("La copia con la nostra funzione produce %s\n", r);
    return 0;
}