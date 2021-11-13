#include "field.h"

float Field::GetFieldXSize()
{
    return fieldXSize;
}

float Field::GetFieldYSize()
{
    return fieldYSize;
}

void Field::SetFiled(sf::RenderWindow &window)
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 3)
            {
                fieldTilesArray[i][j] = 1;
            }
            else
            {
                fieldTilesArray[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (fieldTilesArray[i][j] == 0)
            {
                if ((i == 9 || j == 4) || (j == 5))
                {
                    grassSprite.setPosition(-50 + 181 * i, -50 + 172 * j);
                    window.draw(grassSprite);
                    if (i == 9 || j == 5) {
                        grassSprite.setPosition(-50 + 181 * i, -50 + 172 * (j+1));
                        window.draw(grassSprite);
                    }
                    if (j == 4)
                    {
                        grassSprite.setPosition(-50 + 160 * i, -50 + 172 * j);
                        window.draw(grassSprite);
                    }
                }
                else
                {
                    grassSprite.setPosition(-50 + 200 * i, -50 + 200 * j);
                    window.draw(grassSprite);
                }
            }
            else if (fieldTilesArray[i][j] == 1)
            {
                waterSprite.setPosition(-50 + 181 * i, -50 + 172 * j);
                window.draw(waterSprite);
            }
            else if (fieldTilesArray[i][j] == 2)
            {
                if (j == 1)
                {
                    dirtSprite.setPosition(-50 + 200 * i, -50 + 150 * j);
                    window.draw(dirtSprite);
                }
                else
                {
                    dirtSprite.setPosition(-50 + 200 * i, -50 + 200 * j);
                    window.draw(dirtSprite);
                }
            }
            else if (fieldTilesArray[i][j] == 3)
            {
            }
        }
    }

    for (int i = 3; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 1)
                {
                    dirtSprite.setPosition(-50 + 200 * i, -50 + 150 * j);
                    window.draw(dirtSprite);
                }
                else
                {
                    dirtSprite.setPosition(-50 + 200 * i, -50 + 200 * j);
                    window.draw(dirtSprite);
                }
        }
    }

    dirtRoadSprite.setPosition(812, 720);
    dirtRoadSprite.setScale(sf::Vector2f(0.7,0.7));
    window.draw(dirtRoadSprite);


    dirtRoadSprite.setPosition(812, 660);
    window.draw(dirtRoadSprite);

    dirtRoadSprite.setPosition(812, 305);
    window.draw(dirtRoadSprite);
}

void Environment::SetEnvironmentTrees(sf::RenderWindow& window) {
    // HOUSE

    house01Sprite.setPosition(825, 100);
    house01Sprite.setScale(sf::Vector2f(1.5,1.5));
    window.draw(house01Sprite);

    // BUSHES

    bush01Sprite.setPosition(1310, 200);
    bush01Sprite.setScale(sf::Vector2f(1.5,1.5));
    window.draw(bush01Sprite);

    bush01Sprite.setPosition(320, 385);
    window.draw(bush01Sprite);

    bush01Sprite.setPosition(670, 760);
    window.draw(bush01Sprite);

    bush01Sprite.setPosition(1090, 840);
    window.draw(bush01Sprite);

    bush02Sprite.setPosition(1750, 800);
    window.draw(bush02Sprite);

    bush02Sprite.setPosition(1500, 40);
    window.draw(bush02Sprite);

    bush02Sprite.setPosition(150, 100);
    window.draw(bush02Sprite);

    bush03Sprite.setPosition(1000, 700);
    window.draw(bush03Sprite);

    bush03Sprite.setPosition(1500, 130);
    window.draw(bush03Sprite);

    bush03Sprite.setPosition(150, 800);
    window.draw(bush03Sprite);

    bush03Sprite.setPosition(500, 465);
    window.draw(bush03Sprite);

    // TREES

    tree02Sprite.setPosition(10, 410);
    window.draw(tree02Sprite);

    tree01Sprite.setPosition(100, 300);
    window.draw(tree01Sprite);

    tree01Sprite.setPosition(20, 130);
    tree01Sprite.setRotation(30);
    window.draw(tree01Sprite);

    tree01Sprite.setPosition(1400, 20);
    window.draw(tree01Sprite);

    tree01Sprite.setPosition(1550, 150);
    window.draw(tree01Sprite);

    tree01Sprite.setPosition(1260, 230);
    window.draw(tree01Sprite);

    tree01_1Sprite.setPosition(1800, 230);
    tree01_1Sprite.setRotation(65);
    window.draw(tree01_1Sprite);

    tree01_1Sprite.setPosition(400, 0);
    window.draw(tree01_1Sprite);

    tree02Sprite.setPosition(20, 20);
    window.draw(tree02Sprite);

    tree02Sprite.setPosition(1510, 800);
    window.draw(tree02Sprite);

    tree02Sprite.setPosition(210, 0);
    window.draw(tree02Sprite);

    tree02Sprite.setPosition(1510, 800);
    window.draw(tree02Sprite);

    tree02Sprite.setPosition(550, 150);
    window.draw(tree02Sprite);

    tree02Sprite.setPosition(210, 0);
    window.draw(tree02Sprite);

    tree02Sprite.setPosition(210, 0);
    window.draw(tree02Sprite);

    tree02Sprite.setPosition(210, 0);
    window.draw(tree02Sprite);

    tree03Sprite.setPosition(990, 320);
    tree03Sprite.setScale(sf::Vector2f(1.5,1.5));
    window.draw(tree03Sprite);

    tree03_1Sprite.setPosition(190, 810);
    tree03_1Sprite.setRotation(170);
    window.draw(tree03_1Sprite);

    tree03_1Sprite.setPosition(1700, 210);
    window.draw(tree03_1Sprite);

    tree03_1Sprite.setPosition(1850, 130);
    window.draw(tree03_1Sprite);

    tree03_1Sprite.setPosition(1760, 790);
    window.draw(tree03_1Sprite);

}

void Environment::SetEnvironment(sf::RenderWindow& window) {
    // BRIGE

    bridge02Sprite.setPosition(850, 460);
    bridge02Sprite.setScale(sf::Vector2f(1.5,1.5));
    window.draw(bridge02Sprite);

    // ROCKS

    rock01Sprite.setPosition(580, 50);
    window.draw(rock01Sprite);

    rock01Sprite.setPosition(1560, 400);
    window.draw(rock01Sprite);

    rock01_1Sprite.setPosition(300, 780);
    rock01_1Sprite.setRotation(140);
    window.draw(rock01_1Sprite);

    rock02Sprite.setPosition(1240, 10);
    window.draw(rock02Sprite);

    rock02Sprite.setPosition(1590, 830);
    window.draw(rock02Sprite);

    rock03Sprite.setPosition(820, 860);
    window.draw(rock03Sprite);

    rock03Sprite.setPosition(20, 340);
    window.draw(rock03Sprite);

    rock04Sprite.setPosition(1740, 160);
    rock04Sprite.setRotation(150);
    window.draw(rock04Sprite);

    rock05Sprite.setPosition(1340, 640);
    rock05Sprite.setScale(sf::Vector2f(2,2));
    window.draw(rock05Sprite);

    // SANDBAGS

    sandBag01Sprite.setPosition(720, 350);
    window.draw(sandBag01Sprite);

    sandBag01Sprite.setPosition(865, 262);
    window.draw(sandBag01Sprite);

    sandBag01Sprite.setPosition(900, 350);
    window.draw(sandBag01Sprite);

    sandBag02Sprite.setPosition(990, 350);
    window.draw(sandBag02Sprite);

    sandBag03Sprite.setPosition(1000, 800);
    window.draw(sandBag03Sprite);

    // DIED FS

    diedFSSprite.setPosition(1013,778);
    window.draw(diedFSSprite);

    // TREES

    tree04Sprite.setPosition(1780, 220);
    window.draw(tree04Sprite);

    tree04Sprite.setPosition(10, 840);
    window.draw(tree04Sprite);

    tree05Sprite.setPosition(1100, 40);
    window.draw(tree05Sprite);

    tree05Sprite.setPosition(1200, 110);
    window.draw(tree05Sprite);

    tree05Sprite.setPosition(1180, 330);
    window.draw(tree05Sprite);

    tree05Sprite.setPosition(410, 790);
    window.draw(tree05Sprite);
}
