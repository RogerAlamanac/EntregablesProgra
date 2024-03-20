#pragma once
enum class Movement { UP, DOWN, LEFT, RIGHT, INVALID };
struct Player {
    int row, column, score = 0;
    Movement move = Movement::INVALID;
};

void addScore(Player& player);