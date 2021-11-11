#include <SFML/Graphics.hpp>
#include <iostream>
#include "units.h"
#include "field.h"

int main()
{
	Field GameField;

	Environment Item;

	sf::RenderWindow window(sf::VideoMode(GameField.GetFieldXSize(), GameField.GetFieldYSize()), "Game");
	
	sf::Clock clock;
 
	Hero Player("sprites/tds-modern-hero-weapons-and-props/Hero_Pistol/Hero_Pistol.png", 250, 250);

	Player.getSprite().setRotation(180);
 
	while (window.isOpen())
	{
 
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
 
 
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		//  CHARACTER CONTROL
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
			if (Player.getCoordX() - 5 > 0) {
				if ((Player.getCoordY() > 440 && Player.getCoordY() < (650)) && ((Player.getCoordX() > 845 && Player.getCoordX() < 940))) {
					if (Player.getCoordX() - 5 > 845) {
						Player.setDirection(1); Player.setSPeed(0.1);
						Player.sprite.setRotation(90);
					}
				} else {
				Player.setDirection(1); Player.setSPeed(0.1); //  направление влево
				Player.sprite.setRotation(90);
				}
			}
		}
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
			if (Player.getCoordX() + 5 < 1810) {
				if ((Player.getCoordY() > 440 && Player.getCoordY() < (650)) && ((Player.getCoordX() > 845 && Player.getCoordX() < 940))) {
					if (Player.getCoordX() + 5 < 940) {
						Player.setDirection(0); Player.setSPeed(0.1);
						Player.sprite.setRotation(270);
					}
				} else {
					Player.setDirection(0); Player.setSPeed(0.1); //  направление вправо
					Player.sprite.setRotation(270);
				}
			}
		}
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
		if (Player.getCoordY() < 450 || (Player.getCoordX() > 845 && Player.getCoordX() < 940)) {
			if (Player.getCoordY() + 5 > 0) {
				Player.setDirection(3); Player.setSPeed(0.1); //  направление вверх
				Player.sprite.setRotation(180);
				}
			} else if (Player.getCoordY() > 670) {
				if (Player.getCoordY() - 5 > 670) {
					Player.setDirection(3); Player.setSPeed(0.1); //  направление вверх
					Player.sprite.setRotation(180);
				}
			}
		}	
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
			if (Player.getCoordY() < 450 || (Player.getCoordX() > 845 && Player.getCoordX() < 940)) {
				if (Player.getCoordY() - 5 < 440 || ((Player.getCoordX() > 845 && Player.getCoordX() < 940) && (Player.getCoordY() - 5 < 840))) {
					Player.setDirection(2); Player.setSPeed(0.1); //  направление вниз
					Player.sprite.setRotation(0);
				}
			} else if(Player.getCoordY() > 640) {
				if (Player.getCoordY() - 5 < 840) {
					Player.setDirection(2); Player.setSPeed(0.1); //  направление вниз
					Player.sprite.setRotation(0);
				}
			}
		}

		std::cout << "X: " << Player.getCoordX() << "Y: " << Player.getCoordY() << std::endl; // отладка координат
 
		Player.update(time); //  оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться

		window.clear();
		GameField.SetFiled(window);
		Item.SetEnvironment(window);
		window.draw(Player.getSprite());
		window.display();
	}
 
	return 0;
}
