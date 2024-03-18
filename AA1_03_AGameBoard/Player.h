#pragma once
enum class Movement { UP, DOWN, LEFT, RIGHT };
struct Player {
    int row, column, score = 0;
    Movement move;
};

void addScore(Player& player);