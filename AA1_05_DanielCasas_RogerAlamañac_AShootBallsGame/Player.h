#pragma once
#include <iostream>
#include <conio.h>
#include "Ball.h"
const int AMOUNT_PISTOL_BALLS = 20;
struct Player {
    std::string name;
    int position;
    int points;
    int numBalls = AMOUNT_PISTOL_BALLS;
    bool hasShoot;
    bool pistolEmpty = false;
    bool gameOver = false;
    Ball bulletsPistol[AMOUNT_PISTOL_BALLS];

    void init(std::string name2, int position2);

    Ball shoot();

    void addScore();
};