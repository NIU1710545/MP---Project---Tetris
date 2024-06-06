#include "Partida.h"
#include "Figura.h"
#include "InfoJoc.h"
#include "SDL_keyboard.h"
#include "NodeFigura.h"
#include "NodeMoviment.h"


bool Partida::finalitzarFigura()
{
    if (m_joc.getColocada()) {
        m_joc.setColocada(false);
        return true;
    }
    else {
        return false;
    }
}

void Partida::inicialitzarNouTauler()
{
    m_joc.escriuTauler("NouTauler.txt");
    m_joc.nouTauler("NouTauler.txt");
}

void Partida::inicialitzarNovaFigura(int mode)
{
    if (mode == 2) {
        if (m_nFigura < 7) {
            m_nMoviment = 0;
            ofstream fitxerNovaFigura("NovaFigura.txt");
            if (!fitxerNovaFigura.is_open()) {
                cout << "ERROR. Escriptura" << endl;
                return;
            }
            else {
                fitxerNovaFigura << numFigura[m_nFigura][0] << " " << numFigura[m_nFigura][1] << " " << numFigura[m_nFigura][2] << " " << numFigura[m_nFigura][3];
            }
            fitxerNovaFigura.close();

            m_joc.novaFigura("NovaFigura.txt");
            m_nFigura++;
            m_joc.setColocada(false);
        }
        else {
            setFinalPartida(true);
        }
    }
    else {
        m_joc.novaFigura();
    }
}


void Partida::actualitza(int mode, double deltaTime)
{
    m_temps += deltaTime;
    if (mode == 1) {
        // Normal
        int TECLA = -1;
        if (Keyboard_GetKeyTrg(KEYBOARD_RIGHT))
            TECLA = KEYBOARD_RIGHT;
        else if (Keyboard_GetKeyTrg(KEYBOARD_LEFT))
            TECLA = KEYBOARD_LEFT;
        else if (Keyboard_GetKeyTrg(KEYBOARD_DOWN))
            TECLA = KEYBOARD_DOWN;
        else if (Keyboard_GetKeyTrg(KEYBOARD_UP))
            TECLA = KEYBOARD_UP;
        else if (Keyboard_GetKeyTrg(KEYBOARD_SPACE))
            TECLA = KEYBOARD_SPACE;

        switch (TECLA)
        {
        case KEYBOARD_RIGHT:
            m_joc.mouFigura(1);
            break;
        case KEYBOARD_LEFT:
            m_joc.mouFigura(-1);
            break;
        case KEYBOARD_UP:
            m_joc.giraFigura(GIR_ANTI_HORARI);
            break;
        case KEYBOARD_DOWN:
            m_joc.giraFigura(GIR_HORARI);
            break;
        case KEYBOARD_SPACE:
            m_joc.baixaFiguraCop();
            break;
        case KEYBOARD_ESCAPE: break;
        }

    }
    else {

        switch (m_moviments[m_nMoviment]) {
        case 0:
            m_joc.mouFigura(-1);
            break;
        case 1:
            m_joc.mouFigura(1);
            break;
        case 2:
            m_joc.giraFigura(GIR_HORARI);
            break;
        case 3:
            m_joc.giraFigura(GIR_ANTI_HORARI);
            break;
        case 4:
            m_joc.baixaFiguraCop();
            break;
        case 5:
            break;
        }
        m_nMoviment++;
    }

    if (!m_joc.comprovaTaulerPle()) {
        setFinalPartida(true);
    }

    // Pantalla
    GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
    GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);

    // Figures
    m_joc.dibuixa();

    // Actualització puntuació
    int filesCompletes = m_joc.getfilesCompletes();
    if (filesCompletes > 0) {
        m_puntuacio += 100 * filesCompletes;
        switch (filesCompletes) {
        case 0:break;
        case 1:
            break;
        case 2:
            m_puntuacio += 50;
            break;
        case 3:
            m_puntuacio += 70;
            break;
        case 4:
            m_puntuacio += 100;
            break;
        }
    }

    // Actualització nivell i velocitat

    if (m_temps >= m_tempsVelocitat) {
        m_joc.baixaFigura();
        m_temps = 0.0;
    }
    if (m_puntuacio >= m_nivell * 1000) {
        m_nivell++;
        m_tempsVelocitat -= 0.1;
    }
    
    // Nivell i puntució actual
    string msg = "Nivel: " + to_string(m_nivell) + ",   Puntuacio: " + to_string(m_puntuacio);
    GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, msg);

}

void Partida::inicialitza(int mode, const string& fitxerInicial, const string& fitxerFigures,
    const string& fitxerMoviments)
{   

    m_joc.inicialitza(fitxerInicial, mode);

    if (mode == 2) {

        ifstream fileFigures(fitxerFigures);
        ifstream fileMoviments(fitxerMoviments);

        if (!fileFigures.is_open() || (!fileMoviments.is_open())) {
            cout << "ERROR. Inicialitzar Partida" << endl;
        }
        else {

            int moviment;
            
            for (int i = 0; i < MAX_FIGURES; i++) {
                for (int j = 0; j < 4; j++) {
                    fileFigures >> numFigura[i][j];
                }
            }

            int i = 0;
            while (fileMoviments >> moviment) {
                m_moviments[i] = moviment;
                i++;
            }
        }
    }

}




/*
void Partida::actualitza(double deltaTime)
{
    //TODO 1: Interactuar amb la crida per dibuixar gràfics (sprites).
    // 	      Dibuixar a pantalla el fons i el gràfic amb el tauler buit.
    //------------------------------------------------------------------

    //TODO 1.1 Afegir l'include de GraphicManager --> #include "GraphicManager.h"
    //TODO 1.2 Fer la crida de dibuixar un sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY, centered);
    //	    Per començar podem cridar el drawSprite amb els params --> 
    //          (GRAFIC_FONS,0,0, false) i 
    //          (GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false)



    

    //TODO 1.3: Dibuixar a pantalla el gràfic amb el tauler i un quadrat groc a la posició (2,3) del tauler



    //TODO 1.3: Dibuixar a pantalla el gràfic amb el tauler i la figura representada a la matriu m_forma 
    // a la posició del tauler indicada per m_fila i m_columna



    
    //TODO 2: Interacció amb el teclat
    //------------------------------------------
    // TODO 2.1: Dibuixar dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i 
    // m_columna i que es vagi movent cap a la dreta cada cop que es prem la tecla de la fletxa dreta. 



    // TODO 2.2 Dibuixar a pantalla el gràfic amb el tauler i la figura representada a l’atribut m_forma
    // a la posició del tauler indicada per m_fila i m_columna. 
    // Moure la figura cap a la dreta o l’esquerra si es pressionen les tecles de les fletxes corresponents, 
    // comprovant que no ens passem dels limits del tauler. 



    //TODO 3: Introduir un temps d'espera
    //-----------------------------------
    // TODO 3.1: Dibuixar dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i 
    // m_columna. Fer que cada mig segon baixi una fila


    

    // TODO 3.2: Dibuixar per pantalla un quadrat groc a la posicio indicada per m_fila i  m_columna.
    // Moure el quadrat cap a la dreta o l’esquerra si es pressionen les tecles de les fletxes corresponents, 
    // comprovant que no ens passem dels limits del tauler.
    // Fer que cada segon baixi una fila, comprovant que no ens passem del limit inferior del tauler.



    // TODO 4: Imprimir text per pantalla
    //------------------------------------------
    // TODO 4.1: Mostrar la posició actual del quadrat a dalt del tauler





    //TODO 5: Mostrar l’estat inicial del joc amb el tauler i la figura inicialitzats del fitxer        
    //-----------------------------------------
 



}

*/