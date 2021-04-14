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
	void setPos(vec2d pos) { m_pos = pos; };
	void setSize(vec2d size) { m_size = size; };
	void setVel(vec2d vel) { m_vel = vel; };
	vec2d getPos(void) { return m_pos; };
	vec2d getSize(void) { return m_size; };
	vec2d getVel(void) { return m_vel; };
protected:
	vec2d m_pos;
	vec2d m_size;
	vec2d m_vel;
};

#endif