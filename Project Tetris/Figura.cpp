#include "Figura.h"
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


Figura::~Figura() {}

// Gir en sentit horari - Moviment del lliurament

void Figura::girarFigura(int gir, int area)
{
	if (gir != 0) {
		int temp[MAX_AMPLADA][MAX_AMPLADA];
		// Quantitats de gir
		for (int x = 0; x < gir; x++) {

			for (int i = 0; i < area; i++) { // Fila
				for (int j = 0; j < area; j++) { // Columna
					temp[i][j] = m_forma[j][area - 1 - i];
				}
			}

			for (int i = 0; i < area; i++) { // Fila
				for (int j = 0; j < area; j++) { // Columna
					m_forma[i][j] = temp[area - j - 1][j];
				}
			}
		}
	}

}


void Figura::setColor(int color)
{
	int intColor = 0;
	switch (color) {
	case 1:
		m_color = COLOR_GROC;
	case 2:
		m_color = COLOR_BLAUCEL;
	case 3:
		m_color = COLOR_MAGENTA;
	case 4:
		m_color = COLOR_TARONJA;
	case 5:
		m_color = COLOR_BLAUFOSC;
	case 6:
		m_color = COLOR_VERMELL;
	case 7:
		m_color = COLOR_VERD;
	default:
		cout << "ERROR" << endl;
	}
}

void Figura::setFigura(int figura)
{
	switch (figura) {
	case 1:
		m_figura = FIGURA_O;
	case 2:
		m_figura = FIGURA_I;
	case 3:
		m_figura = FIGURA_T;
	case 4:
		m_figura = FIGURA_L;
	case 5:
		m_figura = FIGURA_J;
	case 6:
		m_figura = FIGURA_Z;
	case 7:
		m_figura = FIGURA_S;
	default:
		cout << "ERROR" << endl;
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

	ifstream fitxerFigura("FormaFigura.txt");
	if (!fitxerFigura.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}
	
	while (!fitxerFigura.eof() && (fitxerFigura.is_open())) {
		int forma[MAX_CASELLES];

		int numCaselles = numCasellesFigura(figura);

		int j = 0;

		while (j <= figura) {
			for (int i = 0; i < numCaselles; i++) {
				fitxerFigura >> forma[i];
			}
			j++;
		}
		fitxerFigura.close();
	}

	setColor(figura);
	setFigura(figura);
}


void desplacamentLateral(int columna)
{

}

void baixar(int fila)
{

}

void girar()
{

}