#include "GameMap.h"

GameMap::GameMap(vec2d pos, vec2d size, vec2d number_pices)
{
	m_pos = pos;
	m_size = size;
	m_number_pieces = number_pices;
	// vec2d cellSize = size / number_pices;
	for (size_t i = 0; i < m_number_pieces.x; i++) {
		for (size_t j = 0; j < m_number_pieces.y; j++) {
			m_pieces.push_back(new LaberynthPiece(pos + m_size * vec2d{ (double)i, (double)j }, m_size));
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

char GameMap::GetCell(vec2d pos)
{
	vec2d map_pos = (pos - m_pos);
	vec2d piece_pos = map_pos / m_size;
	piece_pos.x = (int)piece_pos.x % (int)m_size.x;
	piece_pos.y = (int)piece_pos.y % (int)m_size.y;
	vec2d cell_pos = map_pos - piece_pos * m_size;
	cell_pos.x = (int)cell_pos.x / (int)10;
	cell_pos.y = (int)cell_pos.y / (int)10;
	//printf("Cell piece position: %.2lf %.2lf -- %.2lf %.2lf\n", piece_pos.x, piece_pos.y, cell_pos.x, cell_pos.y);
	return m_pieces[piece_pos.x * m_number_pieces.x + piece_pos.y]->GetCell(cell_pos);
}

