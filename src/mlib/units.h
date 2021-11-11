#ifndef UNITS_H_
#define UNITS_H_

#include <SFML/Graphics.hpp>
#include <iostream>

// PARENTAL ABSTRACT OBJECT CLASS

class Object { // родительский класс объектов
    public:
        Object() {

        }

        ~Object() {

        }

        virtual std::string getObjectName() = 0;

        int getSpriteRotation();

        float getCoordX();
        float getCoordY();
        float getDirectionX();
        float getDirectionY();
        float getSPeed();

        sf::Sprite getSprite();
        sf::Texture getTexture();

        void setCoordX(float coordX);
        void setCoordY(float coordY);
        void setDirectionX(float directionX);
        void setDirectionY(float directionY);
        void setSPeed(float speed);
        void setDirection(int direction);
        void setSpriteRotation(int spriteRotation);

        void update(float time);

        sf::Sprite sprite;
 
    protected:
        float coordX, coordY, directionX, directionY, speed = 0;

        int HP, DMG, spriteRotation = 0, direction = 0;

        std::string objectName;

        sf::String filePath;
        sf::Image image;
        sf::Texture texture;

};

// STRUCTURES CLASS

class Structures : public Object {
    public:

    Structures() {

    }

    Structures(sf::String filePath, float coordX, float coordY) {
        this->filePath = filePath;
        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        this->coordX = coordX; this->coordY = coordY;
    }

    ~Structures() {

    }

    std::string getObjectName() override;

    private:
};

// UNITS CLASS

class Units : public Object {
    public:

        Units() {
        
        }

        ~Units() {

        }

    protected:

};

class PlayerUnits : public Units {
    public:

    PlayerUnits() {

    }

    std::string getObjectName() override;

    protected:
};

class Hero : public PlayerUnits {
    public:

    Hero() {
    }

    Hero(sf::String filePath, float coordX, float coordY) {
        this->filePath = filePath;
        sprite.setRotation(180);
        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        this->coordX = coordX; this->coordY = coordY;
    }

    protected:

};

class AIUnits : public Units {
    public:

    AIUnits() {

    }

    ~AIUnits() {

    }

    std::string getObjectName() override;

    protected:

};

class FriendlySoldier : public AIUnits {
    public:

    FriendlySoldier() {

    }

    FriendlySoldier(sf::String filePath, float coordX, float coordY) {
        this->filePath = filePath;
        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        this->coordX = coordX; this->coordY = coordY;
    }

    protected:

};

class EnemySoldier : public AIUnits {
    public:

    EnemySoldier() {

    }

    EnemySoldier(sf::String filePath, float coordX, float coordY) {
        this->filePath = filePath;
        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        this->coordX = coordX; this->coordY = coordY;
    }

    protected:

};

class EnemySniper : public AIUnits {
    public:

    EnemySniper() {

    }

    EnemySniper(sf::String filePath, float coordX, float coordY) {
        this->filePath = filePath;
        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        this->coordX = coordX; this->coordY = coordY;
    }

    protected:

};

class Boss : public AIUnits {
    public:

    Boss() {

    }

    Boss(sf::String filePath, float coordX, float coordY) {
        this->filePath = filePath;
        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        this->coordX = coordX; this->coordY = coordY;
    }
    

    protected:

};

#endif //  UNITS_H_
