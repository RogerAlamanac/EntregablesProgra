#pragma once
#include "Position.h"
enum class PokemonType {
    INVALID,
    WATER,
    FIRE,
    ROCK,
    ELECTRIC,
    POISIONOUS,
    PSYQUIC,
    PLANT
};

enum class Pokemons {
    INVALID,
    STANDARD,
    MEWTWO
};
const int minLifeToCure = 20;
const int PROBABILITYLVL1 = 90;
const int PROBABILITYLVL2 = 80;
const int PROBABILITYLVL3 = 65;
const int PROBABILITYLVL4 = 55;
const int PROBABILITYLVL5 = 40;
const int PROBABILITYLVL6 = 25;

struct Player;

struct Pokemon {
    int lifes;
    int strengthLevel;
    int timeToMove = 0;
    bool isTrapped = false;
    int initialTime = 0;
    bool hasTakenTime = false;
    PokemonType type = PokemonType::INVALID;
    Pokemons pokemon = Pokemons::INVALID;
    Pokemon();
    void RandomisePokeType();
    void CureHealth();
    void Attack(Player& player);
    void PokemonCaptured(Player& player);
    void CheckCapture(Player& player);
    void PokemonEscaped(Player& player);
    void CapturePokemon(Player& player);
    void PlayerEscaped();
    Position position;
};