#pragma once
enum class Scene{PUEBLO_PALETA, BOSQUE, CUEVA_CELESTE, LIGA_POKENTI, INVALID};
struct Map{
	Scene scene = Scene::INVALID;
	int NUM_ROWS;
	int NUM_COLS;
	int enemiesPuebloPaleta;
	int enemiesForest;
	void getMapData();
};