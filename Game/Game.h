#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <Windows.h>
#include <string>
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

using namespace std;

//***********************************************
class Game
{

public:
	Game();
	~Game();
	
	void runGame();

protected:
	enum GameState { MENU, GAME, GAME_OVER, END };
	GameState state;

private:
	sf::Font font;
};

//***********************************************
class Menu
{

public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void menu(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu1[MAX_NUMBER_OF_ITEMS];
	sf::Text title;
	sf::SoundBuffer buffer;
	sf::Sound sound;
};

//***********************************************

class Options
{

public:
	Options(float width, float height);
	~Options();
	void options1(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text options[MAX_NUMBER_OF_ITEMS];
	sf::Text title;
	sf::SoundBuffer buffer;
	sf::Sound sound;
	
};