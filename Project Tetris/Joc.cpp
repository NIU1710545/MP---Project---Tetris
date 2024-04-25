#include "Joc.h"

Joc::Joc() 
{

}

Joc::~Joc() {}

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
	return m_figura.desplacamentLateral(dirX);
}

int Joc::baixaFigura()
{
	return m_figura.baixar();
}

void Joc::escriuTauler(const string& nomFitxer)
{
	ofstream fitxer(nomFitxer);
	if (fitxer.is_open()) {
		m_tauler.escriuTauler(fitxer);
		fitxer.close();
	}
}
