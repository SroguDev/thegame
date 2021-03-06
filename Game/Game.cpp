#include <iostream>
#include "Game.h"

sf::RenderWindow window(sf::VideoMode(1000, 600), "Mystical Blade Commando");

Game::Game()
{
	state = END;

	if (!font.loadFromFile("Fonts/lato.ttf"))
	{
		cout << "Font not found ERROR" << endl;
	}
	//Włączenie menu
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
			//utworzenie obiektu openMenu z klasy Menu
			Menu openMenu(window.getSize().x, window.getSize().y);
			//wywołanie metody menu() z klasy MENU
			openMenu.menu(window);
			// przypisanie statusu end po skończeniu funkcji menu()
			state = END;
			break;
		}
		
		case GameState::GAME:
			//Klasa gry
			break;
		}
	}
}