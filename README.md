
# MP - Project - Bàsic Tetris

Part del treball autònom de l'assignatura Metodologia de la Computació de 1r de carrera d'Enginyeria Informàtica de la Universitat Autònoma de Barcelona.

El projecte consisteix en la creació bàsica del joc Tetris. El joc consta d'un tauler i una sèrie de peces, les quals es poden rotar i desplaçar horitzontalment segons calgui per tal que encaixin amb les peces prèvieament col·locades. 

Si hi ha més d'una filera plena, aquestes s'eliminarant i totes les peces del damunt, es deplacaràn cap avall. Per a cada fila eliminada, el contador del jugador augmentarà, quantes més a la vegada major serà la puntuació de la jugada. 

La dificultat del joc anirà augmentant cada vegada que el jugador passi de nivell, el joc acabarà un cop el jugador no pugui posar més figures en el tauler sense passar el nombre de files.
## Authors
- [@NIU1710545](https://github.com/NIU1710545) - Identificació Universitat
- [@LL-OV](https://github.com/) - Personal

## Functions and main sections

```c++
Implementació de la classe Joc

class joc {} 
    Gestió global del joc, guarda el tauler de joc i les dades de la    
    figura utilitzant diversos mètodes de class Figura i class Tauler.
```

```c++
class Tauler {}
    Guarda tota la informació relacionada sobre l'estat del tauler en una 
    partida, des de quines caselles estan ocupades per una figura, 
    mitjançant diversos mètodes en la classe, fins l'eliminació de files 
    completades.
```

```c++
class Figura() {}
    Gestió dels diversos tipos de figures que té el joc i informàció de la 
    figura amb la que s'esta jugant en el moment. Implementació de girs de 
    la figura, coloca, posició actual i forma principal de la figura.
```
## Lessons Learned

L'objectiu principal del projecte és poder implementar tots els coneixements prèviemanet ensenyats en un mateix projecte. 

1. Implementació de classes i objectes 
2. Encapsulament de dades
3. Utilització de constructors i destructors
4. Obtenció de dades a partir de fitxers.txt fora del projecte



## Documentation

[PDF - Presentació Projecte](https://caronte.uab.cat/pluginfile.php/36636/mod_resource/content/9/presentacio_projecte.pdf)

[PDF - GitHub_Conceptes bàsic](https://caronte.uab.cat/pluginfile.php/38491/mod_resource/content/9/Introduccio%CC%81_als_repositoris.pdf)


## Run Locally

Creem un repositori en on guardarep el projecte

```bash
  git init
```

Clone projecte

```bash
  git clone https://github.com/NIU1710545/MP---Project---Tetris
```

Ens situem dintre del repositori
```bash
  cd my-project
```

I ens baixem tot el que hi ha en el repositori remot que hem copiat

```bash
  git pull
```
