#include "NodeMoviment.h"

void LlistaMoviments::afegirMoviment(int moviment)
{
	NodeMoviment* nouMoviment = new NodeMoviment();
	nouMoviment->moviment = moviment;
	nouMoviment->m_nextMoviment = movimentActual;

	movimentActual = nouMoviment;

    if (primer == nullptr) {
        primer = nouMoviment;
        ultim = nouMoviment;
        nouMoviment->m_nextMoviment = nullptr;
    }
    else {
        ultim->m_nextMoviment = nouMoviment;
        ultim = nouMoviment;
        nouMoviment->m_nextMoviment = nullptr;
    }

}

void LlistaMoviments::treuMoviment()
{
    if (primer != nullptr) {
        NodeMoviment* temp = primer;
        primer = primer->m_nextMoviment;
        delete temp;
        if (primer == nullptr) {
            ultim = nullptr;
        }
    }
}