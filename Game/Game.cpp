#include <iostream>
#include "Game.h"
#include "Menu/Menu.h"

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


void Game::runGame()
{
	while (state != END)
	{
		switch (state)
		{
		case GameState::MENU:
		{
			menu();
			break;
		}
		
		case GameState::GAME:
			//Klasa gry
			break;
		}
	}
}



void Game::menu()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mystical Blade Commando");
	window.setMouseCursorVisible(false); //Hide cursor
	Menu menu(window.getSize().x, window.getSize().y);

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
				state = END;
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
						sound2.play();
						cout << "Play button has been pressed" << endl;
						break;

					case 1:
					{
						sound2.play();
						cout << "Option button has been pressed" << endl;
					}
						break;

					case 2:
						sound2.play();
						state = END;
						window.close();
						break;
					}

					break;
				}

				break;

			case sf::Event::Closed:
				state = END;
				window.close();
				break;

			}
		}

		window.clear(sf::Color(243, 245, 242, 255));
		menu.draw(window);
		window.display();
	}
}