#include "Tauler.h"

void Tauler::inicialitzarTauler()
{
	/* 0 -> No hi ha figura || -1 -> Limit del tauler

	for (int i = 0; i < MAX_FILA; i++) {
		for (int j = 0; j < MAX_COL; j++) {

			if ((i == 0) || (i == MAX_FILA - 1)) {
				m_tauler[i][j] = NO_COLOR;
			}
			else {
				if ((j == 0) || (j == MAX_COL - 1)) {
					m_tauler[i][j] = NO_COLOR;
				}
				else {
					m_tauler[i][j] = COLOR_NEGRE;
				}
			}

		}
	}
	*/

	for (int i = 0; i < MAX_FILA; i++) {
		for (int j = 0; j < MAX_COL; j++) {
		}
	}



}

Tauler::Tauler()
{
	inicialitzarTauler();
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
