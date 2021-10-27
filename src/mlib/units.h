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

        std::string GetName();

        Units() {
        
        }

        ~Units() {

        }

    protected:

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

    PlayerUnits(int HP, int DMG) {
        this->HP = HP;
        this->DMG = DMG;
    }

    protected:
};

class AIUnits : public Units {
    public:

    AIUnits() {
        HP = 100;
        DMG = 20;
    }

    AIUnits(int HP, int DMG) {
        this->HP = HP;
        this->DMG = DMG;
    }

    protected:
};

#endif //  UNITS_H_