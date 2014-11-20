#include "SFML/Graphics.hpp"
#include <Windows.h>
#include <string>

#define MAX_NUMBER_OF_ITEMS 3

using namespace std;

class React
{
public:
	React();
	~React();

	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

	int selectedItemIndex;
	sf::Text choosen[MAX_NUMBER_OF_ITEMS];
	sf::Font font;

};