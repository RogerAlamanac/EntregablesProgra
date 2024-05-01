#include"Pokemon.h"
#include "Player.h"
#include <iostream>
#include <ctime>

void Pokemon::CureHealth(){
    if(lifes <= minLifeToCure){
        lifes += minLifeToCure;
    }
}

void Pokemon::Attack(){
    
}

void Pokemon::CheckCapture(Player player){
  int probabilityOfCapture = rand() % (100);
  //Pokeball --> Level 1 = 70%, 2 = 50%, 3 = 38%, 4 = 27%, 5 = 15%, 6 = 5%
  if (player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 1 && probabilityOfCapture < 70){
    CapturePokemon();  
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 2 && probabilityOfCapture < 50){
    CapturePokemon();         
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 3 && probabilityOfCapture < 38){
    CapturePokemon();         
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 4 && probabilityOfCapture < 27){
    CapturePokemon();
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 5 && probabilityOfCapture < 15){
    CapturePokemon();
  } else if(player.pokeBall == PokeBallsType::POKEBALL && strengthLevel == 6 && probabilityOfCapture < 5){
    CapturePokemon();
  } else {
    
  }
  //Superball --> Level 1 = 85%, 2 = 65%, 3 = 48%, 4 = 30%, 5 = 25%, 6 = 13%;
  if (player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 1 && probabilityOfCapture < 85){
    CapturePokemon();  
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 2 && probabilityOfCapture < 65){
    CapturePokemon();         
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 3 && probabilityOfCapture < 48){
    CapturePokemon();         
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 4 && probabilityOfCapture < 30){
    CapturePokemon();
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 5 && probabilityOfCapture < 25){
    CapturePokemon();
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 6 && probabilityOfCapture < 13){
    CapturePokemon();
  } else {
    
  }

  //Ultraball --> Level 1 = 95%, 2 = 75%, 3 = 60%, 4 = 40%, 5 = 30%, 6 = 20%;
  if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 1 && probabilityOfCapture < 95) {
      CapturePokemon();
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 2 && probabilityOfCapture < 75) {
      CapturePokemon();
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 3 && probabilityOfCapture < 60) {
      CapturePokemon();
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 4 && probabilityOfCapture < 40) {
      CapturePokemon();
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 5 && probabilityOfCapture < 30) {
      CapturePokemon();
  }
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 6 && probabilityOfCapture < 20) {
      CapturePokemon();
  }
  else {

  }
}

void Pokemon::CapturePokemon(){
   isTrapped = true;
   lifes = 10;//MAXLIFES
}

