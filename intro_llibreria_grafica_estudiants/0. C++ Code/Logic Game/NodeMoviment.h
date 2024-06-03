#pragma once


struct NodeMoviment {
	int moviment;
	NodeMoviment* m_nextMoviment;
};


class LlistaMoviments {
public:
	LlistaMoviments() : movimentActual(nullptr) {}

	void afegirMoviment(int moviment);
	void treuMoviment();

	NodeMoviment* getPrimerMoviemnt() { return primer; }
	NodeMoviment* getUltimMoviment() { return ultim; }


private:
	NodeMoviment* movimentActual;
	NodeMoviment* primer;
	NodeMoviment* ultim;
};