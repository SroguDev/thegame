#include <iostream>
#include "Menu.h"

using namespace std;

Menu::Menu(float width, float height)
{
	if (!font.loadFromFile("Fonts/lato.ttf"))
	{
		cout << "Couldn't load font" << endl;
	}

	if (!buffer.loadFromFile("sounds/menu.wav"))
	{
		cout << "Couldn't load music" << endl;
	}
	sound.setBuffer(buffer);
	

	string str[] = { "Play", "Options", "Exit" };

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) 
	{
		menu[i].setFont(font);
		if (i == 0) 
		menu[i].setColor(sf::Color(155, 193, 28));
		else
		menu[i].setColor(sf::Color(0, 173, 217));
		menu[i].setString(str[i]);
		menu[i].setPosition(sf::Vector2f(width / 2 - menu[i].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * (i+2)*0.5));
	}

	title.setFont(font);
	title.setColor(sf::Color(6, 77, 141));
	title.setString("Mystical Blade Commando");
	title.setCharacterSize(50);
	title.setPosition(sf::Vector2f(width / 2 - title.getGlobalBounds().width / 2, 10));

	
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
		window.draw(title);
	}
}

void Menu::MoveUp()
{
	sound.play();
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
	sound.play();
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