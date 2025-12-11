

/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include <chrono>
#include <cstring>
#include <iostream>

#include "raylib.h"
#include <string>

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
    Rectangle r;
    char seme[TESTO]; //Cuori, ...
    int numero; // Il numero che compare sulla carta, per le
        //figure è 11 -> jack, 12 -> donna, 13 -> re
    int valore; //Valore nel gioco, le figure valgono tutte 10, l'asso verrà gestito separatamente poichè può avere due valori, 1 e 10
    int pos_x;
    int pos_y;
    const Texture2D *card_sheet;
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
    static const Texture carte = LoadTexture("../assets/deck.png");
    int i, j;
    /*In questo ciclo vengono inizializzate le 52 carte
    valore e punteggio dovranno poi essere modificati
    per le figure, che non seguono
    una regola uguale alle altre*/
    for (i = 0; i < 4; i++) //semi
        for (j = 0; j < 13; j++) //numeri
        {
            int posizione = i*13 + j;
            Carta c;
            strncpy(c.seme, Semi[i], TESTO);
            c.numero = j + 1;
            c.valore = j + 1;
            c.r.width = 125;
            c.r.height = 172;
            c.r.x = 173 + (c.r.width + 14) * j;
            c.r.y = 35 +  (c.r.height + 18) * i;
            c.card_sheet = &carte;
            mazzo->carte[posizione] = c;
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

//Parte grafica

/**
 *
 * @param c Carta da disegnare
 * @param w larghezza della carta a video, se non passato vale 125
 * @param h altezza della carta a video, se non passato uguale a 172
 */
void disegna_carta(const Carta *c, int w = 125, int h = 172) {
    Rectangle destination = {(float)c->pos_x,(float)c->pos_y,(float)w, (float)h};
    DrawTexturePro(*c->card_sheet, c->r, destination,{}, 0, WHITE);
}

/**
 *
 * @param c Carta da posizionare
 * @param x
 * @param y
 */
void posiziona_carta(Carta *c, int x, int y) {
    c->pos_x = x;
    c->pos_y = y;
}

/**
 *
 * @param mano Mano da disegnare a video
 * @param y Altezza dove disegnare, tutte le carte sono disegnate in fila alla stessa altezza
 */
void disegna_mano(Mano *mano, int y) {
    for (int i = 0; i < mano->quante; ++i) {
        posiziona_carta(&mano->carte[i], 100 + (mano->carte[i].r.width + 20)*i, y);
        disegna_carta(&mano->carte[i]);
    }
}

/**
 * Serve a verificare se il click del mouse è fatto su un pulsante
 * @param r Il rettangolo che rappresenta il pulsante
 * @param x Coordinata x del mouse
 * @param y Coordinata y del mouse
 * @return
 */
int inside(const Rectangle *r, int x, int y) {
    if (x < r->x || x > r->x + r->width)
        return 0;
    if (y < r->y || y > r->y + r->height)
        return 0;
    return 1;
}

/**
 * Disegna un pulsante con una scritta
 * @param r Dimensione del pulsante
 * @param testo Testo del pulsante
 * @param fontSize Dimensione del font
 * @param c Colore del pulsante, il testo è sempre nero
 */
void disegna_pulsante(Rectangle r, char testo[], int fontSize, Color c) {
    DrawRectangle(r.x, r.y, r.width, r.height,c);
    int dimensione = MeasureText(testo, fontSize);
    int x = r.x + (r.width - dimensione) / 2;
    int y = r.y + (r.height - fontSize) / 2;
    DrawText(testo,x, y, fontSize, BLACK);
}

int main(void)
{
    srand(time(NULL));
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1280;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Blackjack");



    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    Mazzo mazzo;
    Mano umano, computer;
    umano.quante = computer.quante = 0;
    inizializza_mazzo(&mazzo);
    mescola_mazzo(&mazzo);
    pesca_carta(&umano, dai_carta(&mazzo));
    pesca_carta(&computer, dai_carta(&mazzo));
    Rectangle p1 = {300, 640, 200, 70};
    Rectangle p2 = {700, 640, 200, 70};
    int fine = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        if (!fine) {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (inside(&p1, GetMouseX(), GetMouseY())) {
                    pesca_carta(&umano, dai_carta(&mazzo));
                    if (calcola_valore(&umano) > 21) {
                        fine = 1;
                    }
                }
                if (inside(&p2, GetMouseX(), GetMouseY())) {
                    while (calcola_valore(&umano) > calcola_valore(&computer)) {
                        pesca_carta(&computer, dai_carta(&mazzo));
                    }
                    fine = 1;
                }
            }
        }
        //----------------------------------------------------------------------------------
        //----------------------------------------------------------------------------------
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground({5,72,36,255});
        disegna_pulsante(p1,"PESCA", 40, YELLOW);
        disegna_pulsante(p2,"STAI", 40, YELLOW);
        char punteggio1[50];
        sprintf(punteggio1, "Giocatore: %d", calcola_valore(&umano));
        DrawText(punteggio1, 100, 100, 30, WHITE);
        disegna_mano(&umano, 150);
        char punteggio2[50];
        sprintf(punteggio2, "Banco: %d", calcola_valore(&computer));
        DrawText(punteggio2, 100, 400, 30, WHITE);
        disegna_mano(&computer, 450);

        if (fine) {
            if (calcola_valore(&umano) > 21) {
                DrawText("Hai sballato, vince il banco", 100, 20, 50, WHITE);
            }else if (calcola_valore(&computer) > 21) {
                DrawText("Hai vinto, il banco ha sballato", 100, 20, 50, WHITE);
            }else {
                DrawText("Ha vinto il banco, spiacente", 100, 20, 50, WHITE);
            }
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

