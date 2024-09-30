#include <stdio.h>
#include <string.h>

int my_strlen(char *s){
    char *p;
    p = s;
    while (*p != '\0'){
        p++;
    }
    return p - s;
}

int main() {
    char s[] = "Arrivederci a tutti";
    char t[100];
    //copia tra stringhe, equivalente all'assegnamento tra numeri
    strncpy(t, s, 100);
    printf("%s \n%s", s, t);
    //concatenazione tra stringhe, quindi la seconda viene "attaccata" alla prima
    strncat(t, " e buonasera.", 20);
    printf("\n%s", t);
    char a[] = "albero", b[] = "pietra";
    //La condizione è vera se a < b
    if (strncmp(a, b, 20) < 0){
        printf("\n%s è minore di %s\n", a, b);
    }
    //La condizione è vera se il primo e il secondo parametro contengono la stessa identica parola
    if (strncmp(a, "albero", 20) == 0){
        printf ("Sono uguali\n");
    }
    printf("%d\n", my_strlen("ciao ale"));

    //Ricerca di una parola dentro una frase
    char parola[] = "ciao", frase[50];
    fgets(frase,50, stdin);
    printf("%s", frase);
    int conta = 0;
    char *p;
    p = frase;
    for (int i = 0; i < strlen(frase) - strlen(parola) + 1; ++i) {
        if (strncmp(p, parola, strlen(parola)) == 0){
            conta++;
        }
        p++;
    }
    printf("%d\n", conta);
    return 0;
}
