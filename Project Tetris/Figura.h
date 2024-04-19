#ifndef FIGURA_H
#define FIGURA_H

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

typedef enum
{
    GIR_HORARI = 0,
    GIR_ANTI_HORARI
} DireccioGir;

class Figura
{
public:
    Figura(TipusFigura figura, ColorFigura color);
    ~Figura();

    void desplacamentLateral(int columna);
    void baixar(int fila);
    void girar();

    void getFormaActual();

private:
    TipusFigura m_figura;
    ColorFigura m_color;

    int m_columa;
    int m_fila;
    int m_forma[MAX_ALCADA][MAX_AMPLADA];

};


/*
 - Ha de servir per poder gestionar figures que van caient.
 - Ha de poder guardar tota la informaci� necess�ria per gestionar la caiguda de la figura: tipus i 
   color de la figura, posici� actual, forma actual de la figura.
 - Ha de tenir m�todes que permetin fer el moviment i el gir de la figura i la interacci� amb el 
   tauler:
    - Despla�ar-se lateralment
    - Baixar dins del tauler
    - Girar
    - Recuperar la forma actual de la figura
    ...
*/

#endif
