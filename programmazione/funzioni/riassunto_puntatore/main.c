#include <stdio.h>

void scambio(int *p, int *r) {
    int temp;
    temp = *p;
    *p = *r;
    *r = temp;
}

int main(void) {
    //La variabile a serve a contenere un valore intero
    int a;
    //La variabile p serve a contente l'indirizzo di una variabile che contiene un intero
    int *p;
    //Quando assegnamo un valore ad a è perché ci interessa poi fare qualcosa con quel valore
    a = 10;
    //Per un puntatore l'assegnamento è piuttosto l'indicazione sulla variabile alla quale deve riferirsi
    p = &a; //da questo momento p fa riferimento ad a, o si può dire che p contiene l'indirizzo di a
    //Se modifico il contenuto della variabile riferita o puntata da p, si modifica il valore in a
    *p = 15;
    //L'espressione *p usata in un contesto come l'assegnamento o un'espressione significa
    //prendi il valore che si trova all'indirizzo contenuto in p e fanne qualcosa
    //Verifichiamo che il valore contenuto in a è cambiato
    printf("%d\n", a);

    //Esempio di utilizzo con funzione, che ha senso rispetto a quanto fatto sopra
    int f = 15, g = 23;
    scambio(&f, &g);
    printf("%d %d\n", f, g);
    return 0;
}
