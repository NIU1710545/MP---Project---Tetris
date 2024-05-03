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
 - Ha de poder guardar quines caselles del tauler estan ocupades per figures ja col�locades i per la 
   figura actual que est� caient. 
 - Ha de tenir tots els m�todes necessaris per poder comprovar que els moviments i girs de la 
   figura s�n v�lids, col�locar la figura a la seva posici� final i eliminar les files que es van 
   completant. 
 - Penseu b� quins m�todes p�blics ha de tenir aquesta classe. Poseu nom�s com a m�todes 
   p�blics els que sigui necessari utilitzar des de la classe Joc. 
 - Si �s necessari, descomposeu els m�todes p�blics en altres m�todes m�s simples. Definiu com 
   a privats aquests m�todes auxiliars.
*/


#endif