#include "enemyAdd.h"

void enemyListSpawn(std::list<EnemySoldier*> &entities, int amount) {
    srand(time(NULL));
 	for (int i = 0; i < amount; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		entities.push_back(new EnemySoldier("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/Soldier.png", 
	"sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/Die/SD_04.png", "Soldier", 885 + (rand() % 70), 925 + (rand() % 50) , 10, 14));
	}
	for (int i = 0; i < 3; i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		entities.push_back(new EnemySoldier("sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper/Sniper.png", 
	"sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper/Die/SniperDIe_04.png", "Sniper", 885 + (rand() % 70), 925 + (rand() % 50) , 10, 14));
	}
}

void enemyListDelete(std::list<EnemySoldier*> &entities) {
    srand(time(NULL));
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
	entities.pop_back();
}
