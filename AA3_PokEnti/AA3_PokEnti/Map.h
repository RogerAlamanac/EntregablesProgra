#pragma once
#include "Player.h"
#include "Walls.h"
enum class Scene{
	PUEBLO_PALETA, 
	BOSQUE, 
	CUEVA_CELESTE, 
	LIGA_POKENTI, 
	INVALID
};

struct Map{
	Scene scene = Scene::INVALID;
	Player player;
	Wall walls;		//Array dinamic
	int NUM_ROWS = 30;
	int NUM_COLS = 30;
	int enemiesPuebloPaleta;
	int enemiesForest;
	Map();
	void GetMapData();
	void PrintMap();
	void PlayerMovement();
	void UpdateScene();
};

//std::stoi
//std::getLine
//std::