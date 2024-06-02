﻿#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include <fstream>
#include "Joc.h"

using namespace std;


const int MAX_FIGURES = 7;
const int SEQ_MOV = 11;

class Partida 
{
public:
    Partida() : m_puntuacio(0), m_nivell(1), m_modeTest(false) {}
    
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures,
        const string& fitxerMoviments);
    void actualitza(int mode, double deltaTime);

private:
    double m_temps;
    Joc m_joc;
    int m_puntuacio;
    int m_nivell;
    bool m_modeTest;

};

#endif 


/*

 ▪ Guarda tota la informació necessària per gestionar la visualització gràfica i el funcionament d’una partida:
    ▪ Un objectede la classe Joc per poder gestionar el funcionament de la partida.
    ▪ La puntuació actual del jugador.
    ▪ El nivell actual del joc, que determina la velocitat de caiguda de les figures.
    ▪ Si la partida es juga en mode test, la seqüència d’aparició de les figures i la seqüència de moviments de
      les figures, que s’hauran llegit dels fitxers de text.
    ▪ Altres atributs que cregueu que puguin ser necessaris per gestionar la interacció gràfica o el funcionament
      de la partida.
 ▪ Us suggerim que tingui com a mínim aquests mètodes:
    ▪ inicialitza: s’encarrega d’inicialitzar la partida en mode normal o en mode test.
    ▪ actualitza: s’encarrega de cridar als mètodes de la classe Joc per fer els moviments de la figura en
      funció de l’entrada de tecla o del següent moviment en mode test i de la visualització de l’estat actual de
      la partida per pantalla
*/