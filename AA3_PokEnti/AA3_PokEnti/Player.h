#pragma once
#include "Position.h"
#include "Pokemon.h"
enum class Movement {
	UP,
	DOWN,
	RIGHT,
	LEFT,
	INVALID
};

enum class Action {
	CAPTURE,
	MOVE,
	INVALID
};

enum class Scene {
	PUEBLO_PALETA,
	BOSQUE,
	CUEVA_CELESTE,
	LIGA_POKENTI,
	INVALID
};

class Player{
private:
	Scene scene = Scene::PUEBLO_PALETA;
	Position position;
	Action action = Action::INVALID;
	Movement movement = Movement::DOWN;
	Movement lastMovement = Movement::DOWN;
	Pokemon* capturedPokemons = nullptr;
	int numCapturedPokemons = 50;
	int numPokeballs = 10;
	bool capturedMewtwo = false;
public:
	Player();
	Scene GetScene() const;
	Position GetPosition() const;
	Action GetAction() const;
	Movement GetMovement() const;
	Movement GetLastMovement() const;
	int GetNumCapturedPokemons() const;
	int GetPokeballs() const;
	bool GetCapturedMewtwo() const;
	void ChangeScene(Scene s);
	void ChangeAction(Action a);
	void ChangePosition(Position p);
	void ChangePositionX(int x);
	void ChangePositionY(int y);
	void ChangeMovement(Movement m);
	void ChangeLastMovement(Movement m);
	void ChangeNumCapturedPokemons(int n);
	void ChangeNumPokeballs(int p);
	void ChangeCapturedMewtwo(bool c);
	void PrintScene();
	~Player();
};