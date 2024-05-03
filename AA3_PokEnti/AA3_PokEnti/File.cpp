#include "File.h"
#include <iostream>
#include <fstream>
#include <string>

File::File() {
    std::ifstream archivo("config.txt");
    int pokemonsPuebloPaleta = 0; //Fichero
    int pokemonsForest = 0;	//Fichero
    int pokemonsCave = 10;
    if (archivo.is_open()) {
        // Leer la primera línea para obtener las dimensiones del mapa
        archivo >> NUM_COLS;
        archivo.ignore(); // Ignorar el separador ;
        archivo >> NUM_ROWS;

        // Leer la segunda línea para obtener los datos de la sala 1
        archivo >> pokemonsPuebloPaleta;
        archivo.ignore(); // Ignorar el separador ;
        archivo >> pokemonsToUnlockForest;

        // Leer la tercera línea para obtener los datos de la sala 2
        archivo >> pokemonsForest;
        archivo.ignore(); // Ignorar el separador ;
        archivo >> pokemonsToUnlockCave;

        archivo.close();
    }
    else {
        std::cerr << "Error al abrir el archivo de configuración." << std::endl;
    }
}