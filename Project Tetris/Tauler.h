#ifndef TAULER_H
#define TAULER_H
#include "Figura.h"


const int MAX_FILA = 8;
const int MAX_COL = 8;

class Tauler
{
public:
	Tauler();
	~Tauler();


	void inicialitzarTauler(string nomFitxer);
	void baixarFigura(Figura& figura);
	void desplacarLateral(Figura& figura, int direccio);

	bool colisions(Figura figura, int fila, int columna);

	ColorFigura getCasella(int i, int j) const { return m_tauler[i][j]; }
	ColorFigura& getCasellaRef(int i, int j) { return m_tauler[i][j]; }
	void setColorCasella(ColorFigura& casella, int colorCasella);

private:
	ColorFigura m_tauler[MAX_FILA][MAX_COL];

	void eliminarFilesCompletades(int filaEliminar);
};

/*
 - Ha de servir per poder gestionar el tauler de joc. 
 - Ha de poder guardar quines caselles del tauler estan ocupades per figures ja col·locades i per la 
   figura actual que està caient. 
 - Ha de tenir tots els mètodes necessaris per poder comprovar que els moviments i girs de la 
   figura són vàlids, col·locar la figura a la seva posició final i eliminar les files que es van 
   completant. 
 - Penseu bé quins mètodes públics ha de tenir aquesta classe. Poseu només com a mètodes 
   públics els que sigui necessari utilitzar des de la classe Joc. 
 - Si és necessari, descomposeu els mètodes públics en altres mètodes més simples. Definiu com 
   a privats aquests mètodes auxiliars.
*/


#endif