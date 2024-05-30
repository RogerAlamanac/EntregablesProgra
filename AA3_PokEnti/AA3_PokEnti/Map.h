#pragma once
#include "File.h"
#include "Player.h"
#include "Pokemon.h"

enum class Square {
	INVALID,
	WALL,
	NOTHING,
	POKEBALL,
	PLAYER, 
	POKEMON,
	MEWTWO
};

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
	const int pikachuPower = file.pikachuPower;
	const int healthPokemons = file.healthPokemons;
	const int healthMewtwo = file.healthMewtwo;
	const int minTimePokemons = file.minTimePokemons;
	const int maxTimePokemons = file.maxTimePokemons;
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
	int FindPokemonPosition(int x, int y) const;
	void FightPokemon(int x, int y);
	void NewPokemon();
	~Map();

};