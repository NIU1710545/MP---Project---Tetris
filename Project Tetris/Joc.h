#ifndef JOC_H
#define JOC_H
#include "Tauler.h"
#include "Figura.h"
#include <string>
#include <fstream>
using namespace std;

class Joc
{
public:
	Joc();
	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

	Tauler getTauler() { return m_tauler; }
	Figura getFigura() { return m_figura; }

	void setTauler(const Tauler& tauler) { m_tauler = tauler; }
	void setFigura(const Figura& figura) { m_figura = figura; }

private:
	Tauler m_tauler;
	Figura m_figura;

};


/* 
 - Ha de servir per poder gestionar el funcionament global del joc
 - Ha de poder guardar i gestionar el tauler de joc (utilitzant la classe Tauler), la figura actual que 
   està caient (utilitzant la classe Figura), la informació de l’estat de la partida (puntuació, nivell, 
   etc. ) i qualsevol altra informació que considereu necessària per gestionar la partida.
*/

#endif