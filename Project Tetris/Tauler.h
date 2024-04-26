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
	void setColorCasella(ColorFigura casella, int colorCasella);

	bool colocarFigura(Figura figura, int fila, int columna);
	bool moureFigura(Figura figura, int columna);
	bool girarFigura(Figura figura);
	void eliminarFilesCompletades();
	bool taulerPle() const;

	void escriuTauler(ostream& nomFitxer) const;


private:
	ColorFigura m_tauler[MAX_FILA][MAX_COL];

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