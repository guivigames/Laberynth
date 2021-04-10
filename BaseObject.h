#pragma once
#ifndef __GAMEOBJECT__
#define __GAMEOBJECT__
#include <SDL.h>
#include "GameMath.h"


class BaseObject
{
public:
	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void Update() = 0;
	virtual void Clean() = 0;
protected:
	vec2d m_pos;
	vec2d m_size;
	vec2d m_vel;
};

#endif