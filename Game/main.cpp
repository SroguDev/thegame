#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "Menu.h"

using namespace std;

/*
bool isSpritePressed(sf::Sprite &av_Sprite, sf::RenderWindow &av_Window)
{
	int mouseX = sf::Mouse::getPosition().x;
	int mouseY = sf::Mouse::getPosition().y;

	sf::Vector2i windowPosition = av_Window.getPosition();

	if (mouseX > av_Sprite.getPosition().x + windowPosition.x && mouseX < (av_Sprite.getPosition().x + av_Sprite.getGlobalBounds().width + windowPosition.x)
		&& mouseY > av_Sprite.getPosition().y + windowPosition.y + 30 && mouseY < (av_Sprite.getPosition().y + av_Sprite.getGlobalBounds().height + windowPosition.y + 30))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return true;
		}
		return false;
	}
	return false;
}

bool isRectanglePressed(sf::RectangleShape &av_Sprite, sf::RenderWindow &av_Window)
{
	int mouseX = sf::Mouse::getPosition().x;
	int mouseY = sf::Mouse::getPosition().y;

	sf::Vector2i windowPosition = av_Window.getPosition();

	if (mouseX > av_Sprite.getPosition().x + windowPosition.x && mouseX < (av_Sprite.getPosition().x + av_Sprite.getGlobalBounds().width + windowPosition.x)
		&& mouseY > av_Sprite.getPosition().y + windowPosition.y + 30 && mouseY < (av_Sprite.getPosition().y + av_Sprite.getGlobalBounds().height + windowPosition.y + 30))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return true;
		}
		return false;
	}
	return false;
}

*/

int main()
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

	/*sf::Texture texture;
	if (!texture.loadFromFile("Fat-Pig.png"))
	{
	cout << "Error! Couldnt find texture!" << endl;
	}
	sf::Sprite sprite(texture);
	sprite.setPosition(400-103, 50);*/
	/*
	sf::Font font;
	font.loadFromFile("lato.ttf");

	sf::Text text("Hello World", font);
	text.setColor(sf::Color(6, 77, 141));
	text.setPosition(300, 50);
	text.setCharacterSize(100);

	//Center text
	sf::FloatRect textRect = text.getLocalBounds();
	//nie wiem jak to dziala xD, ale dziala
	text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(800 / 2.0f, 80));

	sf::Text menu1("Nowa gra", font);
	menu1.setColor(sf::Color(243, 245, 242));
	menu1.setPosition(320, 155);
	menu1.setCharacterSize(40);

	sf::RectangleShape rectangle(sf::Vector2f(300, 60));
	rectangle.setOutlineThickness(5);
	rectangle.setOutlineColor(sf::Color(5, 135, 193));
	rectangle.setFillColor(sf::Color(0, 173, 217));
	rectangle.setPosition(250, 150);

	*/
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			
			/*
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
			cout << sf::Mouse::getPosition(window).x << " x " << sf::Mouse::getPosition(window).y << endl;
			//cout << sprite.getPosition().x << " x " << sprite.getPosition().y << endl;
			//cout << sprite.getGlobalBounds().height << " x " << sprite.getGlobalBounds().width <<  endl;
			/*if (isSpritePressed(sprite, window)) {
			cout << "CLICKED" << endl;
			}

			cout << rectangle.getPosition().x << " x " << rectangle.getPosition().y << endl;
			if (isRectanglePressed(rectangle, window)) {
			cout << "TEST" << endl;
			rectangle.setOutlineColor(sf::Color(6, 77, 141));
			}

			}
			*/
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
							sound2.play();
							cout << "Option button has been pressed" << endl;
							break;

						case 2:
							sound2.play();
							window.close();
							break;
					}

					break;
				}

				break;

			case sf::Event::Closed:
				window.close();
				break;

			}
		}

		window.clear(sf::Color(243, 245, 242, 255));

		//window.draw(sprite);
		//window.draw(text);
		//window.draw(rectangle);
		//window.draw(menu1);
		menu.draw(window);
		window.display();
	}

}