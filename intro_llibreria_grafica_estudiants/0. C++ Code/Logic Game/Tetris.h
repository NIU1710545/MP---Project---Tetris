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

	int juga(Screen & pantalla);
	void mostraPuntuacions();

private:
	Partida m_partida;
	int opcioMenu;
};

#endif 