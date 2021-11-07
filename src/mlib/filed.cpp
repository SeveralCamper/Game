#include "field.h"

float Field::GetFieldCoordX()
{
    return fieldXSize;
}

float Field::GetFiledCoordY()
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
        for (int j = 0; j < 5; j++)
        {
            if (fieldTilesArray[i][j] == 0)
            {
                if (i == 9 || j == 4)
                {
                    grassSprite.setPosition(-50 + 181 * i, -50 + 172 * j);
                    window.draw(grassSprite);
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
}

void Environment::SetEnvironment(sf::RenderWindow& window) {
    bridge02Sprite.setPosition(850, 460);
    bridge02Sprite.setScale(sf::Vector2f(1.5,1.5));
    window.draw(bridge02Sprite);

    house01Sprite.setPosition(825, 100);
    house01Sprite.setScale(sf::Vector2f(1.5,1.5));
    window.draw(house01Sprite);
}
