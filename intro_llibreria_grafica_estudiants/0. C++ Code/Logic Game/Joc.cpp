#include "Joc.h"


void Joc::inicialitza(const string& nomFitxer, int mode)
{
	if (mode == 1) {
		novaFigura();
		m_tauler.inicialitzarTaulerActaul(nomFitxer);
	}
	else {
		m_figura.inicialitzarFigura(nomFitxer);
		m_tauler.inicialitzarTauler(nomFitxer);
	}
}

void Joc::dibuixa()
{
	m_tauler.dibuixa();
	m_figura.dibuixa();
}

void Joc::novaFigura(const string & nomFitxer)
{
	m_figura.inicialitzarFigura(nomFitxer);
}

void Joc::seleccionarNovaFigura(int& nFigura)
{
	do {
		nFigura = rand() % 7;
	} while (figuraSortir[nFigura] || (nFigura == 0));
	figuraSortir[nFigura] = true;
	nFiguresSortir++;
}

void Joc::reiniciarFigures()
{
	for (int i = 0; i < 7; i++) {
		figuraSortir[i] = false;
	}
	nFiguresSortir = 0;
}

void Joc::novaFigura()
{
	int numFigura = -1;
	int numGir = rand() % 4;
	
	if (nFiguresSortir == 7) {
		reiniciarFigures();
	}
	seleccionarNovaFigura(numFigura);

	ofstream fitxerNovaFigura("NovaFigura.txt");
	if (!fitxerNovaFigura.is_open()) {
		cout << "ERROR. Escriptura" << endl;
		return;
	}
	else {
		fitxerNovaFigura << numFigura << " " << 1 << " " << 5 << " " << numGir;
	}
	fitxerNovaFigura.close();

	m_figura.inicialitzarFigura("NovaFigura.txt");

}

void Joc::nouTauler(const string& nomFitxer)
{
	m_tauler.inicialitzarTaulerActaul(nomFitxer);
}

void Joc::baixaFiguraCop()
{
	while (!m_tauler.colisions(m_figura, m_figura.getFila() + 1, m_figura.getColumna())) {
		m_tauler.baixarFigura(m_figura);
	}
}

bool Joc::comprovaTaulerPle()
{
	for (int i = 0; i < N_COL_TAULER; i++) {
		if (m_tauler.getCasellaRef(i, 0) != 0) {
			return true;
		}
	}
}

bool Joc::giraFigura(DireccioGir direccio)
{
	int dir = -1;
	int contrari = -1;
	if (direccio == 0) {
		dir = 0;
	}
	else {
		contrari = 0;
	}

	m_figura.girarFigura(1, m_figura.getLimit(), dir);
	if (!m_tauler.colisions(m_figura, m_figura.getFila(), m_figura.getColumna())) {
		return true;
	}
	else {
		m_figura.girarFigura(1, m_figura.getLimit(), contrari);
		return false;
	}
}

bool Joc::mouFigura(int dirX)
{
	filesCompletes = 0;

	int columna = m_figura.getColumna() + dirX;
	if (!m_tauler.colisions(m_figura, m_figura.getFila(), columna)) {
		m_tauler.desplacarLateral(m_figura, dirX);
		return true;
	}
	else {
		return false;
	}
}

int Joc::baixaFigura()
{
	filesCompletes = 0;

	// La figura ha de baixar una casella cada cert temps.
	int fila = m_figura.getFila() + 1;
	if (!m_tauler.colisions(m_figura, fila, m_figura.getColumna())) {
		m_tauler.baixarFigura(m_figura);
	}
	else {
		colocada = true;
	}

	return filesCompletes;
}

void Joc::colocaFigura(int nfigura)
{
	int fila = m_figura.getFila() ;
	int columna = m_figura.getColumna();
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
					m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i, columna + j-1), m_figura.getForma(i, j));
					break;
				case 3: case 4:
					m_tauler.setColorCasella(m_tauler.getCasellaRef(fila + i - 1, columna + j - 1), m_figura.getForma(i, j));
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

int Joc::eliminarFilaCompleta()
{
	int filesCompletes = 0;
	int files[MAX_FILA]{ -1 };


	for (int i = MAX_FILA - 1; i >= 0; i--) {
		bool filaCompleta = true;

		for (int j = 0; j < MAX_COL; j++) {
			if (m_tauler.getCasella(i, j) == 0) {
				filaCompleta = false;
				break;
			}
		}

		if (filaCompleta) {
			filesCompletes++;
			// Si la fila [i] està completa l'eliminem i les de dalt baixen 
			for (int k = i; k >= 0; k--) {
				for (int j = 0; j < MAX_COL; j++) {
					if (k != 0) {
						m_tauler.setColorCasella(m_tauler.getCasellaRef(k, j), m_tauler.getCasella(k - 1, j));
					}
					else {
						m_tauler.setColorCasella(m_tauler.getCasellaRef(k, j), 0);
					}

				}
			}
			i = MAX_FILA;
		}
	}

	return filesCompletes;
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxerEscriure(nomFitxer);
	if (!fitxerEscriure.is_open()) {
		cout << "ERROR. Escriptura";
		return;
	}

	colocaFigura(determinarFigura(m_figura.getFigura()));
	filesCompletes = eliminarFilaCompleta();

	for (int i = 0; i < MAX_FILA; i++) {
		for (int j = 0; j < MAX_COL; j++) {
			fitxerEscriure << m_tauler.getCasella(i, j) << " ";
		}
		fitxerEscriure << endl;
	}

	fitxerEscriure.close();

}
