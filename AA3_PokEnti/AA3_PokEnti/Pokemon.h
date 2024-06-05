#pragma once
#include "Position.h"
#include <iostream>
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

enum class PokemonName {
    AXEW,
    BALTOY,
    BARBOACH,
    CROBAT,
    CROAGUNK,
    CORSOLA,
    VICTINI,
    PALOSSAND,
    PANSEAR,
    PARAS,
    SANDILE,
    MEWTWO,
    INVALID
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

class Player;

class Pokemon {
private:
    int lifes;
    int strengthLevel;
    int timeToMove = 0;
    bool isTrapped = false;
    int initialTime = 0;
    bool hasTakenTime = false;
    bool isBeingCaptured = false;
    Position position;
    PokemonType type = PokemonType::INVALID;
    PokemonName name = PokemonName::INVALID;
    Pokemons pokemon = Pokemons::INVALID;
public:
    Pokemon();
    int GetLifes() const;
    int GetStrenght() const;
    int GetTimeToMove() const;
    bool GetIsTrapped() const;
    int GetInitialTime() const;
    bool GetHasTakenTime() const;
    Position GetPosition() const;
    PokemonType GetPokemonType() const;
    Pokemons GetIsMewtwo() const;
    std::string GetName() const;

    void ChangeLifes(int l);
    void ChangeStrenght(int s);
    void ChangeTimeToMove(int t);
    void ChangeIsTrapped(bool t);
    void ChangeInitialTime(int t);
    void ChangeHasTakenTime(bool h);
    void ChangePosition(Position p);
    void ChangePositionX(int x);
    void ChangePositionY(int y);
    void ChangeType(PokemonType t);
    void ChangeIsMewtwo(Pokemons p);
    void ChangeName(PokemonName n);

    void RandomisePokeType();
    void RandName();
    void CureHealth();
    bool Attack(Player& player, int pikachuDamage);
    void PokemonCaptured(Player& player);
    bool CheckCapture(Player& player);
    void PokemonEscaped(Player& player);
    void CapturePokemon(Player& player, int pikachuDamage);
    void PlayerEscaped();
};