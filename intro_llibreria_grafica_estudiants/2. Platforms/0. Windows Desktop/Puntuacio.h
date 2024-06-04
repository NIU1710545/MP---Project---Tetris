#include <fstream>
#include <list>
#include <string>
#include <algorithm>

using namespace std;

struct Puntuacio {
    string nomUsuari;
    string nivell;
    int puntacio;
};

list<Puntuacio> puntuacions;

void mostraPuntuacions(const string& fitxer) {
    ifstream file(fitxer);
    if (file.is_open()) {
        Puntuacio p;
        while (file >> p.nomUsuari >> p.nivell >> p.puntacio) {
            puntuacions.push_back(p);
        }
        file.close();
    }
    puntuacions.sort([](const Puntuacio& a, const Puntuacio& b) {
        return a.puntacio > b.puntacio;
        });
    for (const auto& p : puntuacions) {
        cout << p.nomUsuari << " " << p.nivell << " " << p.puntacio << endl;
    }
}

void guardaPuntuacions(const string& fitxer) {
    ofstream file(fitxer);
    if (file.is_open()) {
        for (const auto& p : puntuacions) {
            file << p.nomUsuari << " " << p.nivell << " " << p.puntacio << endl;
        }
        file.close();
    }
}

void afegirPuntuacio(const string nomUsuari, const string nivell, int puntacio) {
    Puntuacio p = { nomUsuari, nivell, puntacio };
    puntuacions.push_back(p);
    puntuacions.sort([](const Puntuacio& a, const Puntuacio& b) {
        return a.puntacio > b.puntacio;
        });
}