#include <iostream>
#include "../Game.h"

Options::Options(float width, float height)
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

	string str[] = { "Window size", "Sound", "Back"};

	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		options[i].setFont(font);
		if (i == 0)
			options[i].setColor(sf::Color(155, 193, 28));
		else
			options[i].setColor(sf::Color(0, 173, 217));
			options[i].setString(str[i]);
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
		window.draw(title);
		window.draw(options[i]);
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
	else {
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
	else {
		selectedItemIndex = 0;
		options[MAX_NUMBER_OF_ITEMS - 1].setColor(sf::Color(0, 173, 217));
		options[selectedItemIndex].setColor(sf::Color(155, 193, 28));
	}
}


void Options::options1(sf::RenderWindow &window)
{

	window.setMouseCursorVisible(false); //Hide cursor
	Options opcje(window.getSize().x, window.getSize().y); // <<-- to jest tylko obiekt klasy MENU, a nie metoda klasy MENU -  nie mylic!!!!

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
					opcje.MoveUp();
					break;

				case sf::Keyboard::Down:
					opcje.MoveDown();
					break;

				case sf::Keyboard::Return:
					switch (opcje.GetPressedItem())
					{
					case 0:
					{
						sound2.play();
						cout << "Window size button has been pressed" << endl;
						break;
					}

					case 1:
					{
						sound2.play();
						cout << "Sound button has been pressed" << endl;
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
		opcje.draw(window);
		window.display();
	}
}