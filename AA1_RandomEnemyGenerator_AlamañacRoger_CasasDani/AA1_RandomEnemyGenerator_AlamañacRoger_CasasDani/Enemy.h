#pragma once
#include <iostream>
#include <ctime>
#include <string>

enum class EnemyType { ZOMBIE, VAMPIRE, GHOST, WITCH };
struct Enemy {
    EnemyType type;
    std::string name;
    int health;
};

std::string getEnemyTypeString(EnemyType enemytype);
bool equalEnemies(Enemy enemy, Enemy enemy2);
Enemy createRandomEnemy();