#pragma once
#include <iostream>

struct Ball {
    int position;
    int color = rand() % (6 - 2 + 1) + 2; //2 Verd, 3 Blau fluix, 4 Vermell, 5 Lila, 6 Taronja;
    bool isDestroyed = false;
};