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

    void inicialitzarFigura(const string& nomFitxer);
    void girarFigura(int figura[][MAX_AMPLADA], int gir, int limit, int direccio);

    bool girarFigura(DireccioGir direccio);
    
    void setColor(int color);
    void setFigura(int figura);
    void setFila(int fila) { m_fila = fila; }
    void setColumna(int columna) { m_columna = columna; }
    void setPivot4x4(int posicio);

    ColorFigura getColor() const { return m_color; }
    TipusFigura getFigura() const { return m_figura; }
    int getFila() const { return m_fila; }
    int getColuma() const { return m_columna; }
    int getForma(int i, int j) const { return m_forma[i][j]; }
    int getLimit() const { return limit; }
    int getPosicio4x4() const { return posicio4x4; }

private:
    TipusFigura m_figura;
    ColorFigura m_color;

    int limit = -1;
    int m_columna;
    int m_fila;
    int m_forma[MAX_ALCADA][MAX_AMPLADA];
    int posicio4x4 = 0;

    int numCasellesFigura(int figura, int& limit);
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


