#pragma once
#include "File.h"
#include "Player.h"
#include "Pokemon.h"
#include "Pokeballs.h"
#include <ctime>

enum class Square {
	INVALID,
	WALL,
	NOTHING,
	POKEBALL,
	PLAYER, 
	POKEMON,
	MEWTWO
};

class Map{
private:
	File file;
	const int NUM_ROWS = file.NUM_ROWS;
	const int NUM_COLS = file.NUM_COLS;
	const int pokemonsPuebloPaleta = file.pokemonsPuebloPaleta;
	const int pokemonsForest = file.pokemonsForest;
	const int pokemonsToUnlockForest = file.pokemonsToUnlockForest;
	const int pokemonsToUnlockCave = file.pokemonsToUnlockCave;
	const int pokemonsToUnlockPokenti = file.pokemonsToUnlockForest + file.pokemonsToUnlockCave;
	const int totalPokemons = pokemonsPuebloPaleta + pokemonsForest;
	const int pikachuPower = file.pikachuPower;
	const int healthPokemons = file.healthPokemons;
	const int healthMewtwo = file.healthMewtwo;
	const int minTimePokemons = file.minTimePokemons;
	const int maxTimePokemons = file.maxTimePokemons;
	const int maxPokeBalls = 18;
	const int pokeballsPuebloPaleta = 5;
	const int pokeballsForest = 6;
	const int pokeballsCave = 7;
	bool unlockedForest = false;
	bool unlockedCave = false;
	bool unlockedPokenti = false;
	Pokemon* pokemons = nullptr;
	Square** map = nullptr;
	Pokeballs* pokeballs;
	clock_t timer;
public:
	Player player;
	Map();
	void PrintMap();
	void PlayerMovement();
	void UpdateScene();
	void UpdateMap();
	void InitializePokemons();
	int FindPokemonPosition(int x, int y) const;
	void FightPokemon(int x, int y);
	void NewPokemon();
	void InsertPokeballs();
	void NewPokeball();
	int FindPokeballPosition(int x, int y);
	void PokemonsMovement();
	~Map();

};