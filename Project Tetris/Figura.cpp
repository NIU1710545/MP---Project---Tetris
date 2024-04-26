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

int Figura::numCasellesFigura(int figura, int& limit)
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

void girarFigura(int figura[][MAX_AMPLADA], int gir, int limit, int direccio)
{
	int temp[MAX_ALCADA][MAX_AMPLADA];

	for (int i = 0; i < gir; i++) {

		if (direccio == 0) {
			for (int j = 0; j < MAX_ALCADA; j++) {
				for (int k = 0; k < MAX_AMPLADA; k++) {
					temp[k][limit - j] = figura[j][k];
				}
			}

			for (int j = 0; j < MAX_ALCADA; j++) {
				for (int k = 0; k < MAX_AMPLADA; k++) {
					figura[j][k] = temp[j][k];
				}
			}

		}
		else {
			for (int j = 0; j < MAX_ALCADA; j++) {
				for (int k = 0; k < MAX_AMPLADA; k++) {
					temp[limit - k][j] = figura[j][k];
				}
			}

			for (int j = 0; j < MAX_ALCADA; j++) {
				for (int k = 0; k < MAX_AMPLADA; k++) {
					figura[j][k] = temp[j][k];
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

	ifstream fitxerFigura("FormaFigura.txt");
	if (!fitxerFigura.is_open()) {
		cout << "ERROR. Lectura" << endl;
		return;
	}
	
	int limit = -1;
	int forma[MAX_CASELLES]{};
	while (!fitxerFigura.eof() && (fitxerFigura.is_open())) {

		int numCaselles = numCasellesFigura(figura, limit);

		int j = 0;

		while (j <= figura) {
			for (int i = 0; i < numCaselles; i++) {
				fitxerFigura >> forma[i];
			}
			j++;
		}
		fitxerFigura.close();
	}

	int x = 0;
	for (int i = 0; i < MAX_ALCADA; i++) {
		for (int j = 0; j < MAX_AMPLADA; j++) {
			m_forma[i][j] = forma[x];
			x++;
		}
	}

	girarFigura(m_forma, gir, limit, 0);

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