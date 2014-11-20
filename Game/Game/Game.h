#pragma once
#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <string>

using namespace std;

class Game
{
public:
	Game();
	~Game();

	void runGame();

protected:
	enum GameState {MENU,GAME_OVER, END};
	GameState state;

private:
	Font font;

	void menu();
};