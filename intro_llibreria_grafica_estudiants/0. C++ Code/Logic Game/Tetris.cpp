#include "Tetris.h"
#include "fsrmscreen.h"

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



