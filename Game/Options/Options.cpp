// CIA£A KLAS

#include <iostream>
#include "Options.h"

Options::Options(float width, float height)
{
	if (!font.loadFromFile("Fonts/lato.ttf"))
	{
		cout << "Couldn't load font" << endl;
	}

	string mns[] = { "Window size", "Sound", "Language" };

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		options[i].setFont(font);
		if (i == 0)
			options[i].setColor(sf::Color(155, 193, 28));
		else
			options[i].setColor(sf::Color(0, 173, 217));
			options[i].setString(mns[i]);
			options[i].setPosition(sf::Vector2f(width / 2 - options[i].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * (i + 2)*0.5));
	}

	title.setFont(font);
	title.setColor(sf::Color(6, 77, 141));
	title.setString("Options");
	title.setCharacterSize(50);
	title.setPosition(sf::Vector2f(width / 2 - title.getGlobalBounds().width / 2, 10));

	selectedItemIndex = 0;
}

Options::~Options()
{
}

void Options::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.clear(sf::Color(243, 245, 242, 255));
		window.draw(title);
		window.draw(options[i]);
		window.display();
	}
}

void Options::MoveUp()
{
	sound.play();
	if (selectedItemIndex - 1 >= 0)
	{
		options[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex--;
		options[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else
	{
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
		options[0].setColor(sf::Color(0, 173, 217));
		options[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}

void Options::MoveDown()
{
	sound.play();
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		options[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex++;
		options[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else
	{
		selectedItemIndex = 0;
		options[MAX_NUMBER_OF_ITEMS].setColor(sf::Color(0, 173, 217));
		options[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}