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
        texture.loadFromFile("../../sprites/tds-modern-hero-weapons-and-props/Hero_pistol/Hero_Pistol.png");
    }

    Hero(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        texture.loadFromFile("../../sprites/tds-modern-hero-weapons-and-props/Hero_pistol/Hero_Pistol.png");
    }

    protected:

    sf::Texture texture;
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
        texture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/FriendlySoldier.png");
    }

    FriendlySoldier(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        texture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/FriendlySoldier.png");
    }

    protected:

    sf::Texture texture;
};

class EnemySoldier : public AIUnits {
    public:

    EnemySoldier() {
        HP = 100;
        DMG = 20;
        texture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier.png");
    }

    EnemySoldier(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        texture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier.png");
    }

    protected:

    sf::Texture texture;
};

class EnemySniper : public AIUnits {
    public:

    EnemySniper() {
        HP = 100;
        DMG = 20;
        texture.loadFromFile("../../sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper.png");
    }

    EnemySniper(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        texture.loadFromFile("../../sprites/tds-modern-soldiers-and-vehicles-sprites-2/Sniper.png");
    }

    protected:

    sf::Texture texture;
};

class Boss : public AIUnits {
    public:

    Boss() {
        HP = 1000;
        DMG = 25;
        texture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/BTR/BTR.png");
    }

    Boss(int HP, int DMG, float coordinateX, float coordinateY) {
        this->HP = HP;
        this->DMG = DMG;
        this->coordinateX = coordinateX;
        this->coordinateY = coordinateY;
        this->texture.loadFromFile("../../sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/BTR/BTR.png");
    }

    protected:

    sf::Texture texture;
};

#endif //  UNITS_H_
