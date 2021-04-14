#pragma once
#ifndef __PLAYER__
#define __PLAYER__
#include "BaseObject.h"

class Player : public BaseObject
{
public:
    Player(vec2d pos, double radius);
    ~Player();
    void Draw(SDL_Renderer* renderer);
    void Update();
    void Clean();
    int getRadius() { return m_nRadius; };
protected:
    int m_nRadius;
};
#endif
