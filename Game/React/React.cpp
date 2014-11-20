#include <iostream>
#include "React.h"


void React::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		choosen[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex--;
		choosen[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else
	{
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
		choosen[0].setColor(sf::Color(0, 173, 217));
		choosen[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}

void React::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		choosen[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex++;
		choosen[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else
	{
		selectedItemIndex = 0;
		choosen[MAX_NUMBER_OF_ITEMS - 1].setColor(sf::Color(0, 173, 217));
		choosen[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}