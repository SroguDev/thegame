// NAG£ÓWSKI KLAS

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>

#define MAX_NUMBER_OF_ITEMS 3

using namespace std;

class Options
{
public:
	Options(float width, float height);
	~Options();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text options[MAX_NUMBER_OF_ITEMS];
	sf::Text title;
	sf::Sound sound;
};