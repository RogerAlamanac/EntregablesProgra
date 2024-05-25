#include "File.h"
#include <iostream>
#include <fstream>
#include <string>

File::File() {
    std::ifstream archivo("config.txt");
    if (!archivo.is_open()) {
        while (true) {
            std::cerr << "Error al abrir el archivo." << std::endl;
            system("pause");
        }
    }
    else {
        int num1[6] = {0, 0, 0, 0, 0, 0}, num2[6] = {0, 0, 0, 0, 0, 0};

        for (int i = 0; i < 6; ++i) {
            std::string linea;
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

        NUM_ROWS = num1[0];
        NUM_COLS = num2[0];
        pokemonsPuebloPaleta = num1[1];
        pokemonsToUnlockForest = num2[1];
        pokemonsForest = num1[2];
        pokemonsToUnlockCave = num2[2];
        pikachuPower = num1[3];
        healthPokemons = num1[4];
        healthMewtwo = num2[4];
        minTimePokemons = num1[5];
        maxTimePokemons = num2[5];
        archivo.close();
    }
}