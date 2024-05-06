#include"Pokemon.h"
#include "Player.h"
#include <iostream>
#include <ctime>

void Pokemon::CureHealth(){
    if(lifes <= minLifeToCure){
        lifes += minLifeToCure;
    }
}

void Pokemon::Attack(){ //Se implementar� en la siguiente entrega
    
}

void Pokemon::RandomisePokeType() {
    int randomType = rand() % (7-1+1)+1;
    switch (randomType) {
    case 1: type = PokemonType::WATER;
        break;
    case 2: type = PokemonType::FIRE;
        break;
    case 3: type = PokemonType::ROCK;
        break;
    case 4: type = PokemonType::ELECTRIC;
        break;
    case 5: type = PokemonType::POISIONOUS;
        break;
    case 6: type = PokemonType::PSYQUIC;
        break;
    case 7: type = PokemonType::PLANT;
        break;
    }
}

Pokemon::Pokemon() {
    position.x = 0;
    position.y = 0;
    RandomisePokeType();
}

void Pokemon::CapturePokemon(Player& player) {
    char pokeBallType;
    std::cout << "Choose your Pokeball: " << std::endl;
    std::cout << "P: PokeBall; O:SuperBall; U:UltraBall"<<std::endl;
    for (bool valid = false; !valid;) {
        std::cin >> pokeBallType;
        switch (pokeBallType) {
        case 'p':
        case 'P':
            player.pokeBall = PokeBallsType::POKEBALL;
            valid = true;
            break;
        case 'o':
        case 'O':
            player.pokeBall = PokeBallsType::SUPERBALL;
            valid = true;
            break;    
        case 'u':
        case 'U':
            player.pokeBall = PokeBallsType::ULTRABALL;
            valid = true;
            break;
        default:
            break;
        }
    }
    CheckCapture(player);
}

void Pokemon::CheckCapture(Player& player){
  int probabilityOfCapture = rand() % 100;
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
  } 
  //Superball --> Level 1 = 85%, 2 = 65%, 3 = 48%, 4 = 30%, 5 = 25%, 6 = 13%
  else if (player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 1 && probabilityOfCapture < 85){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 2 && probabilityOfCapture < 65){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 3 && probabilityOfCapture < 48){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 4 && probabilityOfCapture < 30){
    PokemonCaptured(player);
  } else if(player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 5 && probabilityOfCapture < 25){
    PokemonCaptured(player);
  } else if (player.pokeBall == PokeBallsType::SUPERBALL && strengthLevel == 6 && probabilityOfCapture < 13) {
      PokemonCaptured(player);
  }
  //Ultraball --> Level 1 = 95%, 2 = 75%, 3 = 60%, 4 = 40%, 5 = 30%, 6 = 20%;
  else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 1 && probabilityOfCapture < 95) {
      PokemonCaptured(player);
  } else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 2 && probabilityOfCapture < 75) {
      PokemonCaptured(player);
  } else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 3 && probabilityOfCapture < 60) {
      PokemonCaptured(player);
  } else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 4 && probabilityOfCapture < 40) {
      PokemonCaptured(player);
  } else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 5 && probabilityOfCapture < 30) {
      PokemonCaptured(player);
  } else if (player.pokeBall == PokeBallsType::ULTRABALL && strengthLevel == 6 && probabilityOfCapture < 20) {
      PokemonCaptured(player);
  } else {
      PokemonEscaped(player);
  }
}

void Pokemon::PokemonEscaped(Player& player) {
    int tryAgain;
    std::cout << "Pokemon escaped!" << std::endl;
    std::cout << "Press 1 to try again or any other key to escape" << std::endl;
    std::cin >> tryAgain;
    if (tryAgain == 1) CheckCapture(player);
    else {
       std::cout << "Pokemon has escaped!"<<std::endl;
       system("pause");
    }
}

void Pokemon::PokemonCaptured(Player& player){
   std::cout << "Pokemon captured" << std::endl;
   system("pause");
   isTrapped = true;
   lifes = 10;//MAXLIFES
   player.numCapturedPokemons++;
}