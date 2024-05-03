#pragma once
#include "File.h"
#include "Player.h"
#include "Pokemon.h"

enum class Square {WALL, NOTHING, PLAYER, POKEMON};

struct Map{
	File file;
	int NUM_ROWS;
	int NUM_COLS;
	const int pokemonsPuebloPaleta = file.pokemonsPuebloPaleta;
	const int pokemonsForest = file.pokemonsForest;
	const int pokemonsCave = file.pokemonsCave;
	const int pokemonsToUnlockForest = file.pokemonsToUnlockForest;
	const int pokemonsToUnlockCave = file.pokemonsToUnlockCave;
	const int totalPokemons = pokemonsPuebloPaleta + pokemonsForest + pokemonsCave;
	Player player;
	Pokemon* pokemons = nullptr;
	Square** map = nullptr;
	Map();
	void PrintMap();
	void PlayerMovement();
	void UpdateScene();
	void InitializePokemons();
};

//std::stoi
//std::getLine
//std::