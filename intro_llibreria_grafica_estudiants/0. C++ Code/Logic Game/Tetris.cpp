#include "Tetris.h"
#include "fsrmscreen.h"
#include "GraphicManager.h"
#include "InfoJoc.h"
#include <list>


Tetris::~Tetris() 
{

}

void Tetris::Menu() 
{
	cout << "MENU PRINCIPAL" << endl;
	cout << "======================" << endl;
	cout << "1. Joc en mode normal" << endl;
	cout << "2. Joc en mode test" << endl;
	cout << "3. Mostrar puntuacions" << endl;
	cout << "4. Sortir" << endl;
	cout << endl;
	cout << "Eleccio: ";
	cin >> opcioMenu;
	cout << endl;
}


void Tetris::inicialitzar(int mode, const string& fitxerInicial, const string& fitxerFigures,
	const string& fitxerMoviments)
{
	m_partida.inicialitza(mode, fitxerInicial, fitxerFigures, fitxerMoviments);
}


bool Tetris::juga(int mode, double deltaTime)
{
	if (!m_partida.getFinalPartida()) {

		m_partida.actualitza(mode, deltaTime);
		
		if(m_partida.finalitzarFigura()) { 
			m_partida.inicialitzarNouTauler();
			m_partida.inicialitzarNovaFigura(mode);
			m_partida.setTemps(0);
		}

	}
	else {
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		GraphicManager::getInstance()->drawSprite(GRAFIC_TAULER, POS_X_TAULER, POS_Y_TAULER, false);
		string missatgeFinal = "GAME OVER :(";
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, missatgeFinal);
	}
	return m_partida.getFinalPartida();

}


// Nom a registrar - Nivell i Puntuació final

void Tetris::guardaPuntuacions()
{

}

void Tetris::afegirPuntuacio(const string& nomUusuari, const string& nivell, int puntacio)
{

}

void Tetris::mostraPuntuacions()
{

}



/*
void Tetris::mostraPuntuacions()
{
	for (const auto& puntuacio : puntuacions_) {
		string missatge = "Usuari: " + get<0>(puntuacio) + " Nivel: " + get<1>(puntuacio) + ",   Puntuacio: " + to_string(get<2>(puntuacio));
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, missatge);
	}

}

void Tetris::guardaPuntuacions() 
{
	ofstream fitxerPuntuacio("Puntuacions.txt");
	if (!fitxerPuntuacio.is_open()){
		cout << "ERROR. Guarda Puntuacions";
		return;
	}

	for (const auto& puntuacio : puntuacions_) {
		fitxerPuntuacio << get<0>(puntuacio) << " " << get<1>(puntuacio) << " " << get<2>(puntuacio) << std::endl;
	}
}

void Tetris::afegirPuntuacio(const string& nomUsuari, const string& nivell, int puntuacio) 
{
	puntuacions_.emplace_back(nomUsuari, nivell, puntuacio);
	puntuacions_.sort([](const auto& a, const auto& b) { return std::get<2>(a) > std::get<2>(b); });
}
*/