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