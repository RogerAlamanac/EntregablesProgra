#include "Map.h"
#include <iostream>
#include <fstream>
#include <string>

void Map::getMapData(){
    std::string linea;
    std::ifstream myFile("config.txt");

    if (myFile.is_open()) {
        // Leer dimensiones del mapa
        getline(myFile, linea);
        std::string dimensiones;
        getline(myFile, dimensiones, ';');
        int ancho, alto;
        myFile >> ancho;
        myFile.ignore(); // Ignorar el ';' entre los valores
        myFile >> alto;

        std::cout << "Dimensiones del mapa: " << ancho << "x" << alto << std::endl;

        // Leer información de Pueblo Paleta
        getline(myFile, linea);
        myFile >> enemiesPuebloPaleta >> NUM_ROWS >> NUM_COLS;

        std::cout << "Pueblo Paleta: Enemigos - " << enemiesPuebloPaleta
            << ", Filas - " << NUM_ROWS
            << ", Columnas - " << NUM_COLS << std::endl;
        myFile.close();
    }
    else {
        std::cout << "No se pudede abrir el myFile .txt" << std::endl;
    }
}