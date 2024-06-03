#pragma once
#ifndef TETRIS_H
#define TETRIS_H

#include <iostream>
#include <fstream>
#include <string>
#include "Partida.h"
#include "fsrmscreen.h"


using namespace std;


class Tetris {
public:
	Tetris() {}
	~Tetris();

	int Menu();
	void inicialitzar(int mode);

	int juga(int mode);
	void mostraPuntuacions();

private:
	Partida m_partida;
	int opcioMenu;

	string fitxerPartidaTest = "./data/Games/partida.txt";
	string fitxerFiguresTest = "./data/Games/figures.txt";
	string fitxerMovimentsTest = ".data/Games/moviments.txt";

};

#endif 