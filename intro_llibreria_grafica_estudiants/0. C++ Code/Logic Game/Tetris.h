#pragma once
#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Partida.h"
#include "fsrmscreen.h"
#include <list>
#include <string>
#include <tuple>


using namespace std;


class Tetris {
public:
	Tetris() : opcioMenu(-1) {}
	~Tetris();

	void Menu();
	void inicialitzar(int mode, const string& fitxerInicial, const string& fitxerFigures,
		const string& fitxerMoviments);

	void juga( int mode, double deltaTime);
	Partida getPartida() const { return m_partida; }

	int getMode() const { return opcioMenu; }

	void mostraPuntuacions(const string& fitxer);
	void guardaPuntuacions(const string& fitxer);
	void afegirPuntuacio(const string& nomFitxer, const string nomUusuari, int nivell, int puntacio);

private:
	Partida m_partida;
	int opcioMenu;

};

#endif 