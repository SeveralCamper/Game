#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
#include <list>

#include "units.h"
#include "field.h"
#include "enemyAdd.h"
#include "settings.h"

int main() {
	Menu Menu;
	Field GameField;
	Environment Item;

	sf::Clock clock;
	sf::Sprite spriteEnd;

	Hero Player("sprites/tds-modern-hero-weapons-and-props/Hero_Pistol/Hero_Pistol.png", 250, 250, 8.5, 14);
	FriendlySoldier FS1("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/FriendlySoldier.png", 
	"sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/FriendlySoldierDie.png", 920, 270, 8.5, 14);
	Structures Base("sprites/tds-modern-tilesets-environment/House/TDS04_0000_House01.png", 925, 200, 66, 66);


	std::list<EnemySoldier*> entities;
	std::list<EnemySoldier*>::iterator it;

	std::vector<std::thread> thread_pool;
	std::thread th(enemyListSpawn, std::ref(entities), 10);

	sf::RenderWindow window(sf::VideoMode(GameField.GetFieldXSize(), GameField.GetFieldYSize()), "Game");

	int endFlagLose = 0, endFlagWin = 0, fireFlag = 0;

	while (window.isOpen()) {
		if (!endFlagLose && !endFlagWin) {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
 
 
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
 
		//  CHARACTER CONTROL
		if (Player.getIsAlive() && Base.getIsAlive()) {
			// std::cout << "X: " << Player.getCoordX() << std::endl;
			// std::cout << "Y: " << Player.getCoordY() << std::endl;
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
				if (Player.getCoordX() - 5 > FIELD_LEFT_BOARD) {
					if (((Player.getCoordY() > RIVER_TOP_FIELD && Player.getCoordY() < RIVER_DOWN_FIELD))) {
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
				if (Player.getCoordX() + 5 < FIELD_RIGHT_BOARD) {
					if (((Player.getCoordY() > RIVER_TOP_FIELD && Player.getCoordY() < RIVER_DOWN_FIELD))) {
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
				if (Player.getCoordY() < RIVER_TOP_FIELD || (Player.getCoordX() + 5 > BRIDGE_LEFT_BOARD && Player.getCoordX() - 5 < BRIDGE_RIGHT_BOARD)) {
					if (Player.getCoordY() + 5 > FIELD_TOP_BOARD) {
						Player.setDirection(3); Player.setSPeed(0.1); //  направление вверх
						Player.setSpriteRotation(180);
					}
				} else if (Player.getCoordY() + 5 > RIVER_DOWN_FIELD) {
					if (Player.getCoordY() - 2 > RIVER_DOWN_FIELD) {
						Player.setDirection(3); Player.setSPeed(0.1); //  направление вверх
						Player.setSpriteRotation(180);
					}
				}
			}	
	
			if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || (sf::Keyboard::isKeyPressed(sf::Keyboard::S)))) {
				if (Player.getCoordY() + 5 < RIVER_TOP_FIELD || (Player.getCoordX() + 5 > BRIDGE_LEFT_BOARD && Player.getCoordX() - 5 < BRIDGE_RIGHT_BOARD)) {
					if (Player.getCoordY() - 1 < FIELD_DOWN_BOARD) {
						Player.setDirection(2); Player.setSPeed(0.1); //  направление вниз
						Player.setSpriteRotation(0);
					}
				} else if(Player.getCoordY() + 5 > RIVER_DOWN_FIELD) {
					if (Player.getCoordY() - 2 < BRIDGE_LEFT_BOARD) {
						Player.setDirection(2); Player.setSPeed(0.1); //  направление вниз
						Player.setSpriteRotation(0);
					}
				}
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				for (it = entities.begin(); it != entities.end(); it++)  {
					if ((Player.getCoordY() + Player.getRange()) >= (*it)->getCoordY() && (Player.getCoordX() + Player.getRange()) >= (*it)->getCoordX()) {
						if ((*it)->getHP() != 0) {
							(*it)->giveDMG(Player.getDMG());
						}
					}
				}
				fireFlag = 1;
			}
			/* if (Player.getCoordX() < 1000 || Player.getCoordY() < 200) {
				Player.setHP(0);
			} */  // проверить конец игры
			for (it = entities.begin(); it != entities.end(); it++) {
				if ((*it)->getCoordY() < 400) {
					// ((*it)->setHP(0));
				}
			}  // проверить конец игры
		}	
		// std::cout << "X: " << Player.getCoordX() << "Y: " << Player.getCoordY() << std::endl; // отладка координат

		// AI CONTROL
		for (it = entities.begin(); it != entities.end(); it++) {
			if ((*it)->getCoordY() - (*it)->getRange() + 20 > 200 && (*it)->getHP() != 0) {
				(*it)->setSPeed(0.05);
			}
		}
 
		// ALL

		Player.update(time);
		FS1.update(time);
		Base.update(time);
		
		for (it = entities.begin(); it != entities.end(); it++) {
			(*it)->update(time);
		}


		window.clear();
		GameField.setFiled(window);
		Item.SetEnvironment(window);

		for (it = entities.begin(); it != entities.end(); it++) {
			window.draw((*it)->getSprite());
		}

		if (fireFlag != 0) {
			window.draw(Player.getFireSprite());
		} else {
			window.draw(Player.getSprite());
		}

		Item.SetEnvironmentTrees(window);

		window.draw(Base.getSprite());
		window.draw(FS1.getSprite());

		if (!Player.getIsAlive() || !Base.getIsAlive()) {
			Item.endGameLose(window);
			endFlagLose = 1;
		}

		for (it = entities.begin(); it != entities.end(); it++) {
			endFlagWin = 1;
			if ((*it)->getHP() > 0) {
				endFlagWin = 0;
				break;
			}
		}

		if (endFlagWin) {
			Item.endGameWin(window);
		}

		int BaseOrSolider;

		for (it = entities.begin(); it != entities.end(); it++) {
			if (((FS1.getCoordY() + FS1.getRange()) >= (*it)->getCoordY()) && (FS1.getHP() != 0) && ((*it)->getHP() != 0)) {
				FS1.incAttackCD();
				if (FS1.getAttackCD() == 142) {
					if ((*it)->getHP() != 0) {
						(*it)->giveDMG(FS1.getDMG());
						window.draw(FS1.getFireSprite());
					}
					FS1.setAttackCD(0);
				}
			}

			// printf("HP: %d\n", (*it)->getHP());

			if ((((*it)->getCoordY() - (*it)->getRange()) <= Base.getCoordY()) && ((*it)->getHP() != 0)) {
				(*it)->incAttackCD();
				if ((*it)->getAttackCD() == 112) {
					BaseOrSolider++;
					if (Base.getHP() != 0 && (*it)->getHP() != 0) {
						if (BaseOrSolider == 5 && FS1.getHP() != 0 && (*it)->getHP() != 0) {
							FS1.giveDMG((*it)->getDMG());
							window.draw((*it)->getFireSprite());
							BaseOrSolider = 0;
						} else if ((*it)->getHP() != 0) {
							Base.giveDMG((*it)->getDMG());
							window.draw((*it)->getFireSprite());
						}
					}
					printf("base: %d\n", Base.getHP());
					printf("fs1: %d\n", FS1.getHP());
					(*it)->setAttackCD(0);
				}
			}
			std::cout << "It HP:" << (*it)->getHP() << std::endl;
		}

		Menu.SetMenu(window);

        sf::Font font;
        font.loadFromFile("fonts/" + DEFAULT_FONT);
        sf::String Base_message = "Base HP = ";
		sf::String Horary_message = "Horary HP = ";
        Base_message += std::to_string(Base.getHP());
		Horary_message += std::to_string(FS1.getHP());

        sf::Text textStep(Base_message, font, DEFAULT_FONT_SIZE);
		sf::Text textStep_2(Horary_message, font, DEFAULT_FONT_SIZE);

        textStep.setPosition(sf::Vector2f(
                window.getSize().x - 990,
                window.getSize().y - 875));
        textStep_2.setPosition(sf::Vector2f(
                window.getSize().x - 995,
                window.getSize().y - 845));
		
        textStep.setFillColor(LIGHTY_BROWN_COLOR);
		textStep_2.setFillColor(LIGHTY_BROWN_COLOR);

        window.draw(textStep);
		window.draw(textStep_2);

		fireFlag = 0;

		window.display();		
		} else {
			int timeAfterDie = 0;
			while(timeAfterDie < 1000) {
				timeAfterDie++;
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
			window.close();
		}
	}
	th.join();

	return 0;
}
