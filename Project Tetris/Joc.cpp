#include "Joc.h"

Joc::Joc() 
{

}

void Joc::inicialitza(const string& nomFitxer)
{
	m_figura.inicialitzarFigura(nomFitxer);
	m_tauler.inicialitzarTauler(nomFitxer);
}

bool Joc::giraFigura(DireccioGir direccio)
{

}

bool Joc::mouFigura(int dirX)
{

}

int Joc::baixaFigura()
{

}

void Joc::escriuTauler(const string& nomFitxer)
{

}
