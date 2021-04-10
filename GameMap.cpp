#include "GameMap.h"

GameMap::GameMap(vec2d pos, vec2d size, vec2d number_pices)
{
	m_pos = pos;
	m_size = size;
	m_number_pieces = number_pices;
	vec2d cellSize = size / number_pices;
	for (size_t i = 0; i < m_number_pieces.x; i++) {
		for (size_t j = 0; j < m_number_pieces.y; j++) {
			m_pieces.push_back(new LaberynthPiece(pos + cellSize * vec2d{ (double)i, (double)j }, cellSize));
		}
	}
}

void GameMap::Draw(SDL_Renderer* renderer)
{
	for (auto i : m_pieces)
		i->Draw(renderer);
}

void GameMap::Update()
{
}

void GameMap::Clean()
{
}

