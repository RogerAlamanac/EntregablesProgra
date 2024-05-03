#include <iostream>
#include <windows.h>
#include <ctime>
#include "Panel.h"
#include <fstream>

const int FPS = 60;

int main() {
	int NUM_ROWS1; //Fichero
	int NUM_COLS1; //Fichero
	int pokemonsPuebloPaleta1; //Fichero
	int pokemonsToUnlockForest1;
	int pokemonsForest1;	//Fichero
	int pokemonsToUnlockCave1;
	int pokemonsCave1;
	std::ifstream archivo("config.txt");
	if (archivo.is_open()) {
		// Leer la primera línea para obtener las dimensiones del mapa
		archivo >> NUM_COLS1;
		archivo.ignore(); // Ignorar el separador ;
		archivo >> NUM_ROWS1;

		// Leer la segunda línea para obtener los datos de la sala 1
		archivo >> pokemonsPuebloPaleta1;
		archivo.ignore(); // Ignorar el separador ;
		archivo >> pokemonsToUnlockForest1;

		// Leer la tercera línea para obtener los datos de la sala 2
		archivo >> pokemonsForest1;
		archivo.ignore(); // Ignorar el separador ;
		archivo >> pokemonsToUnlockCave1;

		archivo.close();
		std::cout << "HOLA";
	}
	else {
		std::cout << "Error al abrir el archivo de configuracion." << std::endl;
	}
}