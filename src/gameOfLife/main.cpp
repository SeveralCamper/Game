#include <SFML/Graphics.hpp>
#include "units.h"

int main() {
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
		window.draw(shape);
		window.display();
	}

    Hero Warrior(300, 30, 50, 50);

    std::cout << Warrior.GetDMG() << std::endl;
    std::cout << Warrior.GetHP() << std::endl;
	std::cout << Warrior.GetCoordX() << std::endl;
    std::cout << Warrior.GetCoordY() << std::endl;
 
	return 0;
}
