#pragma once
#include "Player.h";
enum class PokemonType {
    WATER,
    FIRE,
    ROCK,
    ELECTRIC,
    POISIONOUS,
    PSYQUIC,
    PLANT
};
struct Pokemon {
    int lifes;
    int movementType;
    const int minLifeToCure;
    int amountLifeCured;
    int strengthLevel;
    int tryAgain;
    bool isTrapped;
    void CureHealth();
    void Attack();
    void PokemonCaptured(Player& player);
    void CheckCapture(Player player);
    void PokemonEscaped(Player& player);
    void CapturePokemon(Player& player);
    Position position;
};

void GeneratePokemon(Pokemon pokemon);

void RandomisePokeType(Pokemon pokemon);