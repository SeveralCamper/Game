#ifndef UNITS_H_
#define UNITS_H_

#include <SFML/Graphics.hpp>
#include <iostream>

// PARENTAL ABSTRACT OBJECT CLASS

class Object {
    public:
        Object() {

        }

        ~Object() {

        }

        virtual std::string getObjectName() = 0;

        bool getIsAlive();

        int getSpriteRotation();
        int getHP();
        int getDMG();

        float getSPeed();
        float getCoordX();
        float getCoordY();
        float getDirectionX();
        float getDirectionY();

        sf::Sprite getSprite();

        sf::Texture getTexture();
        sf::Texture getDieTexture();

        void setHP(int HP);
        void setDMG(int DMG);
        void setSPeed(float speed);
        void setIsAlive(bool alive);
        void setCoordX(float coordX);
        void setCoordY(float coordY);
        void setDirection(int direction);
        void setDirectionX(float directionX);
        void setDirectionY(float directionY);
        void setSprite(sf::Texture newTexture);
        void setSpriteRotation(int spriteRotation);

        void update(float time);

    protected:
        bool isAlive = true;

        float coordX, coordY, directionX, directionY, speed = 0;

        int HP, DMG, spriteRotation = 0, direction = 0;

        std::string objectName;

        sf::Sprite sprite;

        sf::String filePath;
        sf::String diePath;

        sf::Image image;
        sf::Image dieImage;

        sf::Texture texture;
        sf::Texture dieTexture;

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

    Hero(sf::String filePath, float coordX, float coordY, float spriteSizeX, float spriteSizeY) {
        this->filePath = filePath;
        sprite.setRotation(180);

        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(sf::Vector2f(spriteSizeX,spriteSizeY));

        dieImage.loadFromFile("sprites/tds-modern-hero-weapons-and-props/Hero_Die/4.png");
        dieTexture.loadFromImage(dieImage);

        this->coordX = coordX; this->coordY = coordY;
        HP = 200;
        DMG = 20;
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
