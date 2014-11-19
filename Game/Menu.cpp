// CIA£A KLAS

#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("lato.ttf"))
	{
		cout << "Couldn't load font" << endl;
	}

	string str[] = { "Play", "Options", "Exit" };

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		menu[i].setFont(font);
		if (i == 0) 
		menu[i].setColor(sf::Color(155, 193, 28));
		else
		menu[i].setColor(sf::Color(0, 173, 217));
		menu[i].setString(str[i]);
		menu[i].setPosition(sf::Vector2f(width / 2 - menu[i].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * (i+1)*0.5));
	}
	
	selectedItemIndex = 0;

}

Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else {
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
		menu[0].setColor(sf::Color(0, 173, 217));
		menu[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else {
		selectedItemIndex = 0;
		menu[MAX_NUMBER_OF_ITEMS-1].setColor(sf::Color(0, 173, 217));
		menu[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}