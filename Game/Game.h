#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <string>

#define MAX_NUMBER_OF_ITEMS 3

using namespace std;

class Game
{
public:
	Game();
	~Game();
	
	void runGame(int i);
	
protected:
	enum GameState {MENU, GAME, GAME_OVER, END};
	GameState state;

private:
	sf::Font font;
	void menu();
};