#include"Pokemon.h"
#include "Player.h"
#include <iostream>
#include <ctime>

Pokemon::Pokemon() {
    position.x = 0;
    position.y = 0;
    RandName();
    RandomisePokeType();
}

int Pokemon::GetLifes() const {
    return lifes;
}
int Pokemon::GetStrenght() const {
    return strengthLevel;
}
int Pokemon::GetTimeToMove() const {
    return timeToMove;
}
bool Pokemon::GetIsTrapped() const {
    return isTrapped;
}
int Pokemon::GetInitialTime() const {
    return initialTime;
}
bool Pokemon::GetHasTakenTime() const {
    return hasTakenTime;
}
Position Pokemon::GetPosition() const {
    return position;
}
PokemonType Pokemon::GetPokemonType() const {
    return type;
}
Pokemons Pokemon::GetIsMewtwo() const {
    return pokemon;
}
std::string Pokemon::GetName() const {
    switch (name) {
    case PokemonName::AXEW:
        return "AXEW";
    case PokemonName::BALTOY:
        return "BALTOY";
    case PokemonName::BARBOACH:
        return "BARBOACH";
    case PokemonName::CROBAT:
        return "CROBAT";
    case PokemonName::CROAGUNK:
        return "CROAGUNK";
    case PokemonName::CORSOLA:
        return "CORSOLA";
    case PokemonName::VICTINI:
        return "VICTINI";
    case PokemonName::PALOSSAND:
        return "PALOSSAND";
    case PokemonName::PANSEAR:
        return "PANSEAR";
    case PokemonName::PARAS:
        return "PARAS";
    case PokemonName::SANDILE:
        return "SANDILE";
    case PokemonName::MEWTWO:
        return "MEWTWO";
    default:
        return "INVALID";
    }
}


void Pokemon::ChangeLifes(int l) {
    lifes = l;
}
void Pokemon::ChangeStrenght(int s) {
    strengthLevel = s;
}
void Pokemon::ChangeTimeToMove(int t) {
    timeToMove = t;
}
void Pokemon::ChangeIsTrapped(bool t) {
    isTrapped = t;
}
void Pokemon::ChangeInitialTime(int t) {
    initialTime = t;
}
void Pokemon::ChangeHasTakenTime(bool h) {
    hasTakenTime = h;
}
void Pokemon::ChangePosition(Position p) {
    position = p;
}
void Pokemon::ChangePositionX(int x) {
    position.x = x;
}
void Pokemon::ChangePositionY(int y) {
    position.y = y;
}
void Pokemon::ChangeType(PokemonType t) {
    type = t;
}
void Pokemon::ChangeIsMewtwo(Pokemons p) {
    pokemon = p;
}
void Pokemon::ChangeName(PokemonName n) {
    name = n;
}

void Pokemon::RandName() {
    int randName = rand() % 11;
    switch (randName) {
    case 0:
        name = PokemonName::AXEW;
        break;
    case 1:
        name = PokemonName::BALTOY;
        break;
    case 2:
        name = PokemonName::BARBOACH;
        break;
    case 3:
        name = PokemonName::CROBAT;
        break;
    case 4:
        name = PokemonName::CROAGUNK;
        break;
    case 5:
        name = PokemonName::CORSOLA;
        break;
    case 6:
        name = PokemonName::VICTINI;
        break;
    case 7:
        name = PokemonName::PALOSSAND;
        break;
    case 8:
        name = PokemonName::PANSEAR;
        break;
    case 9:
        name = PokemonName::PARAS;
        break;
    case 10:
        name = PokemonName::SANDILE;
        break;
    default:
        name = PokemonName::INVALID;
        break;
    }
}
void Pokemon::CureHealth(){
    if(lifes <= minLifeToCure){
        lifes += minLifeToCure;
    }
}
bool Pokemon::Attack(Player& player, int pikachuDamage){ //Se implementará en la siguiente entrega
    std::cout << "Pikachu, attack!" << std::endl;
    int prevLifes = lifes;
    lifes -= pikachuDamage;
    if (lifes > 0) {
        std::cout << "-" << pikachuDamage << " Healthpoints" << std::endl;
        std::cout << "Current lifes: " << lifes << std::endl;
        return false;
    }
    else {
        std::cout << "-" << prevLifes << " Healthpoints" << std::endl;
        std::cout << "Current lifes: 0" << std::endl << "You've killed the pokemon!" << std::endl;
        system("pause");
        return true;
    }
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
void Pokemon::CapturePokemon(Player& player, int pikachuDamage) {
    char pokeBallThrow;
    while (true) {
        std::cout << GetName() << "\tHealth: " << lifes << std::endl;
        std::cout << "Press P to throw the PokeBall" << std::endl;
        std::cout << "Press A to attack the Pokemon" << std::endl;
        std::cout << "Press H to escape" << std::endl;
        std::cin >> pokeBallThrow;
        if (pokeBallThrow == 'p' || pokeBallThrow == 'P' && player.GetPokeballs() > 0) {
            player.ChangeNumPokeballs(player.GetPokeballs() - 1);
            if (CheckCapture(player)) break;
        }
        else if (pokeBallThrow == 'p' || pokeBallThrow == 'P' && player.GetPokeballs() <= 0) {
            std::cout << "You have no Pokeballs left!" << std::endl;
        }
        else if (pokeBallThrow == 'a' || pokeBallThrow == 'A') {
            if(Attack(player, pikachuDamage)) break;
        }
        else if (pokeBallThrow == 'h' || pokeBallThrow == 'H') {
            PlayerEscaped();
            break;
        }
    }
   
}
bool Pokemon::CheckCapture(Player& player){
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
        return false;
  }
  return true;
}
void Pokemon::PokemonEscaped(Player& player) {
    int tryAgain;
    std::cout << "Pokemon escaped!" << std::endl;
    std::cout << "Press 1 to try again or any other key to escape" << std::endl;
    std::cin >> tryAgain;
    if (tryAgain == 1) {
        if (player.GetPokeballs() > 0) {
            CheckCapture(player);
            player.ChangeNumPokeballs(player.GetPokeballs() - 1);
        }
        else {
            std::cout << "You have no Pokeballs left!" << std::endl;
        }
    }
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
   player.ChangeNumCapturedPokemons(player.GetNumCapturedPokemons() + 1);
}