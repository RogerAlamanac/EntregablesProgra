#pragma once
#include "Position.h"
struct Pokeballs
{
private:
    Position position;
public:
    Pokeballs();
    int GetPositionX();
    int GetPositionY();
    void ChangePosition(int x, int y);
};