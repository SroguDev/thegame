#include <iostream>
#include "Game.h"

Game::Game()
{
	state = END;

	if (!font.loadFromFile("Fonts/lato.tff"))
	{
		MessageBox(NULL, "Font not found", "ERROR", NULL);
		return
	}

	state = MENU;
}

void Game::runGame()
{
	while (state != END)
	{
		switch (state)
		{
		case GameState::MENU:
			menu();
			break;
		
		case GameState::GAME:
			//
			break;
		}
	}
}

void Game::menu()
{
	Text title("Mystical Blade Commando", font, 70);
	title.setStyle(Text::Bold);

	title.setPosition(1280 / 2 - title.getGlobalBounds().width / 2, 20);

	const int ile = 2;

	Text tekst[ile];

	string str[] = { "Play", "Exit" };
	for (int i = 0; i < ile; i++)
	{
		tekst[i].setFont(font);
		tekst[i].setCharacterSize(50);
		tekst[i].setString(str[i]);
		tekst[i].setPostion(1280 / 2 - title.getBlobalBounds().width / 2, 250 + i * 120);
	}

	while (state == MENU)
	{
		sf::Vector2f()
	}
}