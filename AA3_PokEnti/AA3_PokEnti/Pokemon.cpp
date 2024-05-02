#include"Pokemon.h"
#include "Player.h"
#include <iostream>
#include <ctime>
#define NUM_LEVEL_1 6
#define NUM_LEVEL_2 5
#define NUM_LEVEL_3 4
#define NUM_LEVEL_4 3
#define NUM_LEVEL_5 2
#define NUM_LEVEL_6 1

void Pokemon::CureHealth(){
    if(lifes <= minLifeToCure){
        lifes += minLifeToCure;
    }
}

void Pokemon::Attack(){
    
}

void RandomisePokeType(Pokemon pokemon) {
    int randomType = rand() % (7+1-1)+1;
    switch (randomType) {
    case 1: PokemonType::WATER;
        break;
    case 2: PokemonType::FIRE;
        break;
    case 3: PokemonType::ROCK;
        break;
    case 4: PokemonType::ELECTRIC;
        break;
    case 5: PokemonType::POISIONOUS;
        break;
    case 6: PokemonType::PSYQUIC;
        break;
    case 7: PokemonType::PLANT;
        break;
    }
}

void GeneratePokemon(Pokemon pokemon) { 
  
    for (int i = 0; i < NUM_LEVEL_1 ; i++) { //Vida Nivel 1 = 10->39
        pokemon.lifes = rand() % (30 - 10 + 1) + 10;
        pokemon.strengthLevel = 1;
        RandomisePokeType(pokemon);
    }
    for (int i = 0; i < NUM_LEVEL_2; i++) { //Vida Nivel 2 = 40->69
        pokemon.lifes = rand() % (69 - 40 + 1) + 40;
        pokemon.strengthLevel = 2;
        RandomisePokeType(pokemon);
    }
    for (int i = 0; i < NUM_LEVEL_3; i++) { //Vida Nivel 3 = 70->99
        pokemon.lifes = rand() % (99 - 70 + 1) + 70;
        pokemon.strengthLevel = 3;
        RandomisePokeType(pokemon);
    }
    for (int i = 0; i < NUM_LEVEL_4; i++) { //Vida Nivel 4 = 100->129
        pokemon.lifes = rand() % (129 - 100 + 1) + 100;
        pokemon.strengthLevel = 4;
        RandomisePokeType(pokemon);
    }
    for (int i = 0; i < NUM_LEVEL_5; i++) { //Vida Nivel 5 = 130->159
        pokemon.lifes = rand() % (159 - 130 + 1) + 130;
        pokemon.strengthLevel = 5;
        RandomisePokeType(pokemon);
    }
    for (int i = 0; i < NUM_LEVEL_6; i++) { //Vida Nivel 6 = 160->180
        pokemon.lifes = rand() % (180 - 160 + 1) + 160;
        pokemon.strengthLevel = 6;
        RandomisePokeType(pokemon);
    }
    
}
void CapturePokemon(Player player) {
    char pokeBallType;
    std::cout << "Choose your Pokeball: " << std::endl;
    std::cout << "P: PokeBall; O:SuperBall; U:UltraBall"<<std::endl;
    std::cin >> pokeBallType;
    switch (pokeBallType) {
    case 'P': PokeBallsType::POKEBALL;
        CheckCapture(player);
        break;

    case 'O': PokeBallsType::SUPERBALL;
        CheckCapture(player);
        break;

    case 'U': PokeBallsType::ULTRABALL;
        
        CheckCapture(player);
        break;
    }
}

void Pokemon::CheckCapture(Player player){
  int probabilityOfCapture = rand() % (100);
  //Pokeball --> Level 1 = 70%, 2 = 50%, 3 = 38%, 4 = 27%, 5 = 15%, 6 = 5%
  if (player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 1 && probabilityOfCapture < 70){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 2 && probabilityOfCapture < 50){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 3 && probabilityOfCapture < 38){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 4 && probabilityOfCapture < 27){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 5 && probabilityOfCapture < 15){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 6 && probabilityOfCapture < 5){
    PokemonCaptured(player);
  } else {
      PokemonEscaped(player);
  }
  //Superball --> Level 1 = 85%, 2 = 65%, 3 = 48%, 4 = 30%, 5 = 25%, 6 = 13%;
  if (player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 1 && probabilityOfCapture < 85){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 2 && probabilityOfCapture < 65){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 3 && probabilityOfCapture < 48){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 4 && probabilityOfCapture < 30){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 5 && probabilityOfCapture < 25){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 6 && probabilityOfCapture < 13){
    PokemonCaptured(player);
  } else {
      PokemonEscaped(player);
  }

  //Ultraball --> Level 1 = 95%, 2 = 75%, 3 = 60%, 4 = 40%, 5 = 30%, 6 = 20%;
  if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 1 && probabilityOfCapture < 95) {
      PokemonCaptured(player);
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 2 && probabilityOfCapture < 75) {
      PokemonCaptured(player);
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 3 && probabilityOfCapture < 60) {
      PokemonCaptured(player);
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 4 && probabilityOfCapture < 40) {
      PokemonCaptured(player);
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 5 && probabilityOfCapture < 30) {
      PokemonCaptured(player);
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 6 && probabilityOfCapture < 20) {
      PokemonCaptured(player);
  }
  else {
      PokemonEscaped(player);
  }
}

void Pokemon::PokemonEscaped(Player& player) {
    std::cout << "Pokemon escaped!" << std::endl;
    std::cout << "Press 1 to try again or 2 for escape" << std::endl;
    std::cin >> tryAgain;
    if (tryAgain == 1) {
        CheckCapture(player);
    }
}
void Pokemon::PokemonCaptured(Player& player){
   isTrapped = true;
   lifes = 10;//MAXLIFES
   player.capturedPokemons++;
}

