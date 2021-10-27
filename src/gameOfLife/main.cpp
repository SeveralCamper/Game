#include <SFML/Graphics.hpp>
#include "units.h"

int main() {
	/*sf::RenderWindow window(sf::VideoMode(200, 200), "Lesson 1. kychka-pc.ru");
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
	}*/

    PlayerUnits Warrior(300, 100);

    std::cout << Warrior.GetDMG() << std::endl;
    std::cout << Warrior.GetHP() << std::endl;
 
	return 0;
}