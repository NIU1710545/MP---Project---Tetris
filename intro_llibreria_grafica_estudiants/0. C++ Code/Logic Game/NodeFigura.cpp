#include "NodeFigura.h"


void LlistaFigures::afegirFigura(int figura, int fila, int columna, int gir)
{
	NodeFigura* nouNode = new NodeFigura();
	nouNode->figura = figura;
	nouNode->fila = fila;
	nouNode->columna = columna;
	nouNode->gir = gir;
	nouNode->m_nextNode = nodeActual;

	nodeActual = nouNode;

	if (primer == nullptr) {
		primer = nouNode;
		ultim = nouNode;
		nouNode->m_nextNode = nullptr;
	}
	else {
		ultim->m_nextNode = nouNode;
		ultim = nouNode;
		nouNode->m_nextNode = nullptr;
	}
}

void LlistaFigures::treuFigura() 
{
	if (primer != nullptr) {
		NodeFigura* temp = primer;
		primer = primer->m_nextNode;
		delete temp;
		
		if (primer == nullptr) {
			ultim = nullptr;
		}
	}
}
