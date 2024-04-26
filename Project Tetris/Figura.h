#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
using namespace std;

typedef enum
{
    COLOR_NEGRE = 0,
    COLOR_GROC = 1,
    COLOR_BLAUCEL = 2,
    COLOR_MAGENTA = 3,
    COLOR_TARONJA = 4,
    COLOR_BLAUFOSC = 5,
    COLOR_VERMELL = 6,
    COLOR_VERD = 7,
    NO_COLOR = -1,
} ColorFigura;


typedef enum
{
    NO_FIGURA = 0,
    FIGURA_O = 1,
    FIGURA_I = 2,
    FIGURA_T = 3,
    FIGURA_L = 4,
    FIGURA_J = 5,
    FIGURA_Z = 6,
    FIGURA_S = 7,
} TipusFigura;

const int MAX_ALCADA = 4;
const int MAX_AMPLADA = 4;
const int MAX_CASELLES = 16;

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura();
    ~Figura();

    void inicialitzarFigura(const string& nomFitxer);
    void desplacamentLateral(int columna);
    void baixar(int fila);
    void girarFigura(int gir, int area);

    void getFormaActual();

    void setFigura(TipusFigura figura) { m_figura = figura; }
    void setColor(ColorFigura color) { m_color = color; }

private:
    TipusFigura m_figura;
    ColorFigura m_color;

    int m_columna;
    int m_fila;
    int m_forma[MAX_ALCADA][MAX_AMPLADA];

};
#endif

/*
 m_fila i m_columna -> Marcaran la casella pivot quan s'ha de moure
*/


/*
 - Ha de servir per poder gestionar figures que van caient.
 - Ha de poder guardar tota la informació necessària per gestionar la caiguda de la figura: tipus i 
   color de la figura, posició actual, forma actual de la figura.
 - Ha de tenir mètodes que permetin fer el moviment i el gir de la figura i la interacció amb el 
   tauler:
    - Desplaçar-se lateralment
    - Baixar dins del tauler
    - Girar
    - Recuperar la forma actual de la figura
    ...
*/


