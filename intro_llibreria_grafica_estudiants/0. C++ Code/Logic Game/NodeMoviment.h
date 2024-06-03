#pragma once


struct NodeMoviment {
	int moviment;
	NodeMoviment* m_nextMoviment;
};


class LlistaMoviments {
public:
	LlistaMoviments() : movimentActual(nullptr) {}

	void afegirMoviment(int moviment);


private:
	NodeMoviment* movimentActual;
};