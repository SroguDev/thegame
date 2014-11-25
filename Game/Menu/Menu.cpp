#include <iostream>
#include "../Game.h"

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
		menu1[i].setFont(font);
		if (i == 0) 
		menu1[i].setColor(sf::Color(155, 193, 28));
		else
		menu1[i].setColor(sf::Color(0, 173, 217));
		menu1[i].setString(str[i]);
		menu1[i].setPosition(sf::Vector2f(width / 2 - menu1[i].getGlobalBounds().width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * (i+2)*0.5));
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
		window.draw(menu1[i]);
		window.draw(title);
	}
}			

void Menu::MoveUp()
{
	sound.play();
	if (selectedItemIndex - 1 >= 0)
	{
		menu1[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex--;
		menu1[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else {
		selectedItemIndex = MAX_NUMBER_OF_ITEMS - 1;
		menu1[0].setColor(sf::Color(0, 173, 217));
		menu1[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}

void Menu::MoveDown()
{
	sound.play();
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu1[selectedItemIndex].setColor(sf::Color(0, 173, 217));
		selectedItemIndex++;
		menu1[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
	else {
		selectedItemIndex = 0;
		menu1[MAX_NUMBER_OF_ITEMS-1].setColor(sf::Color(0, 173, 217));
		menu1[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}




void Menu::menu(sf::RenderWindow &window)
{
	
	window.setMouseCursorVisible(false); //Hide cursor
	Menu menu(window.getSize().x, window.getSize().y); // <<-- to jest tylko obiekt klasy MENU, a nie metoda klasy MENU -  nie mylic!!!!

	sf::SoundBuffer buffer1;
	if (!buffer1.loadFromFile("sounds/activated.wav"))
		cout << "Couldn't load music 1";
	sf::Sound sound1;
	sound1.setBuffer(buffer1);
	sound1.play();

	sf::SoundBuffer buffer2;
	if (!buffer2.loadFromFile("sounds/choose.wav"))
		cout << "Couldn't load music 2";
	sf::Sound sound2;
	sound2.setBuffer(buffer2);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				//state = END;
				window.close();
			}


			switch (event.type)
			{

			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;

				case sf::Keyboard::Down:
					menu.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
					{
						sound2.play();
						cout << "Play button has been pressed" << endl;
						//state = END;
						break;
					}

					case 1:
					{
						sound2.play();
						cout << "Option button has been pressed" << endl;
						Options optionsop(window.getSize().x, window.getSize().y);
						optionsop.options1(window);
						break;
					}

					case 2:
					{
						sound2.play();
						//state = END;
						window.close();
						break;
					}
					}

					break;
				}

				break;

			case sf::Event::Closed:
				//state = END;
				window.close();
				break;

			}
		}

		window.clear(sf::Color(243, 245, 242, 255));
		menu.draw(window);
		window.display();
	}
}