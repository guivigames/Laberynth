#pragma once
#ifndef __LABERYNTHPIECE__
#define __LABERYNTHPIECE__
#include "BaseObject.h"
#include <string>
#include <vector>

//std::string PosiblePieces[10];

class LaberynthPiece : public BaseObject
{
public:
	void Draw(SDL_Renderer* renderer);
	void Update();
	void Clean();
	LaberynthPiece(vec2d pos, vec2d size);
	std::string GetCell();
protected:
	std::string m_cell;
};

#endif
