#include "NodeMoviment.h"

void LlistaMoviments::afegirMoviment(int moviment)
{
    NodeMoviment* nouMoviment = new NodeMoviment();
    nouMoviment->moviment = moviment;
    nouMoviment->m_nextMoviment = nullptr; // No hi ha movimentActual, has de posar nullptr

    if (m_primer == nullptr) {
        m_primer = nouMoviment;
        m_ultim = nouMoviment;
    }
    else {
        m_ultim->m_nextMoviment = nouMoviment;
        m_ultim = nouMoviment;
    }
}

void LlistaMoviments::treuMoviment()
{
    if (m_primer != nullptr) {
        NodeMoviment* temp = m_primer;
        m_primer = m_primer->m_nextMoviment;
        delete temp;
        if (m_primer == nullptr) {
            m_ultim = nullptr;
        }
    }
}

NodeMoviment* LlistaMoviments::getPrimerMoviemnt() const
{
    return m_primer;
}

NodeMoviment* LlistaMoviments::getUltimMoviment() const
{
    return m_ultim;
}