#include "Tauler.h"
#include <iostream>
#include <fstream>

using namespace std;

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			m_tauler[i][j] = NO_COLOR;
		}
	}
}

Tauler::~Tauler() {}

void Tauler::setColorCasella(ColorFigura& casella, int colorCasella)
{
	switch (colorCasella) {
	case 0:
		casella = COLOR_NEGRE;
		break;
	case 1:
		casella = COLOR_GROC;
		break;
	case 2:
		casella = COLOR_BLAUCEL;
		break;
	case 3:
		casella = COLOR_MAGENTA;
		break;
	case 4:
		casella = COLOR_TARONJA;
		break;
	case 5:
		casella = COLOR_BLAUFOSC;
		break;
	case 6:
		casella = COLOR_VERMELL;
		break;
	case 7:
		casella = COLOR_VERD;
		break;

	default:
		cout << "ERROR" << endl;
		break;
	}
}

void Tauler::inicialitzarTauler(string nomFitxer) 
{
	ifstream fitxerLectura(nomFitxer);
	if (!fitxerLectura.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}


	int fila[MAX_COL]{};
	while (!fitxerLectura.eof() && (fitxerLectura.is_open())) {

		for (int i = 0; i < MAX_FILA + 1; i++) {

			if (i != 0) {
				for (int j = 0; j < MAX_COL; j++) {
					fitxerLectura >> fila[j];
				}

				for (int j = 0; j < MAX_COL; j++) {
					setColorCasella(m_tauler[i - 1][j], fila[j]);
				}
			}
			else {
				for (int j = 0; j < 4; j++) {
					fitxerLectura >> fila[j];
				}
			}

		}
		fitxerLectura.close();
	}
}

bool colocarFigura(Figura figura, int fila, int columna)
{

}

bool moureFigura(Figura figura, int columna)
{

}

bool girarFigura(Figura figura)
{

}

void eliminarFilesCompletades()
{

}

bool taulerPle()
{

}
