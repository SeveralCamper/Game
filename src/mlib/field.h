#ifndef FILED_H_
#define FILED_H_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "settings.h"
#include <string.h>

class Field {
    public:

    Field() {

        waterTexture.loadFromFile("sprites/tds-modern-tilesets-environment/Tiles/_0000_WTiles.png");
        waterSprite.setTexture(waterTexture);

        dirtTexture.loadFromFile("sprites/tds-modern-tilesets-environment/Tiles/_0001_DirtTiles.png");
        dirtSprite.setTexture(dirtTexture);

        dirtRoadTexture.loadFromFile("sprites/tds-modern-tilesets-environment/Tiles/_0001_DirtTiles.png");
        dirtRoadSprite.setTexture(dirtRoadTexture);

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

        sf::Texture dirtRoadTexture;
        sf::Sprite dirtRoadSprite;

        sf::Texture sandTexture;
        sf::Sprite sandSprite;

        sf::Texture grassTexture;
        sf::Sprite grassSprite;
};

class Environment {
    public:

    Environment() {

        // BRIGE

        bridge02Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Bridges/Sprite-0002.png");
        bridge02Sprite.setTexture(bridge02Texture);

        // HOUSES

        house01Texture.loadFromFile("sprites/tds-modern-tilesets-environment/House/TDS04_0000_House01.png");
        house01Sprite.setTexture(house01Texture);

        // TREES

        tree01Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0022_Tree1.png");
        tree01Sprite.setTexture(tree01Texture);

        tree01_1Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0022_Tree1.png");
        tree01_1Sprite.setTexture(tree01_1Texture);

        tree02Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0021_Tree2.png");
        tree02Sprite.setTexture(tree02Texture);

        tree03Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0019_Tree4.png");
        tree03Sprite.setTexture(tree03Texture);

        tree03_1Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0019_Tree4.png");
        tree03_1Sprite.setTexture(tree03_1Texture);

        tree04Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0008_Tree05.png");
        tree04Sprite.setTexture(tree04Texture);

        tree05Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0006_Tree07.png");
        tree05Sprite.setTexture(tree05Texture);

        // BUSHES

        bush01Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0012_Bush-01.png");
        bush01Sprite.setTexture(bush01Texture);

        bush02Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0013_Bush-04.png");
        bush02Sprite.setTexture(bush02Texture);

        bush03Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Trees Bushes/TDS04_0014_Bush-05.png");
        bush03Sprite.setTexture(bush03Texture);

        // ROCKS

        rock01Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Rocks/TDS04_0004_Rock02.png");
        rock01Sprite.setTexture(rock01Texture);

        rock01_1Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Rocks/TDS04_0004_Rock02.png");
        rock01_1Sprite.setTexture(rock01_1Texture);

        rock02Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Rocks/TDS04_0004_Rock05.png");
        rock02Sprite.setTexture(rock02Texture);

        rock03Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Rocks/TDS04_0004_Rock09.png");
        rock03Sprite.setTexture(rock03Texture);


        rock04Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Rocks/TDS04_0004_Rock07.png");
        rock04Sprite.setTexture(rock04Texture);

        rock05Texture.loadFromFile("sprites/tds-modern-tilesets-environment/Rocks/TDS04_0004_Rock04.png");
        rock05Sprite.setTexture(rock05Texture);

        // SANDBAGS

        sandBag01Texture.loadFromFile("sprites/tds-modern-tilesets-environment/SandBag/TDS04_0002_Sandbags01.png");
        sandBag01Sprite.setTexture(sandBag01Texture);

        sandBag02Texture.loadFromFile("sprites/tds-modern-tilesets-environment/SandBag/TDS04_0002_Sandbags02.png");
        sandBag02Sprite.setTexture(sandBag02Texture);

        sandBag03Texture.loadFromFile("sprites/tds-modern-tilesets-environment/SandBag/TDS04_0002_Sandbags07.png");
        sandBag03Sprite.setTexture(sandBag03Texture);

        // DIED FS

        diedFSTexture.loadFromFile("sprites/tds-pixel-art-modern-soldiers-and-vehicles-sprites/Soldier/FriendlySoldierDie.png");
        diedFSSprite.setTexture(diedFSTexture);

    }

    ~Environment() {

    }

    void SetEnvironment(sf::RenderWindow& window);

    private:

        // TREES

        sf::Texture tree01Texture;
        sf::Sprite tree01Sprite;

        sf::Texture tree01_1Texture;
        sf::Sprite tree01_1Sprite;

        sf::Texture tree02Texture;
        sf::Sprite tree02Sprite;

        sf::Texture tree03Texture;
        sf::Sprite tree03Sprite;

        sf::Texture tree03_1Texture;
        sf::Sprite tree03_1Sprite;

        sf::Texture tree04Texture;
        sf::Sprite tree04Sprite;

        sf::Texture tree05Texture;
        sf::Sprite tree05Sprite;

        // BUSHES

        sf::Texture bush01Texture;
        sf::Sprite bush01Sprite;

        sf::Texture bush02Texture;
        sf::Sprite bush02Sprite;

        sf::Texture bush03Texture;
        sf::Sprite bush03Sprite;

        // HOUSES

        sf::Texture house01Texture;
        sf::Sprite house01Sprite;

        // BRIGE

        sf::Texture bridge02Texture;
        sf::Sprite bridge02Sprite;

        // ROCKS

        sf::Texture rock01Texture;
        sf::Sprite rock01Sprite;

        sf::Texture rock01_1Texture;
        sf::Sprite rock01_1Sprite;

        sf::Texture rock02Texture;
        sf::Sprite rock02Sprite;

        sf::Texture rock03Texture;
        sf::Sprite rock03Sprite;


        sf::Texture rock04Texture;
        sf::Sprite rock04Sprite;

        sf::Texture rock05Texture;
        sf::Sprite rock05Sprite;

        // SANDBAGS

        sf::Texture sandBag01Texture;
        sf::Sprite sandBag01Sprite;

        sf::Texture sandBag02Texture;
        sf::Sprite sandBag02Sprite;

        sf::Texture sandBag03Texture;
        sf::Sprite sandBag03Sprite;

        // DIED FS

        sf::Texture diedFSTexture;
        sf::Sprite diedFSSprite;


};

#endif //  FILED_H_