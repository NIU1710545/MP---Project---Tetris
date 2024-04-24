#include "Tauler.h"
#include <iostream>
#include <fstream>

using namespace std;

void Tauler::inicialitzarTauler(string nomFitxer) const 
{
	/* 0 -> No hi ha figura || -1 -> Limit del tauler*/

	ifstream fitxer;

	fitxer.open(nomFitxer);

	while ((fitxer.eof()) && (fitxer.is_open())) {
		int casella;
		fitxer >> casella;

		for (int i = 1; i < MAX_FILA; i++) {
			for (int j = 0; j < MAX_COL; j++) {
				fitxer >> m_tauler[i][j];
			}
		}

		fitxer.close();
	}
}

Tauler::Tauler()
{
	for (int i = 0; i < MAX_FILA; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			m_tauler[i][j] = 0;
		}
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
