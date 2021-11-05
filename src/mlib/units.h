#ifndef UNITS_H_
#define UNITS_H_

#include <SFML/Graphics.hpp>
#include <iostream>

class Structures {
    private:

    public:
};

class Units {
    public:

        int GetHP();
        int GetDMG();

        float GetCoordX();
        float GetCoordY();

        std::string GetName();

        Units() {
        
        }

        ~Units() {

        }

    protected:

        float coordinateX;
        float coordinateY;

        int HP;
        int DMG;
        std::string unitName;

};

class PlayerUnits : public Units {
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
        friendlySoldierTexture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/FriendlySoldier.png");
        friendlySoldierSprite.setTexture(friendlySoldierTexture);
        friendlySoldierSprite.setPosition(0, 0);
    }

    FriendlySoldier(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        friendlySoldierTexture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/FriendlySoldier.png");
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
        enemySoldierTexture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier.png");
        enemySoldierSprite.setTexture(enemySoldierTexture);
        enemySoldierSprite.setPosition(0, 0);
    }

    EnemySoldier(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        enemySoldierTexture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier.png");
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
        enemySniperTexture.loadFromFile("../../sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper.png");
        enemySniperSprite.setTexture(enemySniperTexture);
        enemySniperSprite.setPosition(0, 0);
    }

    EnemySniper(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        enemySniperTexture.loadFromFile("../../sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper.png");
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
        bossTexture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/BTR/BTR.png");
        this->bossSprite.setTexture(bossTexture);
        bossSprite.setPosition(0, 0);
    }

    Boss(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        bossTexture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/BTR/BTR.png");
        bossSprite.setTexture(bossTexture);
        bossSprite.setPosition(coordinateX, coordinateY);
    }

    sf::Sprite getSprite() {
        return bossSprite;
    }
    

    protected:

    sf::Texture bossTexture;
    sf::Sprite bossSprite;
};

#endif //  UNITS_H_
