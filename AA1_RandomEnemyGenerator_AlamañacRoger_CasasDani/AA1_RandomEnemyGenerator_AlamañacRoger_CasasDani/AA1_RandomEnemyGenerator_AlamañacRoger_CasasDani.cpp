#include "Enemy.h"
#define MAX_ENEMIES 5

std::string getEnemyTypeString(EnemyType enemytype){
	switch (enemytype) {
	case EnemyType::ZOMBIE:
		return "zombie";
		break;
	case EnemyType::VAMPIRE: 
		return "vampire";
		break;
	case EnemyType::GHOST: 
		return "ghost";
		break;
	case EnemyType::WITCH: 
		return "witch";
		break;
	}
}

bool equalEnemies(Enemy& enemy, Enemy& enemy2){
	if (enemy.type == enemy2.type && enemy.name == enemy2.name) {
		return true;
	}
	return false;
}

Enemy createRandomEnemy(){
	Enemy randomEnemy;
	randomEnemy.type = (EnemyType)(rand() % 4);
	getEnemyTypeString(randomEnemy.type);
	std::string enemyNames[5] = { "Manuel", "Joselito", "Alfonset", "Segismundo", "Fermin"};
	int randomName = rand() % 5;
	randomEnemy.name = enemyNames[randomName];
	randomEnemy.health = rand() % (1000 - 100 + 1) + 1;
	return randomEnemy;
}

int main()
{
	srand(time(NULL));
	Enemy enemies[MAX_ENEMIES];
	int equalEnemy = 0;
	std::cout << "List of enemies:" << std::endl;
	for (int numEnemy = 0; numEnemy < MAX_ENEMIES;) {
		enemies[numEnemy] = createRandomEnemy();
		for (int previousEnemies = 0; previousEnemies < numEnemy; previousEnemies++) {
			if (equalEnemies(enemies[numEnemy], enemies[previousEnemies])) {
				equalEnemy++;
			}
		}
		if (equalEnemy == 0) {
			std::cout << enemies[numEnemy].name << " is a " << getEnemyTypeString(enemies[numEnemy].type) << " whose life is " << enemies[numEnemy].health << std::endl;
			numEnemy++;
		}
		equalEnemy = 0;
	}
}