#include <stdio.h>
#include <string.h>

#define N 20

int main(void) {
    char s1[N], s2[N], s3[] = "Questa è una stringa troppo lunga";
    printf("Inserisci una frase: ");
    fgets(s1, N, stdin);
    //Assegnamento tra stringhe

    //Se fossero numeri scriveremmo così
    //s2 = s1; //Con le stringhe non si può fare
    //QUindi si utilizza la funzione di copia
    strncpy(s2, s1, N);
    puts(s2);

    //Che succede se la frase da compiare è più lunga della stringa che la dovrebbe contenere?
    strncpy(s2, s3, N);
    //Per mettere il terminatore nel caso s3 sia più lunga di s2
    //s2[N - 1] = '\0';
    puts(s2);

    //Confronto tra stringhe

    //Se fossero numeri
    if (s1 < s3) { //Non confronta i contenuti, ma solo gli indirizzi, che sono irrilevanti
        //Quindi non si fa così
    }
    //Per confrontare il contenuto di due stringhe si usa una funzione
    strncpy(s1, "cane", N);
    strncpy(s2, "cane", N);
    if (strncmp(s1, s2, N) < 0) { // s1 < s2 ci si può immaginare che sia così
        printf("%s viene prima di %s\n", s1, s2);
    }else if (strncmp(s1, s2, N) > 0) {
        printf("%s viene dopo %s\n", s1, s2);
    }else if (strncmp(s1, s2, N) == 0) {
        printf("Le due stringhe sono uguali\n");
    }

    //Ultima operazione la concatenazione
    //Se s1 = hello e s2 = world s1 + s2 = helloworld
    //La funzione che lo fa è strncat
    strncpy(s1, "hello", N);
    strncpy(s2, "world", N);
    //Concateno le stringhe e il risultato va nella prima
    strncat(s1, s2, N);
    puts(s1);

    printf("Inserisci il tuo nome: ");
    fgets(s2, N, stdin);
    strncpy(s1, "hello", N);
    strncat(s1, "\n", N);
    strncat(s1, s2, N);
    strncat(s1, s2, N);
    puts(s1);

    return 0;
}
