#include"Pokemon.h"
#include "Player.h"
#include <iostream>
#include <ctime>

void Pokemon::CureHealth(){
    if(lifes <= minLifeToCure){
        lifes += minLifeToCure;
    }
}

void Pokemon::Attack(){ //Se implementará en la siguiente entrega
    
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
    char pokeBallThrow;
    while (true) {
        std::cout << "Press P to throw the PokeBall" << std::endl;
        std::cout << "Press A to attack the Pokemon" << std::endl;
        std::cout << "Press H to escape" << std::endl;
        std::cin >> pokeBallThrow;
        if (pokeBallThrow == 'p' || pokeBallThrow == 'P' && player.numPokeballs > 0) {
            CheckCapture(player);
            player.numPokeballs--;
            break;
        }
        else if (pokeBallThrow == 'p' || pokeBallThrow == 'P' && player.numPokeballs <= 0) {
            std::cout << "You have no Pokeballs left!" << std::endl;
        }
        else if (pokeBallThrow == 'a' || pokeBallThrow == 'A') {
            Attack();
            break;
        }
        else if (pokeBallThrow == 'h' || pokeBallThrow == 'H') {
            PlayerEscaped();
            break;
        }
    }
   
}

void Pokemon::CheckCapture(Player& player){
  int probabilityOfCapture = rand() % 100;
  if (strengthLevel == 1 && probabilityOfCapture < PROBABILITYLVL1){
        PokemonCaptured(player);
  } else if(strengthLevel == 2 && probabilityOfCapture < PROBABILITYLVL2){
        PokemonCaptured(player);
  } else if(strengthLevel == 3 && probabilityOfCapture < PROBABILITYLVL3){
        PokemonCaptured(player);
  } else if(strengthLevel == 4 && probabilityOfCapture < PROBABILITYLVL4){
        PokemonCaptured(player);
  } else if(strengthLevel == 5 && probabilityOfCapture < PROBABILITYLVL5){
        PokemonCaptured(player);
  } else if(strengthLevel == 6 && probabilityOfCapture < PROBABILITYLVL6){
        PokemonCaptured(player);
  } else{
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
        std::cout << "Pokemon has escaped!" << std::endl;
        system("pause");
    }
}

void Pokemon::PlayerEscaped() {
    std::cout << "You escaped!" << std::endl;
    system("pause");
}

void Pokemon::PokemonCaptured(Player& player){
   std::cout << "Pokemon captured" << std::endl;
   system("pause");
   isTrapped = true;
   lifes = 10;
   player.numCapturedPokemons++;
}