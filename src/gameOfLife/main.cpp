#include <SFML/Graphics.hpp>
#include <iostream>
#include "units.h"
#include "field.h"

int main()
{
	Field GameField;

	Environment Item;

	sf::RenderWindow window(sf::VideoMode(GameField.GetFieldCoordX(), GameField.GetFiledCoordY()), "Game");
	
	float CurrentFrame = 0; //  Xранит текущий кадр
	sf::Clock clock;
 
	Object Player("sprites/tds-modern-hero-weapons-and-props/Hero_Pistol/Hero_Pistol.png",250,250, 64, 64);
 
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
			Player.setDirection(1); Player.setSPeed(0.1); //  направление вверх
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3; 
		}
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))) {
			Player.setDirection(0); Player.setSPeed(0.1); //  направление вправо
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3; 
		}
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || (sf::Keyboard::isKeyPressed(sf::Keyboard::W)))) { 
			Player.setDirection(3); Player.setSPeed(0.1); //  направление вниз
			CurrentFrame += 0.005*time;
			if (CurrentFrame > 3) CurrentFrame -= 3;
		}	
 
		if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
			Player.setDirection(2); Player.setSPeed(0.1); //  направление вниз
			CurrentFrame += 0.005*time; //  служит для прохождения по "кадрам". переменная доходит до трех суммируя произведение времени и скорости. изменив 0.005 можно изменить скорость анимации
			if (CurrentFrame > 3) CurrentFrame -= 3;
		}
 
		Player.update(time); //  оживляем объект p класса Player с помощью времени sfml, передавая время в качестве параметра функции update. благодаря этому персонаж может двигаться

		window.clear();
		GameField.SetFiled(window);
		Item.SetEnvironment(window);
		window.draw(Player.getSPrite());
		window.display();
	}
 
	return 0;
}
