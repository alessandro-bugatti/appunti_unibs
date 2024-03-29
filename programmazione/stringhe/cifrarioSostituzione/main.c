#include <stdio.h>
#define N 100
/*
 * Si scriva una funzione che accetta come parametri una stringa che contiene un testo da cifrare e una seconda stringa che contiene una chiave di cifratura. Il metodo da utilizzare è la cifratura per sostituzione, nella quale ogni carattere del testo in chiaro viene sostituito da un carattere diverso secondo una regola dettata dalla chiave di cifratura: ad esempio la 'a' diventa una 'r', la 'b' diventa una 'g', la 'c' diventa una 'm', ecc. Un modo compatto di rappresentare la chiave è quello di avere una stringa contenente tutti i 26 caratteri dell'alfabeto inglese in posizioni mescolate, in modo che la lettera che si trova in prima posizione rappresenti il carattere in cui viene trasformata la 'a', quella in seconda posizione il carattere in cui viene trasformata la 'b', ecc. Si può supporre che le lettere del testo da cifrare siano solo le lettere minuscole dell'alfabeto inglese e quindi il testo non contenga altri tipi di caratteri.

Si scriva successivamente un programma per testare la correttezza della funzione creata.

Suggerimento: si scriva poi anche la funzione per decodificare un testo cifrato creato con questo sistema.
 */

void codifica( char chiaro[], char cifrato[], char chiave[] )
{
    int i;
    for(i = 0; chiaro[i] != 0; i++)
    {
        cifrato[i] = chiave[chiaro[i] - 'a'];   //da 0 a 25 incluso

    }
    cifrato[i] = '\0';
}

int main()
{
    char chiave[] = "qwertyuiopasdfghjklzxcvbnm";
    char chiaro[] = "siamoarrivati";
    char cifrato[N];
    codifica( chiaro, cifrato, chiave );

    printf("%s\n", cifrato);

    return 0;
}
