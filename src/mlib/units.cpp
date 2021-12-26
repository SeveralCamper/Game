#include "units.h"

// HERO CLASS

void PlayerUnits::update(float time) {
    switch (direction) {
        case 0: directionX = speed; directionY = 0;   break; //  движение вправо
        case 1: directionX = -speed; directionY = 0;   break; //  движение влево
        case 2: directionX = 0; directionY = speed;   break; //  движение вниз
        case 3: directionX = 0; directionY = -speed;   break; //  движение вверх
    }

    if (HP <= 0)  {
        isAlive = false;
        sprite.setTexture(getDieTexture());
    }
    coordX += directionX * time;
    coordY += directionY * time;
    
    speed = 0; // остановка персонажа
    sprite.setPosition(coordX,coordY);
    dieSprite.setPosition(coordX,coordY);
}

// PARENTAL ABSTRACT OBJECT CLASS

bool Object::getIsAlive() {
    return isAlive;
}

int Object::getHP() {
    return HP;
}

int Object::getDMG() {
    return DMG;
}

int Object::getRange() {
    return range;
}

int Object::getSpriteRotation() {
    return spriteRotation;
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

sf::Sprite Object::getSprite() {
    if (isAlive) {
        return sprite;
    } else {
        return dieSprite;
    }
}

sf::Sprite Object::getDieSprite() {
    return dieSprite;
}

sf::Sprite Object::getFireSprite() {
    return fireSprite;
}

sf::Texture Object::getTexture() {
    return texture;
}

sf::Texture Object::getDieTexture() {
    return dieTexture;
}

sf::Texture Object::getFireTexture() {
    return fireTexture;
}

void Object::setHP(int HP) {
    this->HP = HP;
}

void Object::setDMG(int DMG) {
    this->DMG = DMG;
}

void Object::giveDMG(int DMG) {
    this->HP = this->HP - DMG;
}

void Object::setIsAlive(bool isAlive) {
    this->isAlive = isAlive;
}

void Object::setSpriteRotation(int spriteRotation) {
    this->spriteRotation = spriteRotation;
    sprite.setRotation(spriteRotation);
    dieSprite.setRotation(spriteRotation);
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

void Object::setSprite(sf::Texture newTexture) {
    getSprite().setTexture(newTexture);
}

// STRUCTURES CLASS

std::string Structures::getObjectName() {
    return objectName;
}

void Structures::update(float time) {
    if (HP <= 0)  {
        isAlive = false;
    }
    if (time < 0) {
        HP += 0;
    }
    
    sprite.setPosition(coordX,coordY);
}

// UNITS CLASS

std::string PlayerUnits::getObjectName() {
    return objectName;
}

std::string AIUnits::getObjectName() {
    return objectName;
}

void EnemySoldier::update(float time) {
    directionX = 0; directionY = -speed;

    if (HP <= 0)  {
        isAlive = false;
        sprite.setTexture(getDieTexture());
    }
    coordX += directionX * time;
    coordY += directionY * time;
    
    speed = 0; // остановка персонажа
    sprite.setPosition(coordX,coordY);
    dieSprite.setPosition(coordX,coordY);
    fireSprite.setPosition(coordX,coordY);
}

void FriendlySoldier::update(float time) {
    if (HP <= 0)  {
        isAlive = false;
        sprite.setTexture(getDieTexture());
    }
    if (time < 0) {
        HP += 0;
    }
    
    sprite.setPosition(coordX,coordY);
    dieSprite.setPosition(coordX,coordY);
    fireSprite.setPosition(coordX,coordY);
}
