#include "enemyAdd.h"

void enemyListSpawn(std::list<EnemySoldier*> &entities) {
    srand(time(NULL));
 	for (int i = 0; i < 5; i ++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		entities.push_back(new EnemySoldier("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/Soldier.png", 
	"sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/Die/SD_04.png", "Soldier", 885 + (rand() % 70), 925 + (rand() % 50) , 10, 14));
	}
}