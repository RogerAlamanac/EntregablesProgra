#pragma once
#include "File.h"
#include "Player.h"
#include "Pokemon.h"

enum class Square {WALL, NOTHING, PLAYER, POKEMON};

struct Map{
	File file;
	const int NUM_ROWS = file.NUM_ROWS;
	const int NUM_COLS = file.NUM_COLS;
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
	bool CheckMovement();
	void PlayerMovement();
	void UpdateScene();
	void InitializePokemons();
};