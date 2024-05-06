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
	const int pokemonsToUnlockPokenti = file.pokemonsToUnlockForest + file.pokemonsToUnlockCave;
	const int totalPokemons = pokemonsPuebloPaleta + pokemonsForest + pokemonsCave;
	bool unlockedForest = false;
	bool unlockedCave = false;
	bool unlockedPokenti = false;
	Player player;
	Pokemon* pokemons = nullptr;
	Square** map = nullptr;
	Map();
	void PrintMap();
	void PlayerMovement();
	void UpdateScene();
	void UpdateMap();
	void InitializePokemons();
	int FindPokemonPosition(int x, int y);
	void FightPokemon(int x, int y);
	void NewPokemon();
	~Map();

};