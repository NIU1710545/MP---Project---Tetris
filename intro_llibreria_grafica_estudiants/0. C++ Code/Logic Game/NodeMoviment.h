#pragma once


struct NodeMoviment {
	int moviment;
	NodeMoviment* m_nextMoviment;
};


class LlistaMoviments {
public:

	void afegirMoviment(int moviment);
	void treuMoviment();

	NodeMoviment* getPrimerMoviemnt() const;
	NodeMoviment* getUltimMoviment() const;


private:
	NodeMoviment* m_primer;
	NodeMoviment* m_ultim;
};