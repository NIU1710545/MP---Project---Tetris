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

	void juga( int mode, double deltaTime, Screen pantalla);
	void mostraPuntuacions();

	int getMode() const { return opcioMenu; }

	void guardaPuntuacions();
	void afegirPuntuacio(const string& nomUusuari, const string& nivell, int puntacio);

private:
	Partida m_partida;
	int opcioMenu;
	list <tuple <string, string, int>> puntuacions_;



};

#endif 