#include <iostream>
#include "Game.h"
#include "Menu/Menu.h"

sf::RenderWindow window(sf::VideoMode(800, 600), "Mystical Blade Commando");

Game::Game()
{
	state = END;

	if (!font.loadFromFile("Fonts/lato.ttf"))
	{
		cout << "Font not found ERROR" << endl;
	}
	//W³¹czenie menu
	state = MENU;
}

Game::~Game()
{
}


void Game::runGame(int i)
{
	while (state != END)
	{
		switch (state)
		{
		case GameState::MENU:
		{
			//menu();
		}
			break;
		
		case GameState::GAME:
			//Klasa gry
			break;
		}
	}
}



void Game::menu()
{
	
	sf::Text title;
	title.setString("Mystical Blade Commando");
	title.setFont(font);
	title.setCharacterSize(40);
	title.setStyle(sf::Text::Bold);
	title.setColor(sf::Color(6, 77, 141));

	title.setPosition(800 / 2 - title.getGlobalBounds().width / 2, 40);

	const int ile = MAX_NUMBER_OF_ITEMS;
	sf::Text tekst[ile];

	string str[] = { "Play", "Options", "Exit" };
	for (int i = 0; i < ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(30);
		tekst[i].setString(str[i]);
		tekst[i].setPosition(800 / 2 - tekst[i].getGlobalBounds().width / 2, 200 + i * 60);	
		tekst[i].setColor(sf::Color(0, 173, 217));
	}

	while (state == MENU)
	{
		sf::Event event;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{

			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					//reactc.MoveUp();
					break;

				case sf::Keyboard::Down:
					//reactc.MoveDown();
					break;
				}
				break;

			case sf::Event::Closed:
				state = END;
				break;
			}

			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape)
			{
				state = END;
			}

			window.clear(sf::Color(243, 245, 242, 255));

			window.draw(title);
			for (int i = 0; i < ile; i++)
			{
				window.draw(tekst[i]);
			}

			window.display();
		}
	}
}