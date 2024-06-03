#include "Tetris.h"
#include "fsrmscreen.h"
#include "GraphicManager.h"
#include "InfoJoc.h"
#include <list>


Tetris::~Tetris() 
{

}

int Tetris::Menu()
{
	cout << "MENU PRINCIPAL" << endl;
	cout << "======================" << endl;
	cout << "1. Joc en mode normal" << endl;
	cout << "2. Joc en mode test" << endl;
	cout << "3. Mostrar puntuacions" << endl;
	cout << "4. Sortir" << endl;
	cout << endl;
	cout << "Eleccio: ";
	cin >> opcioMenu;
	return opcioMenu;
}


void Tetris::inicialitzar(int mode)
{
	switch (mode)
	{
	case 1: case 2:
		m_partida.inicialitza(mode, fitxerPartidaTest, fitxerFiguresTest, fitxerMovimentsTest);
		break;
	case 3:
		mostraPuntuacions();
		break;
	case 4:
		break;
	default:
		cout << "ERROR. Menu" << endl;
		break;
	}
}


int Tetris::juga(int mode)
{
	inicialitzar(mode);
}




// Nom a registrar - Nivell i Puntuació final
void Tetris::mostraPuntuacions()
{
	ifstream fitxerPuntuacio("Puntuacions.txt");
	if (!fitxerPuntuacio.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}

	while (!fitxerPuntuacio.eof() && (fitxerPuntuacio.is_open())) {

		string nomUsuari, nivell, puntuacio;

		fitxerPuntuacio >> nomUsuari >> nivell >> puntuacio;

		string missatge = "Usuari: "+ nomUsuari + "Nivel: " + nivell + ",   Puntuació: " + puntuacio;
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, missatge);
		
	}

}
