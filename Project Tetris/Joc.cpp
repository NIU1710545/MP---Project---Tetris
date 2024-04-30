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
	filesCompletes = 0;

	m_tauler.eliminarFigura(m_figura, m_figura.getFila(), m_figura.getColuma());
	int columna = m_figura.getColuma() + dirX;
	if (!m_tauler.colisions(m_figura, m_figura.getFila(), columna)) {
		m_tauler.desplacarLateral(m_figura, dirX);
		colocaFigura(determinarFigura(m_figura.getFigura()));
		filesCompletes = m_tauler.columnaCompleta();
		return true;
	}
	else {
		colocaFigura(determinarFigura(m_figura.getFigura()));
		return false;
	}
}

int Joc::baixaFigura()
{
	filesCompletes = 0;
	// La figura ha de baixar una casella cada cert temps.
	m_tauler.eliminarFigura(m_figura, m_figura.getFila(), m_figura.getColuma());
	int fila = m_figura.getFila() + 1;
	if (!m_tauler.colisions(m_figura, fila, m_figura.getColuma())) {
		m_tauler.baixarFigura(m_figura);
		colocaFigura(determinarFigura(m_figura.getFigura()));
		filesCompletes = m_tauler.columnaCompleta();
	}
	else {
		colocaFigura(determinarFigura(m_figura.getFigura()));
		filesCompletes = m_tauler.columnaCompleta();
	}

	return filesCompletes;
}

void Joc::colocaFigura(int nfigura)
{
	int fila = m_figura.getFila() ;
	int columna = m_figura.getColuma() ;
	int forma[MAX_ALCADA][MAX_AMPLADA]{};


	for (int i = 0; i < MAX_ALCADA; i++) {
		for (int j = 0; j < MAX_AMPLADA; j++) {
			forma[i][j] = m_figura.getForma(i, j);
		}
	}

	for (int i = 0; i <= m_figura.getLimit(); i++) {
		for (int j = 0; j <= m_figura.getLimit(); j++) {
			if (m_figura.getForma(i, j) != 0) {
				switch (nfigura) {
				case 2:
					m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i, columna + j), m_figura.getForma(i, j));
					break;
				case 3:
					m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i - 1, columna + j - 1), m_figura.getForma(i, j));
					break;
				case 4:
					switch (m_figura.getPosicio4x4()) {
					case 0:
						m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i - 1, columna + j - 2), m_figura.getForma(i, j));
						break;
					case 1:
						m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i - 2, columna + j - 2), m_figura.getForma(i, j));
						break;
					case 2:
						m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i - 2, columna + j - 1), m_figura.getForma(i, j));
						break;
					case 3:
						m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i - 1, columna + j - 1), m_figura.getForma(i, j));
						break;
					default:
						cout << "ERRRO" << endl;
						break;
					}
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
