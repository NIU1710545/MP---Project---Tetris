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

	void inicialitza(const string& nomFitxer, int mode);
	bool giraFigura(DireccioGir direccio);
	bool mouFigura(int dirX);
	int baixaFigura();
	void escriuTauler(const string& nomFitxer);

	void dibuixa();
	void novaFigura(const string& nomFitxer);
	void novaFigura();
	void nouTauler(const string& nomFitxer);
	void baixaFiguraCop();

	void setColocada(bool resultat) { colocada = resultat; }

	int getfilesCompletes() const { return filesCompletes; }
	bool getColocada() const { return colocada; }

private:
	Tauler m_tauler;
	Figura m_figura;
	int puntuacio = 0;
	int filesCompletes = 0;
	bool colocada = false;

	void colocaFigura(int nfigura);
	int determinarFigura(int figura);
	int eliminarFilaCompleta();
};


/* 
 - Ha de servir per poder gestionar el funcionament global del joc
 - Ha de poder guardar i gestionar el tauler de joc (utilitzant la classe Tauler), la figura actual que 
   està caient (utilitzant la classe Figura), la informació de l’estat de la partida (puntuació, nivell, 
   etc. ) i qualsevol altra informació que considereu necessària per gestionar la partida.
*/

#endif