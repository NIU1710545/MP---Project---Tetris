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
