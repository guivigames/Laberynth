#pragma once
#ifndef __LABERYNTHPIECE__
#define __LABERYNTHPIECE__
#include "BaseObject.h"
#include <string>
#include <vector>

enum class PIECES {
	TOPLEFT = 0,
	TOPRIGHT = 1,
	BOTTOMLEFT = 2,
	BOTTOMRIGHT = 3,
	VERTICAL = 4,
	HORYZONTAL = 5,
	TLEFT = 6,
	TRIGHT = 7,
	TTOP = 8,
	TBOTTOM = 9
};
extern std::string PosiblePieces[10];
class LaberynthPiece : public BaseObject
{
public:
	void Draw(SDL_Renderer* renderer);
	void Update();
	void Clean();
	LaberynthPiece(vec2d pos, vec2d size);
	LaberynthPiece(vec2d pos, vec2d size, PIECES piece);
	char GetCell(vec2i pos);
protected:
	//std::string m_cell;
	PIECES m_cell;
};
#endif
