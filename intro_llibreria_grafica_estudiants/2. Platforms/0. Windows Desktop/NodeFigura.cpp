#include "NodeFigura .h"


void LlistaFigures::afegirFigura(int figura, int fila, int columna, int gir)
{
	NodeFigura* nouNode = new NodeFigura();
	nouNode->figura = figura;
	nouNode->fila = fila;
	nouNode->columna = columna;
	nouNode->gir = gir;
	nouNode->m_nextNode = nodeActual;

	nodeActual = nouNode;
}