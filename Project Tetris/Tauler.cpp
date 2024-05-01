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

void Tauler::eliminarFilesCompletades(int filaEliminar)
{
	for (int i = filaEliminar; i >= 0; i--) {
		for (int j = 0; j < MAX_COL; j++) {
			if (i != 0) {
				setColorCasella(getCasellaRef(i, j), getCasella(i + 1, j));
			}
			else {
				setColorCasella(getCasellaRef(i, j), 0);
			}
		}
	}
}

int Tauler::columnaCompleta()
{
	int contador = 0;
	int filesEliminades = 0;

	for (int i = MAX_FILA - 1; i >= 0; i--) {
		for (int j = 0; j < MAX_COL; j++) {
			if (getCasella(i, j) != 0) {
				contador++;
			}
		}

		if (contador == MAX_COL) {
			eliminarFilesCompletades(i);
			filesEliminades++;
		}
		contador = 0;
	}
	return filesEliminades;
}

void Tauler::baixarFigura(Figura& figura)
{
	figura.setFila(figura.getFila() + 1);
}

void Tauler::desplacarLateral(Figura& figura, int direccio)
{
	figura.setColumna(figura.getColuma() + direccio);
}

bool Tauler::colisions(Figura figura, int fila, int columna)
{

	for (int i = 0; i <= figura.getLimit(); i++) {
		for (int j = 0; j <= figura.getLimit(); j++) {
			if (figura.getForma(i, j) != 0) {
				switch (figura.getFigura()) {
				case 1:
					if (((fila + i >= MAX_FILA) || (fila + i < 0) || (columna + j >= MAX_COL) ||
						(columna + j) < 0) || (getCasella(fila + i, columna + j) != 0)) {
						return true;
					}
					break;
				case 2:
					switch (figura.getPosicio4x4()) {
					case 0:
						if (((fila + i - 1 >= MAX_FILA) || (fila + i - 1 < 0) || (columna + j - 2 >= MAX_COL) ||
							(columna + j - 2) < 0) || (getCasella(fila + i - 1, columna + j - 2) != 0)) {
							return true;
						}
						break;
					case 1:
						if (((fila + i - 2 >= MAX_FILA) || (fila + i - 2 < 0) || (columna + j - 2 >= MAX_COL) ||
							(columna + j - 2) < 0) || (getCasella(fila + i - 2, columna + j - 2) != 0)) {
							return true;
						}
						break;
					case 2:
						if (((fila + i - 2 >= MAX_FILA) || (fila + i - 2 < 0) || (columna + j - 1 >= MAX_COL) ||
							(columna + j - 1) < 0) || (getCasella(fila + i - 2, columna + j - 1) != 0)) {
							return true;
						}
						break;
					case 3:
						if (((fila + i - 1 >= MAX_FILA) || (fila + i - 1 < 0) || (columna + j - 1 >= MAX_COL) ||
							(columna + j - 1) < 0) || (getCasella(fila + i - 1, columna + j - 1) != 0)) {
							return true;
						}
						break;
					default:
						cout << "ERROR" << endl;
						break;
					}
					break;
				case 3: case 4: case 5: case 6: case 7:
					if (((fila + i - 1 >= MAX_FILA) || (fila + i - 1 < 0) || (columna - 1 + j >= MAX_COL) ||
						(columna - 1 + j) < 0) || (getCasella(fila + i - 1, columna + j - 1) != 0)) {
						return true;
					}
					break;
				default:
					cout << "ERROR" << endl;
				}

			}
		}
	}
	return false;
}

void Tauler::eliminarFigura(Figura figura, int fila, int columna)
{
	for (int i = 0; i <= figura.getLimit(); i++) {
		for (int j = 0; j <= figura.getLimit(); j++) {
			if (figura.getForma(i, j) != 0) {
				switch (figura.getFigura()) {
				case 1:
					setColorCasella(getCasellaRef(fila + i - 1, columna + j), 0);
					break;
				case 2:
					switch (figura.getPosicio4x4()) {
					case 0:
						setColorCasella(getCasellaRef(fila + i - 1, columna + j - 2), 0);
					case 1:
						setColorCasella(getCasellaRef(fila + i - 2, columna + j - 2), 0);
					case 2:
						setColorCasella(getCasellaRef(fila + i - 2, columna + j - 1), 0);
					case 3:
						setColorCasella(getCasellaRef(fila + i - 1, columna + j - 1), 0);
					}
					break;
				case 3: case 4: case 5: case 6: case 7:
					setColorCasella(getCasellaRef(fila + i - 1, columna + j - 1), 0);
					break;
				default:
					cout << "ERROR" << endl;
					break;
				}
			}
		}
	}
}
