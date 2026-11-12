#include <stdio.h>

#define N 100

int main(void) {
    char s[N];
    printf("Inserisci una parola: ");
    scanf("%s", s);
    printf("Hai inserito la parola %s\n", s);
    //Tutta la parte allocata oltre il terminatore non viene considerata
    //dalle funzioni che lavorano con le stringhe
    //Esperimento per vedere che le altre caselle contengono "sporco"
    for (int i = 0; i < N; ++i) {
        printf("%c", s[i]);
    }
    return 0;
}
