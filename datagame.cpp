#include "datagame.h"

sf::RenderWindow* Global::currentWindow;

float Global::getAngulo(sf::Vector2f spr){
    const float PI = 3.14159265;
    sf::Vector2i m = sf::Mouse::getPosition(*currentWindow);
    sf::Vector2f mpos = currentWindow->mapPixelToCoords(m);
    float angulo = (atan2(mpos.y - spr.y, mpos.x - spr.x)) * 180 / PI;
    return angulo;
}

float Global::randomFloat(float LO, float HI){
float ar = LO + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(HI-LO)));
return ar;
}

sf::Vector2u Global::diffTo(sf::Vector2u startPos, sf::Vector2u endPos){
    sf::Vector2u diff(abs(int(startPos.x - endPos.x)), abs(int(startPos.y - endPos.y)));
    return diff;
}

sf::Vector2f Global::aimDirNorm(sf::Vector2f Pos, sf::Vector2f target){
    sf::Vector2f aimDir = target - Pos;
    //aimDir.x -= Pos.x;
    aimDir.x -= Global::currentWindow->getSize().x/2;
    //aimDir.y -= Pos.y;
    aimDir.y -= Global::currentWindow->getSize().y/2;
    sf::Vector2f aimDirNorm = aimDir / (static_cast<float>(sqrt(pow(aimDir.x, 2)+pow(aimDir.y, 2))));

    return aimDirNorm;
}
