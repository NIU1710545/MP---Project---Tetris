#pragma once

struct NodeFigura {
	int figura;
	int fila;
	int columna;
	int gir;
	NodeFigura* m_nextNode;
};


class LlistaFigures {
public:
	LlistaFigures() : nodeActual(nullptr) {}

	void afegirFigura(int figura, int fila, int columna, int gir);


private:
	NodeFigura* nodeActual;

};