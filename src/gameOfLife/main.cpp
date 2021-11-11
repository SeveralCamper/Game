#include <SFML/Graphics.hpp>
#include <iostream>
#include "units.h"
#include "field.h"
#include "settings.h"

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
			if (Player.getCoordX() - 2 > FIELD_LEFT_BOARD) {
				if ((Player.getCoordY() > RIVER_TOP_FIELD && Player.getCoordY() < (RIVER_DOWN_FIELD)) && ((Player.getCoordX() > BRIDGE_LEFT_BOARD && Player.getCoordX() < 945))) {
					if (Player.getCoordX() - 1 > BRIDGE_LEFT_BOARD) {
						Player.setDirection(1); Player.setSPeed(0.1);
						Player.setSpriteRotation(90);
					}
				} else {
				Player.setDirection(1); Player.setSPeed(0.1); //  направление влево
				Player.setSpriteRotation(90);
				}
			}
		}
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
			if (Player.getCoordX() + 2 < FIELD_RIGHT_BOARD) {
				if ((Player.getCoordY() > RIVER_TOP_FIELD && Player.getCoordY() < (RIVER_DOWN_FIELD)) && ((Player.getCoordX() > BRIDGE_LEFT_BOARD && Player.getCoordX() < BRIDGE_RIGHT_BOARD))) {
					if (Player.getCoordX() + 1 < BRIDGE_RIGHT_BOARD) {
						Player.setDirection(0); Player.setSPeed(0.1);
						Player.setSpriteRotation(270);
					}
				} else {
					Player.setDirection(0); Player.setSPeed(0.1); //  направление вправо
					Player.setSpriteRotation(270);
				}
			}
		}
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) {
		if (Player.getCoordY() < (RIVER_TOP_FIELD + 1) || (Player.getCoordX() > BRIDGE_LEFT_BOARD && Player.getCoordX() < BRIDGE_RIGHT_BOARD)) {
			if (Player.getCoordY() + 2 > FIELD_TOP_BOARD) {
				Player.setDirection(3); Player.setSPeed(0.1); //  направление вверх
				Player.setSpriteRotation(180);
				}
			} else if (Player.getCoordY() > RIVER_DOWN_FIELD + 15) {
				if (Player.getCoordY() - 2 > RIVER_DOWN_FIELD + 15) {
					Player.setDirection(3); Player.setSPeed(0.1); //  направление вверх
					Player.setSpriteRotation(180);
				}
			}
		}	
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
			if (Player.getCoordY() < (RIVER_TOP_FIELD - 1) || (Player.getCoordX() > BRIDGE_LEFT_BOARD && Player.getCoordX() < BRIDGE_RIGHT_BOARD)) {
				if (Player.getCoordY() - 2 < RIVER_TOP_FIELD || ((Player.getCoordX() > BRIDGE_LEFT_BOARD && Player.getCoordX() < BRIDGE_RIGHT_BOARD) && (Player.getCoordY() - 1 < FIELD_DOWN_BOARD))) {
					Player.setDirection(2); Player.setSPeed(0.1); //  направление вниз
					Player.setSpriteRotation(0);
				}
			} else if(Player.getCoordY() > RIVER_DOWN_FIELD) {
				if (Player.getCoordY() - 2 < BRIDGE_LEFT_BOARD) {
					Player.setDirection(2); Player.setSPeed(0.1); //  направление вниз
					Player.setSpriteRotation(0);
				}
			}
		}

		// std::cout << "X: " << Player.getCoordX() << "Y: " << Player.getCoordY() << std::endl; // отладка координат
 
		Player.update(time); //  оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться

		window.clear();
		GameField.SetFiled(window);
		Item.SetEnvironment(window);
		window.draw(Player.getSprite());
		Item.SetEnvironmentTrees(window);
		window.display();
	}
 
	return 0;
}
