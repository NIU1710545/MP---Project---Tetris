#include "Figura.h"
#include "GraphicManager.h"
#include "InfoJoc.h"
#include <iostream>
#include <fstream>

using namespace std;

Figura::Figura() : m_figura(NO_FIGURA), m_color(NO_COLOR), m_columna(0), m_fila(0), m_forma()
{
	for (int i = 0; i < MAX_ALCADA; i++) {
		for (int j = 0; j < MAX_AMPLADA; j++) {
			m_forma[i][j] = -1;
		}
	}
}

void Figura::dibuixa()
{
	GraphicManager* gManager = GraphicManager::getInstance();


	for (int i = 0; i <= getLimit(); i++) {
		for (int j = 0; j <= getLimit(); j++) {

			if (m_forma[i][j] != 0) {
				int color = getColor();
				switch (color) {
				case COLOR_GROC:
					gManager->drawSprite(GRAFIC_QUADRAT_GROC,
						POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);
					break;
				case COLOR_BLAUCEL:
					gManager->drawSprite(GRAFIC_QUADRAT_BLAUCEL,
						POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);
					break;
				case COLOR_MAGENTA:
					gManager->drawSprite(GRAFIC_QUADRAT_MAGENTA,
						POS_X_TAULER + ((m_columna+ j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_fila+i - 1) * MIDA_QUADRAT), false);
					break;
				case COLOR_TARONJA:
					gManager->drawSprite(GRAFIC_QUADRAT_TARONJA,
						POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);
					break;
				case COLOR_BLAUFOSC:
					gManager->drawSprite(GRAFIC_QUADRAT_BLAUFOSC,
						POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);
					break;
				case COLOR_VERMELL:
					gManager->drawSprite(GRAFIC_QUADRAT_VERMELL,
						POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);
					break;
				case COLOR_VERD:
					gManager->drawSprite(GRAFIC_QUADRAT_VERD,
						POS_X_TAULER + ((m_columna + j) * MIDA_QUADRAT), POS_Y_TAULER + ((m_fila + i - 1) * MIDA_QUADRAT), false);
					break;

				}
			}
		}
	}
}

int Figura::determinarLimit(int figura)
{
	int n_caselles = -1;
	switch (figura) {
	case 1:
		n_caselles = 4;
		limit = 1;
		break;
	case 2:
		n_caselles = 16;
		limit = 3;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		n_caselles = 9;
		limit = 2;
		break;
	default:
		cout << "Error." << endl;
		break;
	}
	return n_caselles;
}

void Figura::setColor(int color)
{
	switch (color) {
	case 1:
		m_color = COLOR_GROC;
		break;
	case 2:
		m_color = COLOR_BLAUCEL;
		break;
	case 3:
		m_color = COLOR_MAGENTA;
		break;
	case 4:
		m_color = COLOR_TARONJA;
		break;
	case 5:
		m_color = COLOR_BLAUFOSC;
		break;
	case 6:
		m_color = COLOR_VERMELL;
		break;
	case 7:
		m_color = COLOR_VERD;
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
}

void Figura::setFigura(int figura)
{
	switch (figura) {
	case 1:
		m_figura = FIGURA_O;
		break;
	case 2:
		m_figura = FIGURA_I;
		break;
	case 3:
		m_figura = FIGURA_T;
		break;
	case 4:
		m_figura = FIGURA_L;
		break;
	case 5:
		m_figura = FIGURA_J;
		break;
	case 6:
		m_figura = FIGURA_Z;
		break;
	case 7:
		m_figura = FIGURA_S;
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
}

void Figura::girarFigura(int gir, int limit, int direccio)
{
	int temp[MAX_ALCADA][MAX_AMPLADA]{};

	for (int i = 0; i < gir; i++) {

		if (direccio == 0) {
			for (int j = 0; j <= limit; j++) {
				for (int k = 0; k <= limit; k++) {
					temp[k][limit - j] = m_forma[j][k];
				}
			}

			for (int j = 0; j < MAX_ALCADA; j++) {
				for (int k = 0; k < MAX_AMPLADA; k++) {
					m_forma[j][k] = temp[j][k];
				}
			}

		}
		else {
			for (int j = 0; j <= limit; j++) {
				for (int k = 0; k <= limit; k++) {
					temp[limit - k][j] = m_forma[j][k];
				}
			}

			for (int j = 0; j < MAX_ALCADA; j++) {
				for (int k = 0; k < MAX_AMPLADA; k++) {
					m_forma[j][k] = temp[j][k];
				}
			}
		}
	}
}



void Figura::inicialitzarFigura(const string& nomFitxer)
{

	int figura, fila, columna, gir;

	ifstream fitxerLectura(nomFitxer);
	if (!fitxerLectura.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}

	fitxerLectura >> figura >> fila >> columna >> gir;	
	fitxerLectura.close();

	m_fila = fila;
	m_columna = columna;

	/*
	ifstream fitxerFigura("FormaFigures.txt");
	if (!fitxerFigura.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}

	
	int forma[MAX_CASELLES]{};
	while (!fitxerFigura.eof() && (fitxerFigura.is_open())) {

		int numCaselles = numCasellesFigura(figura, limit);

		int j = 0;

		while (j < figura) {
			for (int i = 0; i < MAX_CASELLES; i++) {
				fitxerFigura >> forma[i];
			}
			j++;
		}
		fitxerFigura.close();
	}
	*/

	
	int Parts[7][4][4]
	{
		{
			{ 1, 1, 0, 0 },
			{ 1, 1, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		},
		{
			{ 0, 0, 0, 0 },
			{ 2, 2, 2, 2 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		},
		{
			{ 0, 3, 0, 0 },
			{ 3, 3, 3, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		},
		{
			{ 0, 0, 4, 0 },
			{ 4, 4, 4, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		},
		{
			{ 5, 0, 0, 0 },
			{ 5, 5, 5, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		},
		{
			{ 6, 6, 0, 0 },
			{ 0, 6, 6, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		},
		{
			{ 0, 7, 7, 0 },
			{ 7, 7, 0, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 },
		}

	};


	determinarLimit(figura);

	for (int j = 0; j < MAX_ALCADA; j++) {
		for (int k = 0; k < MAX_AMPLADA; k++) {
			m_forma[j][k] = Parts[figura - 1][j][k];
		}
	}

	setColor(figura);
	setFigura(figura);
	girarFigura(gir, limit, 0);

}

