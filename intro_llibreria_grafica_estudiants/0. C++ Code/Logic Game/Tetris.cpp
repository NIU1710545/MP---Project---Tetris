#include "Tetris.h"
#include "fsrmscreen.h"
#include <list>

Tetris::Tetris() 
{
	
}

Tetris::~Tetris() 
{

}


int Tetris::juga(Screen& pantalla)
{
	cout << "MENU PRINCIPAL";
	cout << "======================";
	cout << "1. Joc en mode normal";
	cout << "2. Joc en mode test";
	cout << "3. Mostrar puntuacions";
	cout << "4. Sortir";
	cin >> opcioMenu;

	switch (opcioMenu) {
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;

	default:
		cout << "ERROR. Menu" << endl;
		break;
	}

}


void Tetris::mostraPuntuacions()
{
	ifstream fitxerPuntuacio("Puntuacions.txt");
	if (!fitxerPuntuacio.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}

	while (!fitxerPuntuacio.eof() && (fitxerPuntuacio.is_open())) {


		fitxerPuntuacio;

	}

}
