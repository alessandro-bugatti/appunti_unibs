#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Numero di carte presenti in un mazzo da briscola
#define CARTE_MAZZO 52
#define TESTO 30


char Semi[][TESTO] = {
    "Cuori",
    "Quadri",
    "Fiori",
    "Picche"
};

char Figure[][TESTO] = {
    "Jack",
    "Queen",
    "King"
};


//Singola carta da briscola
typedef struct{
    char seme[TESTO]; //Cuori, ...
    int numero; // Il numero che compare sulla carta, per le
        //figure è 11 -> jack, 12 -> donna, 13 -> re
    int valore; //Valore nel gioco, le figure valgono tutte 10, l'asso verrà gestito separatamente poichè può avere due valori, 1 e 10
} Carta;

//Mazzo di carte francesi
typedef struct{
    Carta carte[CARTE_MAZZO];
    int testa; //Posizione corrente della carta da pescare
} Mazzo;

//Mano di carte
typedef struct{
    Carta carte[10];
    int quante;
} Mano;

//Inizializza un mazzo da 52 carte francesi
void inizializza_mazzo(Mazzo *mazzo)
{
    int i, j;
    /*In questo ciclo vengono inizializzate le 52 carte
    valore e punteggio dovranno poi essere modificati
    per le figure, che non seguono
    una regola uguale alle altre*/
    for (i = 0; i < 4; i++) //semi
        for (j = 0; j < 13; j++) //numeri
        {
            int posizione = i*13 + j;
            strncpy(mazzo->carte[posizione].seme, Semi[i], TESTO);
            mazzo->carte[posizione].numero = j + 1;
            mazzo->carte[posizione].valore = j + 1;
        }
    //Modifica il valore delle figure
    for (i = 0; i < 4; i++)
        for (int j = 10; j <= 12; ++j){
            int posizione = i*13 + j;
            mazzo->carte[posizione].valore = 10; //figure
    }
    //Indica che la prima carta del vettore
    //è quella da pescare
    mazzo->testa = 0;
}

void mescola_mazzo(Mazzo *mazzo)
{
    int i;
    //Procedimento standard: scambio ogni elemento con uno a caso di quelli dopo di lui
    for (i = 0; i < CARTE_MAZZO; i++)
    {
        Carta temp;
        int a = rand()%(CARTE_MAZZO - i) + i;
        temp = mazzo->carte[i];
        mazzo->carte[i] = mazzo->carte[a];
        mazzo->carte[a] = temp;
    }
}


void stampa_carta(Carta carta)
{
    //Numero
    if (carta.numero < 11)
        printf("%d di %s ", carta.numero, carta.seme);
    else {
        printf("%s di %s ", Figure[carta.numero - 11], carta.seme);
    };
}

//Funzione per il debug
void stampa_mazzo(Mazzo *mazzo)
{
    int i;
    for (i = 0; i < CARTE_MAZZO; i++)
    {
        if (i % 13 == 0)
            printf("\n");
        stampa_carta(mazzo->carte[i]);
        printf(" ");

    }
}

//Funzione per il gioco
void stampa_mano(Mano *mano)
{
    int i;
    for (i = 0; i < mano->quante; i++)
    {
        stampa_carta(mano->carte[i]);
        printf("   ");
    }
}

//Serve per estrarre la successiva carta del mazzo
Carta dai_carta(Mazzo *mazzo)
{
    Carta estratta = mazzo->carte[mazzo->testa];
    mazzo->testa++;
    return estratta;
}

//Inserisce una carta in una mano
void pesca_carta(Mano *mano, Carta carta)
{
    mano->carte[mano->quante] = carta;
    mano->quante++;
}

//Calcola il valore di una mano, se è presente un asse, gli da il valore compatibile con evitare di andare oltre 21
int calcola_valore(const Mano *mano){
    int totale = 0;
    for (int i = 0; i < mano->quante; ++i) {
        totale += mano->carte[i].valore;
    }
    //Verifica se un asse può diventare un 10
    for (int i = 0; i < mano->quante; ++i) {
        if (mano->carte[i].valore == 1 &&
            totale + 9 <= 21) {
            totale += 9;
        }
    }
    return totale;
}

int main()
{
    srand(time(NULL));
    Carta briscola;
    Mazzo mazzo;
    Mano umano; //Umano
    Mano computer; //Computer
    int scelta;
    inizializza_mazzo(&mazzo);
//    stampa_mazzo(&mazzo);
    mescola_mazzo(&mazzo);
//    stampa_mazzo(&mazzo);
    umano.quante = 0;
    computer.quante = 0;
    //Distribuisce una carta all'umano e una al computer

    pesca_carta(&computer, dai_carta(&mazzo));
    //Turno dell'umano

     do{
         pesca_carta(&umano, dai_carta(&mazzo));
         stampa_mano(&umano);
         printf(" il tuo punteggio è %d\n", calcola_valore(&umano));
         if (calcola_valore(&umano) <= 21) {
             printf("Cosa vuoi fare? 1 - pesca, 2 - stai: ");
             scanf("%d", &scelta);
         }
     }while (scelta == 1 && calcola_valore(&umano) <= 21);
    if (calcola_valore(&umano) > 21) {
        printf("Hai sballato, ha vinto il banco\n");
        return 0;
    }
    while (calcola_valore(&umano) > calcola_valore(&computer)) {
        pesca_carta(&computer, dai_carta(&mazzo));
    }
    stampa_mano(&computer);
    if (calcola_valore(&computer) > 21) {
        printf("Il banco ha sballato con %d punti, ha vinto il giocatore\n", calcola_valore(&computer));
    }
    else {

        printf("Il banco vince con %d punti\n", calcola_valore(&computer));
    }

    return 0;
}