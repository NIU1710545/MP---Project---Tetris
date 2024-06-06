//
//  main.cpp
//
//  Copyright � 2018 Compiled Creations Limited. All rights reserved.
//

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined  (_WIN64)

#include <iostream>
//Definicio necesaria per poder incloure la llibreria i que trobi el main
#define SDL_MAIN_HANDLED
#include <windows.h>
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#include <conio.h>      /* getch */ 

#elif __APPLE__
//Llibreria grafica
#include "../Graphic Lib/libreria.h"
#include "../Graphic Lib/NFont/NFont.h"
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"
#include <SDL2/SDL.h>
#pragma clang diagnostic pop

#endif

#include "./Partida.h"
#include "./InfoJoc.h"
#include "./Tetris.h"
#include "./Joc.h"
#include "fsrmscreen.h"


int main(int argc, const char* argv[])
{
    //Instruccions necesaries per poder incloure la llibreria i que trobi el main
    SDL_SetMainReady();
    SDL_Init(SDL_INIT_VIDEO);

    //Inicialitza un objecte de la classe Screen que s'utilitza per gestionar la finestra grafica
    Screen pantalla(SCREEN_SIZE_X, SCREEN_SIZE_Y);
    //Mostrem la finestra grafica
    pantalla.show();

    Uint64 NOW = SDL_GetPerformanceCounter();
    Uint64 LAST = 0;
    double deltaTime = 0;

    string fitxerPartidaTest = "./data/Games/partida.txt";
    string fitxerFiguresTest = "./data/Games/figures.txt";
    string fitxerMovimentsTest = "./data/Games/moviments.txt";
    string fitxerPartida = "./data/Games/iniciPartida.txt";
    string fitxerPuntuacions = "./data/Games/Puntuacions.txt";


    // CODI PER LA GESTIÓ DEL MENÚ I DE LES OPCIONS DEL JOC

    Tetris tetris;

    do {
        tetris.Menu();
        if (tetris.getMode() == 1) {
            tetris.inicialitzar(tetris.getMode(), fitxerPartida, fitxerFiguresTest, fitxerMovimentsTest);
        }
        else if (tetris.getMode() == 2)
        {
            tetris.inicialitzar(tetris.getMode(), fitxerPartidaTest, fitxerFiguresTest, fitxerMovimentsTest);
        }
        switch (tetris.getMode()) {
        case 1: case 2:

            do
            {
                LAST = NOW;
                NOW = SDL_GetPerformanceCounter();
                deltaTime = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
                pantalla.processEvents();

                tetris.getPartida().actualitza(tetris.getMode(), deltaTime);

                tetris.juga(tetris.getMode(), deltaTime);
                pantalla.update();


            } while (!Keyboard_GetKeyTrg(KEYBOARD_ESCAPE));

            break;
        case 3:
            tetris.mostraPuntuacions(fitxerPuntuacions);
            cout << endl;
            break;
        case 4:
            break;
        default:
            cout << "ERROR. Menu" << endl;
            break;
        }
        

    } while (tetris.getMode() != 4);

    //Instruccio necesaria per alliberar els recursos de la llibreria 
    SDL_Quit();

    return 0;
}

