#pragma once
#include "Position.h"
enum class PokemonType {
    WATER,
    FIRE,
    ROCK,
    ELECTRIC,
    POISIONOUS,
    PSYQUIC,
    PLANT
};
const int minLifeToCure = 20;
const int probabilityLVL1 = 90;
const int probabilityLVL2 = 80;
const int probabilityLVL3 = 65;
const int probabilityLVL4 = 55;
const int probabilityLVL5 = 40;
const int probabilityLVL6 = 25;
struct Player;

struct Pokemon {
    int lifes;
    int movementType;
    int strengthLevel;
    bool isTrapped = false;
    PokemonType type;
    Pokemon();
    void RandomisePokeType();
    void CureHealth();
    void Attack();
    void PokemonCaptured(Player& player);
    void CheckCapture(Player& player);
    void PokemonEscaped(Player& player);
    void CapturePokemon(Player& player);
    Position position;
};