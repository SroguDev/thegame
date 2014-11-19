// NAG£ÓWKI KLAS

#include "SFML/Graphics.hpp"
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

using namespace std;

class Menu
{

public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};