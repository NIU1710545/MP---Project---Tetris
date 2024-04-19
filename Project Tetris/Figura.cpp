#include "Figura.h"
#include <iostream>
#include <fstream>


using namespace std;

void Figura::inicialitzacioForma(TipusFigura forma)
{
	switch (forma) {
	case 1: 
		m_columna = 2;
		m_fila = 2;
	case 2:
		m_columna = 4;
		m_fila = 4;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		m_columna = 3;
		m_fila = 3;
	default:
		cout << "Error." << endl;
	}
	ifstream fitxerFigura;

	fitxerFigura.open(nomFitxer);
	while (!fitxerFigura.eof() && (fitxerFigura.is_open())) {
		int numForma;

		fitxerFigura >> numForma;

		while (numForma != forma) {
			for (int i = 0; i < m_fila; i++) {
				for (int j = 0; j < m_columna; j++) {
					fitxerFigura >> m_forma[i][j];
				}
			}
			fitxerFigura >> numForma;
		}

		fitxerFigura.close();
	}
}



Figura::Figura(TipusFigura figura, ColorFigura color)
{
	m_figura = figura;
	m_color = color;
	nomFitxer = "FormaFigures.txt";
	inicialitzacioForma(figura);
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