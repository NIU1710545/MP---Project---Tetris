#include "NodeMoviment.h"

void LlistaMoviments::afegirMoviment(int moviment)
{
	NodeMoviment* nouMoviment = new NodeMoviment();
	nouMoviment->moviment = moviment;
	nouMoviment->m_nextMoviment = movimentActual;

	movimentActual = nouMoviment;
}