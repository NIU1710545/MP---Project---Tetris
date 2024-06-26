﻿#ifndef PARTIDA_H
#define PARTIDA_H

#include <stdio.h>
#include <string>
#include <fstream>
#include "Joc.h"
#include "GraphicManager.h"

using namespace std;


const int MAX_FIGURES = 7;

class Partida 
{
public:
    Partida() : m_puntuacio(0), m_nivell(1), m_tempsVelocitat(1), m_nMoviment(0), m_final(false) {}
    
    void inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures,
        const string& fitxerMoviments);
    void actualitza(int mode, double deltaTime);

    bool finalitzarFigura();
    void inicialitzarNovaFigura(int mode);   
    void inicialitzarNouTauler();

    void setFinalPartida(bool final) { m_final = final; }
    void setTemps(double time) { m_temps = time; }
    void setPuntuacio(int punts) { m_puntuacio += punts; }

    bool getFinalPartida() const { return m_final; }
    int getmTemps() const { return m_temps; }
    int getPuntuacio() const { return m_puntuacio; }
    int getNivell() const { return m_nivell; }

private:
    double m_temps = 0;
    double m_tempsVelocitat;
    bool m_final;
    Joc m_joc;
    int m_puntuacio;
    int m_nivell;
    int m_nFigura = 0;
    int numFigura[MAX_FIGURES][4]{};
    int m_nMoviment;
    int m_moviments[11]{};

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