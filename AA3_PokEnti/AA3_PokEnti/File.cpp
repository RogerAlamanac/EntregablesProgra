#include "File.h"
#include <iostream>
#include <fstream>
#include <string>

File::File() {
    std::ifstream archivo("config.txt");
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
    }
    else {
        int num1[3], num2[3];

        for (int i = 0; i < 3; ++i) {
            std::string linea;
            // Leer la línea
            if (std::getline(archivo, linea)) {
                size_t pos1 = linea.find(';');
                size_t pos2 = linea.find(';', pos1 + 1);
                num1[i] = std::atoi(linea.substr(0, pos1).c_str());
                num2[i] = std::atoi(linea.substr(pos1 + 1, pos2 - pos1 - 1).c_str());
            }
            else {
                std::cerr << "Error al leer del archivo." << std::endl;
            }
        }
        // Cierra el archivo
        NUM_ROWS = num1[0];
        NUM_COLS = num2[0];
        pokemonsPuebloPaleta = num1[1];
        pokemonsToUnlockForest = num2[1];
        pokemonsForest = num1[2];
        pokemonsToUnlockCave = num2[2];
        archivo.close();
    }
}