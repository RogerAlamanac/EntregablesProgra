#pragma once
#include "Position.h"
class Pokeballs
{
private:
    Position position;
public:
    Pokeballs();
    int GetPositionX() const;
    int GetPositionY() const;
    void ChangePosition(int x, int y);
};