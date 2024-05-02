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
	Wall* walls = nullptr;		//Array dinamic
	int NUM_ROWS = 30; //Fichero
	int NUM_COLS = 30; //Fichero
	int enemiesPuebloPaleta = 0; //Fichero
	int enemiesForest = 0;	//Fichero
	Map();
	void GetMapData();
	void PrintMap();
	void PlayerMovement();
	void UpdateScene();
};

//std::stoi
//std::getLine
//std::