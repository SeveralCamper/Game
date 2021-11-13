#include "characterMoving.h"

void characterLeftMoving(Hero ExName) {
    if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))) {
        if (ExName.getCoordX() - 2 > FIELD_LEFT_BOARD) {
            if ((ExName.getCoordY() > RIVER_TOP_FIELD && ExName.getCoordY() < (RIVER_DOWN_FIELD)) && ((ExName.getCoordX() > BRIDGE_LEFT_BOARD && ExName.getCoordX() < 945))) {
                if (ExName.getCoordX() - 1 > BRIDGE_LEFT_BOARD) {
                    ExName.setDirection(1); ExName.setSPeed(0.1);
                    ExName.setSpriteRotation(90);
                }
            } else {
            ExName.setDirection(1); ExName.setSPeed(0.1); //  направление влево
            ExName.setSpriteRotation(90);
            }
        }
    }
}
