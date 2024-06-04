#include "Tauler.h"
#include "GraphicManager.h"
#include "InfoJoc.h"
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

void Tauler::dibuixa()
{
	GraphicManager* gManager = GraphicManager::getInstance();

	for (int i = 0; i <= MAX_FILA-1; i++) {
		for (int j = 0; j <= MAX_COL-1; j++) {
			
			int color = getCasellaRef(i, j);
			if (color != COLOR_NEGRE) {
				switch (color) {
				case COLOR_GROC:
					gManager->drawSprite(GRAFIC_QUADRAT_GROC,
						POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
					break;
				case COLOR_BLAUCEL:
					gManager->drawSprite(GRAFIC_QUADRAT_BLAUCEL,
						POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
					break;
				case COLOR_MAGENTA:
					gManager->drawSprite(GRAFIC_QUADRAT_MAGENTA,
						POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
					break;
				case COLOR_TARONJA:
					gManager->drawSprite(GRAFIC_QUADRAT_TARONJA,
						POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
					break;
				case COLOR_BLAUFOSC:
					gManager->drawSprite(GRAFIC_QUADRAT_BLAUFOSC,
						POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
					break;
				case COLOR_VERMELL:
					gManager->drawSprite(GRAFIC_QUADRAT_VERMELL,
						POS_X_TAULER + ((j + 1) * MIDA_QUADRAT), POS_Y_TAULER + (i * MIDA_QUADRAT), false);
					break;
				case COLOR_VERD:
					gManager->drawSprite(GRAFIC_QUADRAT_VERD,
						POS_X_TAULER + ((j+1) * MIDA_QUADRAT), POS_Y_TAULER + ( i * MIDA_QUADRAT), false);
					break;
				}
			}
		}
	}
}


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
					setColorCasella(m_tauler[i-1][j], fila[j]);
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


void Tauler::inicialitzarTaulerActaul(const string& nomFitxer)
{
	ifstream fitxerLectura(nomFitxer);
	if (!fitxerLectura.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}

	int fila[MAX_COL]{};
	while (!fitxerLectura.eof() && (fitxerLectura.is_open())) {

		for (int i = 0; i < MAX_FILA ; i++) {

			for (int j = 0; j < MAX_COL; j++) {
				fitxerLectura >> fila[j];
			}
			for (int j = 0; j < MAX_COL; j++) {
				setColorCasella(m_tauler[i ][j], fila[j]);
			}

		}
		fitxerLectura.close();
	}
}

void Tauler::baixarFigura(Figura& figura)
{
	figura.setFila(figura.getFila() + 1);
}

void Tauler::desplacarLateral(Figura& figura, int direccio)
{
	figura.setColumna(figura.getColumna() + direccio);
}

bool Tauler::colisions(Figura figura, int fila, int columna)
{

	for (int i = 0; i <= figura.getLimit(); i++) {
		for (int j = 0; j <= figura.getLimit(); j++) {
			if (figura.getForma(i, j) != 0) {
				switch (figura.getFigura()) {
				case 1:
					if (((fila + i >= MAX_FILA) || (fila + i < 0) || (columna + j -1>= MAX_COL) ||
						(columna + j-1) < 0) || (getCasella(fila + i, columna + j) != 0)) {
						return true;
					}
					break;
				case 2: case 3: case 4: case 5: case 6: case 7:
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

