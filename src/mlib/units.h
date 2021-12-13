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

        virtual std::string getObjectName() = 0; //
        virtual void update(float time) = 0;

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
        sf::Sprite getDieSprite();

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

    protected:
        bool isAlive = true;

        float coordX, coordY, directionX, directionY, speed = 0;

        int HP, DMG, spriteRotation = 0, direction = 0, range = 0;

        std::string objectName;

        sf::Sprite sprite;
        sf::Sprite dieSprite;

        sf::String filePath;
        sf::String dieFilePath;

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
    void update(float time) override;

    protected:
};

class Hero : public PlayerUnits {
    public:

    Hero() {
    }

    Hero(sf::String filePath, float coordX, float coordY, float spriteSizeX, float spriteSizeY) {
        this->filePath = filePath;
        this->dieFilePath = "sprites/tds-modern-hero-weapons-and-props/Hero_Die/4.png";

        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(sf::Vector2f(spriteSizeX,spriteSizeY));

        dieImage.loadFromFile(this->dieFilePath);
        dieTexture.loadFromImage(dieImage);
        dieSprite.setTexture(dieTexture);
        dieSprite.setOrigin(sf::Vector2f(14, 19));

        this->coordX = coordX; this->coordY = coordY;
        HP = 200;
        DMG = 20;
        range = 100;
    }

    protected:

};

class AIUnits : public Units {
    public:

    AIUnits() {

    }

    AIUnits(sf::String filePath, sf::String dieFilePath, float coordX, float coordY, float spriteSizeX, float spriteSizeY) {
        this->filePath = filePath;
        this->dieFilePath = dieFilePath;
        sprite.setRotation(180);
        dieSprite.setRotation(180);

        image.loadFromFile(this->filePath);
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(sf::Vector2f(spriteSizeX,spriteSizeY));

        dieImage.loadFromFile(this->dieFilePath);
        dieTexture.loadFromImage(dieImage);
        dieSprite.setTexture(dieTexture);
        dieSprite.setOrigin(sf::Vector2f(13, 19));

        this->coordX = coordX; this->coordY = coordY;
        HP = 100;
        DMG = 5;
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

    FriendlySoldier(sf::String filePath, sf::String dieFilePath, sf::String Name, float coordX, float coordY, float spriteSizeX, float spriteSizeY) 
    : AIUnits(filePath, dieFilePath, coordX, coordY, spriteSizeX, spriteSizeY) {
        if (Name == "Soldier") {
            HP = 200;
            DMG = 5;
            range = 100;
        }
    }

    void update(float time) override;

    protected:

};

class EnemySoldier : public AIUnits {
    public:

    EnemySoldier() {

    }

    EnemySoldier(sf::String filePath, sf::String dieFilePath, sf::String Name, float coordX, float coordY, float spriteSizeX, float spriteSizeY) 
    : AIUnits(filePath, dieFilePath, coordX, coordY, spriteSizeX, spriteSizeY) {
        if (Name == "Soldier") {
            HP = 100;
            DMG = 5;
            range = 100;
        } else if (Name == "Sniper") {
            HP = 50;
            DMG = 20;
            range = 350;           
        } else if (Name == "Capitan") {
            HP = 150;
            DMG = 15;
            range = 150; 
        } else if (Name == "BOSS") {
            HP = 500;
            DMG = 25;
            range = 100;            
        }
    }

    void update(float time) override;

    protected:

};

#endif //  UNITS_H_
