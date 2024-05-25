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
const int PROBABILITYLVL1 = 90;
const int PROBABILITYLVL2 = 80;
const int PROBABILITYLVL3 = 65;
const int PROBABILITYLVL4 = 55;
const int PROBABILITYLVL5 = 40;
const int PROBABILITYLVL6 = 25;

const int MIN_LIFE_LVL1 = 10;
const int MAX_LIFE_LVL1 = 39;
const int MIN_LIFE_LVL2 = 40;
const int MAX_LIFE_LVL2 = 69;
const int MIN_LIFE_LVL3 = 70;
const int MAX_LIFE_LVL3 = 99;
const int MIN_LIFE_LVL4 = 100;
const int MAX_LIFE_LVL4 = 129;
const int MIN_LIFE_LVL5 = 130;
const int MAX_LIFE_LVL5 = 159;
const int MIN_LIFE_LVL6 = 160;
const int MAX_LIFE_LVL6= 180;

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
    void PlayerEscaped();
    Position position;
};