#include "Game.h"
#include <ctime>
int main()   
{
	srand(time(NULL));
	bool gameOver = false; 
	Game game;  

	while(!gameOver){ 
		for (int i = 0; i < game.GetNumPlayers(); i++) {
			game.PrintDiscarded(); 
			std::cout << std::endl << std::endl;
			game.PrintHands();
			std::cout << std::endl << std::endl;
			std::cout << game.players[i].GetID() << "'s turn." << std::endl;
			game.DiscardedCard((game.players[i].GetCard()));
			Card auxCard = game.GetNewCard();
			game.players[i].InsertCard(auxCard);
			system("pause");
		}
	} 
} 
 