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

        float getCoordX();
        float getCoordY();
        float getDirectionX();
        float getDirectionY();
        float getSPeed();

        sf::Sprite getSPrite();

        void setCoordX(float coordX);
        void setCoordY(float coordY);
        void setDirectionX(float directionX);
        void setDirectionY(float directionY);
        void setSPeed(float speed);

        void setDirection(int direction);

        void update(float time);
 
    protected:
        float coordX, coordY, directionX, directionY, speed = 0;

        int HP, DMG, direction = 0;

        std::string objectName;

        sf::String filePath;
        sf::Image image;
        sf::Texture texture;
        sf::Sprite sprite;

};

// STRUCTURES CLASS

class Structures : public Object {
    public:

    private:
};

// UNITS CLASS

class Units : public Object {
    public:

        Units() {
        
        }

        Units(sf::String filePath, float coordX, float coordY) {
            this->filePath = filePath;
            image.loadFromFile(this->filePath);
            texture.loadFromImage(image);
            sprite.setTexture(texture);
            this->coordX = coordX; this->coordY = coordY;
        }

        ~Units() {

        }

    std::string getObjectName() override;

    protected:

};

/* class PlayerUnits : public Units {
    public:

    PlayerUnits() {
        HP = 100;
        DMG = 20;
    }

    protected:
};

class Hero : public PlayerUnits {
    public:

    Hero() {
        HP = 300;
        DMG = 30;
        heroTexture.loadFromFile("sprites/tds-modern-hero-weapons-and-props/Hero_Pistol/Hero_Pistol.png");
        heroSprite.setTexture(heroTexture);
        heroSprite.setPosition(0, 0);
    }

    Hero(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        heroTexture.loadFromFile("sprites/tds-modern-hero-weapons-and-props/Hero_Pistol/Hero_Pistol.png");
        heroSprite.setTexture(heroTexture);
        heroSprite.setPosition(coordinateX, coordinateY);
    }

    sf::Sprite getSprite() {
        return heroSprite;
    }

    protected:

    sf::Texture heroTexture;
    sf::Sprite heroSprite;
};

class AIUnits : public Units {
    public:

    AIUnits() {
        HP = 100;
        DMG = 20;
    }

    AIUnits(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
    }

    protected:

};

class FriendlySoldier : public AIUnits {
    public:

    FriendlySoldier() {
        HP = 100;
        DMG = 20;
        friendlySoldierTexture.loadFromFile("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/FriendlySoldier.png");
        friendlySoldierSprite.setTexture(friendlySoldierTexture);
        friendlySoldierSprite.setPosition(0, 0);
    }

    FriendlySoldier(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        friendlySoldierTexture.loadFromFile("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/FriendlySoldier.png");
        friendlySoldierSprite.setTexture(friendlySoldierTexture);
        friendlySoldierSprite.setPosition(coordinateX, coordinateY);
    }

    sf::Sprite getSprite() {
        return friendlySoldierSprite;
    }

    protected:

    sf::Texture friendlySoldierTexture;
    sf::Sprite friendlySoldierSprite;
};

class EnemySoldier : public AIUnits {
    public:

    EnemySoldier() {
        HP = 100;
        DMG = 20;
        enemySoldierTexture.loadFromFile("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/Soldier.png");
        enemySoldierSprite.setTexture(enemySoldierTexture);
        enemySoldierSprite.setPosition(0, 0);
    }

    EnemySoldier(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        enemySoldierTexture.loadFromFile("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/Soldier.png");
        enemySoldierSprite.setTexture(enemySoldierTexture);
        enemySoldierSprite.setPosition(coordinateX, coordinateY);
    }

    sf::Sprite getSprite() {
        return enemySoldierSprite;
    }

    protected:

    sf::Texture enemySoldierTexture;
    sf::Sprite enemySoldierSprite;
};

class EnemySniper : public AIUnits {
    public:

    EnemySniper() {
        HP = 100;
        DMG = 20;
        enemySniperTexture.loadFromFile("sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper/Sniper.png");
        enemySniperSprite.setTexture(enemySniperTexture);
        enemySniperSprite.setPosition(0, 0);
    }

    EnemySniper(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        enemySniperTexture.loadFromFile("sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper/Sniper.png");
        enemySniperSprite.setTexture(enemySniperTexture);
        enemySniperSprite.setPosition(coordinateX, coordinateY);
    }

    sf::Sprite getSprite() {
        return enemySniperSprite;
    }

    protected:

    sf::Texture enemySniperTexture;
    sf::Sprite enemySniperSprite;
};

class Boss : public AIUnits {
    public:

    Boss() {
        HP = 1000;
        DMG = 25;
        bossTexture.loadFromFile("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/BTR/BTR.png");
        this->bossSprite.setTexture(bossTexture);
        bossSprite.setPosition(0, 0);
    }

    Boss(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        bossTexture.loadFromFile("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/BTR/BTR.png");
        bossSprite.setTexture(bossTexture);
        bossSprite.setPosition(coordinateX, coordinateY);
    }

    sf::Sprite getSprite() {
        return bossSprite;
    }
    

    protected:

    sf::Texture bossTexture;
    sf::Sprite bossSprite;
}; */

#endif //  UNITS_H_
