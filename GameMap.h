#pragma once
#ifndef __GAMEMAP__
#define __GAMEMAP__
#include "LaberynthPiece.h"

class GameMap : public BaseObject
{
public:
	GameMap(vec2d pos, vec2d size, vec2d number_pices);
	void Draw(SDL_Renderer* renderer);
	void Update();
	void Clean();
protected:
	vec2d m_number_pieces;
	std::vector<LaberynthPiece*> m_pieces;
};

#endif