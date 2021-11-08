#include "units.h"

// PARENTAL ABSTRACT OBJECT CLASS

void Object::update(float time) {
    switch (direction) {
        case 0: directionX = speed; directionY = 0;   break; //  движение вправо
        case 1: directionX = -speed; directionY = 0;   break; //  движение влево
        case 2: directionX = 0; directionY = speed;   break; //  движение вниз
        case 3: directionX = 0; directionY = -speed;   break; //  движение вверх
    }
    
    coordX += directionX * time;
    coordY += directionY * time;
    
    speed = 0; // остановка персонажа
    sprite.setPosition(coordX,coordY);
}

float Object::getCoordX() {
    return coordX;
}

float Object::getCoordY() {
    return coordY;
}

float Object::getDirectionX() {
    return directionX;
}

float Object::getDirectionY() {
    return directionY;
}

float Object::getSPeed() {
    return speed;
}

sf::Sprite Object::getSPrite() {
    return sprite;
}

void Object::setCoordX(float coordX) {
    this->coordX = coordX;
}

void Object::setCoordY(float coordY) {
    this->coordY = coordY;
}

void Object::setDirectionX(float directionX) {
    this->directionX = directionX;
}

void Object::setDirectionY(float directionY) {
    this->directionY = directionY;
}

void Object::setSPeed(float speed) {
    this->speed = speed;
}

void Object::setDirection(int direction) {
    this->direction = direction;
}

// UNITS CLASS

std::string Units::getObjectName() {
    return objectName;
}
