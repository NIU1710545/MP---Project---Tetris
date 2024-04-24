#include "Figura.h"
#include <iostream>
#include <fstream>

using namespace std;

// Gir en sentit horari - Moviment del lliurament

void Figura::girarFigura(int gir, int area)
{
	if (gir != 4 && (gir != 0)) {
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


void Figura::inicialitzarFigura(const string nomFitxer)
{

	int figura, fila, columna, gir;

	ifstream fitxerLectura;
	fitxerLectura.open(nomFitxer);

	fitxerLectura >> figura >> fila >> columna >> gir;
	
	fitxerLectura.close();


	switch (figura) {
	case 1: 
		m_area = 2;
		break;
	case 2:
		m_area = 4;
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		m_area = 3;
		break;
	default:
		cout << "Error." << endl;
		break;
	}

	ifstream fitxerFigura;

	fitxerFigura.open("FormaFigura.txt");
	while (!fitxerFigura.eof()) {
		int numForma;

		fitxerFigura >> numForma;

		while (numForma != figura) {
			for (int i = 0; i < m_area; i++) {
				for (int j = 0; j < m_area; j++) {
					fitxerFigura >> m_forma[i][j];
				}
			}
			fitxerFigura >> numForma;
		}
	}
	fitxerFigura.close();

	girarFigura(gir, m_area);
}


Figura::Figura(TipusFigura figura, ColorFigura color)
{
	m_figura = figura;
	m_color = color;
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