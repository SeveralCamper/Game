#ifndef ENEMY_ADD_H_
#define ENEMY_ADD_H_

#include <list>
#include <ctime>
#include <thread>

#include "units.h"

void enemyListSpawn(std::list<EnemySoldier*> &entities);

#endif //  ENEMY_ADD_H_