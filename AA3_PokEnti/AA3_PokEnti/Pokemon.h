#pragma once
#include "Player.h";

struct Pokemon {
    int lifes;
    int movementType;
    int minLifeToCure;
    int amountLifeCured;
    int strengthLevel;
    bool isTrapped;
    void CureHealth();
    void Attack();
    void CapturePokemon(Player& player);
    void CheckCapture(Player player);
    Position position;
};