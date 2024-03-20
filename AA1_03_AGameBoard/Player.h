#pragma once
enum class Movement { UP, DOWN, LEFT, RIGHT, INVALID };     //El movimiento empieza con INVALID
struct Player {
    int row, column, score = 0;
};

void addScore(Player& player);