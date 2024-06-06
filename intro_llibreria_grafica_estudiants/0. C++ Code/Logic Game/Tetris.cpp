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


void Tetris::juga(int mode, double deltaTime)
{
	if (!m_partida.getFinalPartida()) {

		m_partida.actualitza(mode, deltaTime);
		
		if(m_partida.finalitzarFigura()) { 
			
			m_partida.inicialitzarNouTauler();
			m_partida.inicialitzarNovaFigura(mode);
			m_partida.setTemps(0);
			m_partida.setPuntuacio(10);
		}

	}
	else {
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		string missatgeFinal = "GAME OVER :(";
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, missatgeFinal);
		GraphicManager::getInstance()->drawSprite(GRAFIC_FONS, 0, 0, false);
		string msgNom = "Introdueix el nom d'usuari, tot seguit sense espais: "; 
		GraphicManager::getInstance()->drawFont(FONT_WHITE_30, POS_X_TAULER, POS_Y_TAULER - 50, 1.0, missatgeFinal);
		string nomUsuari = " "; cin >> nomUsuari;
		afegirPuntuacio("Puntuacions.txt", nomUsuari, m_partida.getNivell(), m_partida.getPuntuacio());

	}

}


// Nom a registrar - Nivell i Puntuació final

void Tetris::mostraPuntuacions(const string& fitxer)
{
	ifstream fitxerLlistaPuntuacions(fitxer);

	if (!fitxerLlistaPuntuacions.is_open()) {
		cout << "ERROR. Lectura Puntuacions";
		return;
	}
	else {
		string nomUsuari, nivell, puntuacio;

		while (fitxerLlistaPuntuacions >> nomUsuari >> nivell >> puntuacio) {
			cout << "Usuari: " + nomUsuari + ";   Nivell: " + nivell + ";  Puntuacio: " + puntuacio << endl;
		}
	
	}

}

void Tetris::afegirPuntuacio(const string& nomFitxer, const string nomUusuari, int nivell, int puntacio)
{

	int jugades[5][1];
	ifstream fitxer(nomFitxer);
	if (!fitxer.is_open()) {
		cout << "ERROR. Lectura Puntuacions";
		return;
	}
	else {
		string nomUsuari= " ";
		int nivell = 0, punts = 0;

		for (int i = 0; i < 5; i++) {
			fitxer >> nomUsuari >> nivell >> punts;
			jugades[i][0] = punts;

		}

		for (int i = 0; i < 5; i++) {
			if (jugades[i][0] < puntacio && (jugades[i-1][0] > puntacio)) {
				ofstream fitxer2(nomFitxer);
				for(int j =0; j <=i ;j++){
					if (j == i) {
						fitxer2 << nomUusuari << " " << nivell << " " << puntacio;
					}
				}
				fitxer2.close();

			}
		}
	}
	fitxer.close();
}

