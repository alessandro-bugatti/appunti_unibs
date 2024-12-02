#include <math.h>
#include <stdio.h>

//Questo modo di utilizzare le strutture è poco pratico e ha degli inconvenienti
struct {
    float x;
    float y;
} p, r; //p e r sono delle variabili

//Questo è invece il modo che utilizzeremo
typedef struct {
    float x;
    float y;
} Punto ; //Nuovo tipo di dato, per convenzione maiuscolo

typedef struct {
    Punto p1;
    Punto p2;
    Punto p3;
} Triangolo;

#define MAX_VERTICI 12

typedef struct {
  Punto vertici[MAX_VERTICI];
  int n_vertici;
} Poligono;

//Funzione che prende come parametri delle strutture
float distanza(Punto d, Punto f) {
    float dx = d.x - f.x;
    float dy = d.y - f.y;
    return sqrt(dx*dx + dy*dy);
}

float perimetro(Triangolo t) {
    return distanza(t.p1, t.p2) +
            distanza(t.p2, t.p3) +
            distanza(t.p3, t.p1);
}

float perimetro(Poligono p) {
    float risultato = 0;
    for (int i = 0; i < p.n_vertici - 1; ++i) {
        risultato += distanza(p.vertici[i], p.vertici[i+1]);
    }
    risultato += distanza(p.vertici[0], p.vertici[p.n_vertici-1]);
}

Punto punto_medio(Punto a, Punto b) {
    Punto m;
    //m = (a + b)/ 2; //NO
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

int main(void) {
    Punto a, b, c;
    //Assegnamento, utilizzando i campi uno ad uno
    a.x = 12.4;
    a.y = 23.4;
    //Assegnamento con variabile dello stesso tipo
    b = a;
    //Stampa
    printf("Punto a (%f,%f)\n", a.x, a.y);
    //Lettura
    printf("Inserisci le coordinate di un punto: ");
    scanf("%f", &c.x);
    scanf("%f", &c.y);
    //Operazioni matematiche
    //a = b + c; //nessun operatore matematico può essere usato direttamente
    //Operazioni di confronto
    //Anche in questo caso vanno definite, preferibilmente con delle funzioni
    //if (a < b) {
    Triangolo t;
    t.p1.x = 54.6;
    t.p1.y = 34.5;
    t.p2 = a;
    printf("Inserisci le due coordinate dell'ultimo vertice: ");
    scanf("%f",&t.p3.x);
    scanf("%f",&t.p3.y);

    //Utilizzo di una funzione che accetta strutture come parametri
    float d = distanza(a, b);
    float p = perimetro(t);

    //Dichiarazione di strutture che contengono vettori
    Poligono poligono;
    printf("INserisci il numero di lati del poligono: ");
    scanf("%d", &poligono.n_vertici);
    for (int i = 0; i < poligono.n_vertici; ++i) {
        printf("Inserisci le coordinate del vertice %d: ", i + 1);
        scanf("%f", &poligono.vertici[i].x);
        scanf("%f", &poligono.vertici[i].y);
    }
    float pp = perimetro(poligono);

    //Funzione che ritorna una struttura
    Punto m = punto_medio(a,c);
    m = punto_medio(a, punto_medio(b,c));
    return 0;
}