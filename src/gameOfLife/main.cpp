#include <SFML/Graphics.hpp>
#include <iostream>
#include "units.h"
#include "field.h"

int main() {
	Field GameField;

	Environment Item;

	Hero Allan(300, 30, 100, 100);
	FriendlySoldier SoldierF1(300, 30, 50, 50);
	EnemySoldier SoldierE1(300, 30, 150, 150);
	EnemySniper SniperE1(300, 30, 200, 200);
	Boss BTR(1000, 100, 300, 300);

    std::cout << Allan.GetDMG() << std::endl;
    std::cout << Allan.GetHP() << std::endl;
	std::cout << Allan.GetCoordX() << std::endl;
    std::cout << Allan.GetCoordY() << std::endl;

	sf::RenderWindow window(sf::VideoMode(GameField.GetFieldCoordX(), GameField.GetFiledCoordY()), "Game");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
 
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		GameField.SetFiled(window);
		Item.SetEnvironment(window);
		window.draw(Allan.getSprite());
		window.draw(SoldierF1.getSprite());
		window.draw(SoldierE1.getSprite());
		window.draw(SniperE1.getSprite());
		window.draw(BTR.getSprite());
		window.display();
	}
 
	return 0;
}