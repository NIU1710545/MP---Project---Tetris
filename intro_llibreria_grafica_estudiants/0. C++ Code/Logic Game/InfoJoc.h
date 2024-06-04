#ifndef INFO_JOC_H
#define INFO_JOC_H

typedef enum
{
    TECLA_ESQUERRA = 0,
    TECLA_DRETA = 1,
    TECLA_AMUNT =2,
    TECLA_ABAIX =3,
    TECLA_ESPAI =4,
    TECLA_ESCAPE = 5,
    NO_TECLA = -1
} TipusTecla;

// Tamany de la pantalla gràfica
const int SCREEN_SIZE_X = 600;
const int SCREEN_SIZE_Y = 700;

// Mida dels quadrats que formen el tauler
const int MIDA_QUADRAT = 26;

// Tamany del tauler
const int N_FILES_TAULER = 21;
const int N_COL_TAULER = 11;

// Posició del tauler a la pantalla
const int POS_X_TAULER = 120;
const int POS_Y_TAULER = 100;

#endif