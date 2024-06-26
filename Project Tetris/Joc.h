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
	Joc() {}

	void inicialitza(const string& nomFitxer);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);


private:
	Tauler m_tauler;
	Figura m_figura;
	int puntuacio = 0;
	int filesCompletes = 0;

	void colocaFigura(int nfigura);
	int determinarFigura(int figura);
	int eliminarFilaCompleta();
};


/* 
 - Ha de servir per poder gestionar el funcionament global del joc
 - Ha de poder guardar i gestionar el tauler de joc (utilitzant la classe Tauler), la figura actual que 
   est� caient (utilitzant la classe Figura), la informaci� de l�estat de la partida (puntuaci�, nivell, 
   etc. ) i qualsevol altra informaci� que considereu necess�ria per gestionar la partida.
*/

#endif