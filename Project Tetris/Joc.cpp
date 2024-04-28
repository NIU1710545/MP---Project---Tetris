#include "Joc.h"


void Joc::inicialitza(const string& nomFitxer)
{
	m_figura.inicialitzarFigura(nomFitxer);
	m_tauler.inicialitzarTauler(nomFitxer);
}

bool Joc::giraFigura(DireccioGir direccio)
{
	return m_figura.girarFigura(direccio);
}

bool Joc::mouFigura(int dirX)
{
	return true;
}

int Joc::baixaFigura()
{
	return 0;
}

void Joc::colocaFigura(int nfigura)
{
	int fila = m_figura.getFila() - 1;
	int columna = m_figura.getColuma() - 1;
	int forma[MAX_ALCADA][MAX_AMPLADA]{};


	for (int i = 0; i < MAX_ALCADA; i++) {
		for (int j = 0; j < MAX_AMPLADA; j++) {
			forma[i][j] = m_figura.getForma(i, j);
		}
	}

	for (int i = 0; i < MAX_ALCADA; i++) {
		for (int j = 0; j < MAX_AMPLADA; j++) {
			if (m_figura.getForma(i, j) != 0) {
				switch (nfigura) {
				case 2:
					m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i, columna + j), m_figura.getForma(i, j));
					break;
				case 3:
					m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i - 1, columna + j - 1), m_figura.getForma(i, j));
					break;
				case 4:// Comrpovar si hi ha alguna manera de fer el 4x4, sense fer una versió diferent per a cada posició de la figura
					break;
				default:
					cout << "ERROR" << endl;
					break;
				}
			}
		}
	}
}

int Joc::determinarFigura(int figura)
{
	int area = -1;
	switch (figura) {
	case 1:
		area = 2;
		break;
	case 2:
		area = 4;
		break;
	case 3: case 4:	case 5: case 6:	case 7:
		area = 3;
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
	return area;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxerEscriure(nomFitxer);
	if (!fitxerEscriure.is_open()) {
		cout << "ERROR. Escriptura";
		return;
	}

	colocaFigura(determinarFigura(m_figura.getFigura()));

	for (int i = 0; i < MAX_FILA; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			fitxerEscriure << m_tauler.getCasella(i, j) << " ";
		}
		fitxerEscriure << endl;
	}

	fitxerEscriure.close();
}
