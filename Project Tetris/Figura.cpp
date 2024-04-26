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

void Figura::inicialitzarFigura(const string& nomFitxer)
{

	int figura, fila, columna, gir;

	ifstream fitxerLectura;
	fitxerLectura.open(nomFitxer);

	fitxerLectura >> figura >> fila >> columna >> gir;
	
	fitxerLectura.close();

	int area = 0;

	switch (figura) {
	case 1: 
		area = 2;
		break;
	case 2:
		area = 4;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		area = 3;
		break;
	default:
		cout << "Error." << endl;
		break;
	}

	ifstream fitxerFigura;

	fitxerFigura.open("FormaFigura.txt");

	if (!fitxerFigura.is_open()) {
		cout << "ERROR. Lectura - FormaFigura.txt;" << endl;
		return;
	}

	while (!fitxerFigura.eof()) {
		int numForma;

		fitxerFigura >> numForma;
		while (!fitxerFigura.eof()) {
			int numForma;

			fitxerFigura >> numForma;

			while (numForma != figura) {
				for (int i = 0; i < area; i++) {
					for (int j = 0; j < area; j++) {
						fitxerFigura >> m_forma[i][j];
					}
				}
				fitxerFigura >> numForma;
			}
		}
	}
	fitxerFigura.close();

	girarFigura(gir, area);
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