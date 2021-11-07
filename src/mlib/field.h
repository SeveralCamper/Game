#ifndef FILED_H_
#define FILED_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"

class Field {
    public:

    Field() {

        waterTexture.loadFromFile("sprites/tds-modern-tilesets-environment/Tiles/_0000_WTiles.png");
        waterSprite.setTexture(waterTexture);

        dirtTexture.loadFromFile("sprites/tds-modern-tilesets-environment/Tiles/_0001_DirtTiles.png");
        dirtSprite.setTexture(dirtTexture);

        sandTexture.loadFromFile("sprites/tds-modern-tilesets-environment/Tiles/_0002_SandTiles.png");
        sandSprite.setTexture(sandTexture);

        grassTexture.loadFromFile("sprites/tds-modern-tilesets-environment/Tiles/_0003_GrassTiles.png");
        grassSprite.setTexture(grassTexture);

    }

    ~Field() {

    }

    void SetFiled(sf::RenderWindow& window);

    float GetFieldCoordX();
    float GetFiledCoordY();

    private:

        int fieldTilesArray[9][5];

        float fieldXSize = 1600;
        float fieldYSize = 1200;

        sf::Texture waterTexture;
        sf::Sprite waterSprite;

        sf::Texture dirtTexture;
        sf::Sprite dirtSprite;

        sf::Texture sandTexture;
        sf::Sprite sandSprite;

        sf::Texture grassTexture;
        sf::Sprite grassSprite;
};

class Environment {
    public:

    Environment() {

        bridge02Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Bridges/Sprite-0002.png");
        bridge02Sprite.setTexture(bridge02Texture);

        house01Texture.loadFromFile("sprites/tds-modern-tilesets-environment/House/TDS04_0000_House01.png");
        house01Sprite.setTexture(house01Texture);
    }

    ~Environment() {

    }

    void SetEnvironment(sf::RenderWindow& window);

    private:

        sf::Texture house01Texture;
        sf::Sprite house01Sprite;

        sf::Texture bridge02Texture;
        sf::Sprite bridge02Sprite;

        sf::Texture dirtTexture;
        sf::Sprite dirtSprite;

        sf::Texture sandTexture;
        sf::Sprite sandSprite;

        sf::Texture grassTexture;
        sf::Sprite grassSprite;
};

#endif //  FILED_H_