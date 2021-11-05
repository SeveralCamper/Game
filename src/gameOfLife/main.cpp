#include <SFML/Graphics.hpp>
#include <iostream>
#include "units.h"

int main() {
	Hero Allan(300, 30, 50, 50);

    std::cout << Allan.GetDMG() << std::endl;
    std::cout << Allan.GetHP() << std::endl;
	std::cout << Allan.GetCoordX() << std::endl;
    std::cout << Allan.GetCoordY() << std::endl;

	sf::RenderWindow window(sf::VideoMode(1000, 800), "Game");
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
		window.draw(Allan.getSprite());
		window.display();
	}
 
	return 0;
}