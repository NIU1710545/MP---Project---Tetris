#include "Partida.h"
#include "InfoJoc.h"
#include "GraphicManager.h"
#include "Joc.h"
#include "NodeFigura .h"
#include "NodeMoviment.h"
#include "SDL_keyboard.h"


Partida::Partida()
{
}


void Partida::actualitza(int mode, double deltaTime)
{

    if (mode == 1) {
        // Normal
        TipusTecla tecla = NO_TECLA;
        if (Keyboard_GetKeyTrg(KEYBOARD_LEFT)) {
            tecla = TECLA_ESQUERRA;
        }
        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT)) {
            tecla = TECLA_DRETA;
        }
        if (Keyboard_GetKeyTrg(KEYBOARD_UP)) {
            tecla = TECLA_AMUNT;
        }
        if (Keyboard_GetKeyTrg(KEYBOARD_DOWN)) {
            tecla = TECLA_ABAIX;
        }
        if (Keyboard_GetKeyTrg(KEYBOARD_SPACE)) {
            tecla = TECLA_ESPAI;
        }
        if (Keyboard_GetKeyTrg(KEYBOARD_ESCAPE)) {
            tecla = TECLA_ESCAPE;
        }

        switch (tecla) {
        case TECLA_ESQUERRA:
            m_joc.mouFigura(-1);
            break;
        case TECLA_DRETA:
            m_joc.mouFigura(1);
        case TECLA_AMUNT:
            m_joc.giraFigura(GIR_HORARI);
        case TECLA_ABAIX:
            m_joc.giraFigura(GIR_ANTI_HORARI);
        case TECLA_ESPAI:
            m_joc.baixaFiguraCop();
        case TECLA_ESCAPE:
            break;
        default:
            cout << "ERROR. Tecles" << endl;
        }

        m_temps += deltaTime;
        if (m_temps > 0.5) {
            m_joc.baixaFigura();
            m_temps = 0.0;
        }

    }
    else {
        // Agument de nivell -> Velocitat


        // Temps

    }
    m_puntuacio;




    // Pantalla
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

    // Figures


    // Nivell i puntuci� actual
    string msg = "Nivel: " + to_string(m_nivell) + ",   Puntuaci�: " + to_string(m_puntuacio);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);

}


void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures,
    const string& fitxerMoviments)
{   
    ifstream fileFigures(fitxerFigures);
    ifstream fileMoviments(fitxerMoviments);
    if (fileFigures.is_open() && (fileMoviments.is_open())) {
        
        m_joc.inicialitza(mode, fitxerInicial);

        if (mode == 1) {
            LlistaFigures llistaFigures;
            LlistaMoviments llistaMoviments;

            while (!fileFigures.eof() && (fileFigures.is_open())) {
                int figura, fila, columna, gir;
                fileFigures >> figura >> fila >> columna >> gir;
                llistaFigures.afegirFigura(figura, fila, columna, gir);
            }

            while (!fileMoviments.eof() && (fileMoviments.is_open())) {
                int moviment;
                fileMoviments >> moviment;
                llistaMoviments.afegirMoviment(moviment);
            }
        }
    }
    else {
        cout << "ERROR. Inicialitzar Partida";
    }
}

/* Accedir als continguts dels documents
llistaFigures.imprimirLlista();
llistaMoviments.imprimirLlista();
*/

/*
void Partida::actualitza(double deltaTime)
{
    //TODO 1: Interactuar amb la crida per dibuixar gr�fics (sprites).
    // 	      Dibuixar a pantalla el fons i el gr�fic amb el tauler buit.
    //------------------------------------------------------------------

    //TODO 1.1 Afegir l'include de GraphicManager --> #include "GraphicManager.h"
    //TODO 1.2 Fer la crida de dibuixar un sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY, centered);
    //	    Per comen�ar podem cridar el drawSprite amb els params --> 
    //          (GRAFIC_FONS,0,0, false) i 
    //          (GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false)



    

    //TODO 1.3: Dibuixar a pantalla el gr�fic amb el tauler i un quadrat groc a la posici� (2,3) del tauler



    //TODO 1.3: Dibuixar a pantalla el gr�fic amb el tauler i la figura representada a la matriu m_forma 
    // a la posici� del tauler indicada per m_fila i m_columna



    
    //TODO 2: Interacci� amb el teclat
    //------------------------------------------
    // TODO 2.1: Dibuixar dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i 
    // m_columna i que es vagi movent cap a la dreta cada cop que es prem la tecla de la fletxa dreta. 



    // TODO 2.2 Dibuixar a pantalla el gr�fic amb el tauler i la figura representada a l�atribut m_forma
    // a la posici� del tauler indicada per m_fila i m_columna. 
    // Moure la figura cap a la dreta o l�esquerra si es pressionen les tecles de les fletxes corresponents, 
    // comprovant que no ens passem dels limits del tauler. 



    //TODO 3: Introduir un temps d'espera
    //-----------------------------------
    // TODO 3.1: Dibuixar dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i 
    // m_columna. Fer que cada mig segon baixi una fila


    

    // TODO 3.2: Dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i  m_columna.
    // Moure el quadrat cap a la dreta o l�esquerra si es pressionen les tecles de les fletxes corresponents, 
    // comprovant que no ens passem dels limits del tauler.
    // Fer que cada segon baixi una fila, comprovant que no ens passem del limit inferior del tauler.



    // TODO 4: Imprimir text per pantalla
    //------------------------------------------
    // TODO 4.1: Mostrar la posici� actual del quadrat a dalt del tauler





    //TODO 5: Mostrar l�estat inicial del joc amb el tauler i la figura inicialitzats del fitxer        
    //-----------------------------------------
 



}

*/