#pragma once
#ifndef __PLAYER__
#define __PLAYER__
#include "BaseObject.h"


class Player : public BaseObject
{
private:
    Player();
    ~Player();
    void Draw();
    void Update();
    void Clean();
}
#endif
