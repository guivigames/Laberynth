#include "LaberynthPiece.h"

std::string PosiblePieces[10] =
{
	"###"
	"#.."		// Top left corner
	"#.#",
	"###"
	"..#"		// Top right corner
	"#.#",
	"#.#"
	"#.."		// Bottom left corner
	"###",
	"#.#"
	"..#"		// Bottom right corner
	"###",
	"#.#"
	"#.#"		// Vertical
	"#.#",
	"###"
	"..."		// Horyzontal
	"###",
	"#.#"
	"#.."		// T-Left
	"#.#",
	"#.#"
	"..#"		// T-Right
	"#.#",
	"###"
	"..."		// T-Top
	"#.#",
	"#.#"
	"..."		// T-Bottom
	"###",
};

void LaberynthPiece::Draw(SDL_Renderer* renderer)
{
	SDL_Rect rect;	
	double square = sqrt(PosiblePieces[(int)m_cell].size());
	for (size_t i = 0; i < square; i++) {
		for (size_t j = 0; j < square; j++){
			rect.x = (int) (m_pos.x + (m_size.x / square * i));
			rect.y = (int) (m_pos.y + (m_size.y / square * j));
			rect.w = (int) (m_size.x / square);
			rect.h = (int) (m_size.y / square);
			if (PosiblePieces[(int)m_cell][j * (int) square + i] == '#')
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // the rect color (solid red)	
			else if (PosiblePieces[(int)m_cell][j * (int) square + i] == '.')
				SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // the rect color (solid black)	
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}

void LaberynthPiece::Update()
{
}

void LaberynthPiece::Clean()
{
}

LaberynthPiece::LaberynthPiece(vec2d pos, vec2d size)
{
	m_pos	= pos;
	m_size	= size;
	m_vel	= { 0, 0 };
	int dice	= rand() % 10;
	m_cell = (PIECES) dice;// PosiblePieces[dice];
}
LaberynthPiece::LaberynthPiece(vec2d pos, vec2d size, PIECES piece)
{
	m_pos	= pos;
	m_size	= size;
	m_vel	= { 0, 0 };
	m_cell = (PIECES) piece;// PosiblePieces[dice];
}
char LaberynthPiece::GetCell(vec2i pos)
{
	if (static_cast<unsigned int>(pos.y * 3 + pos.x) < PosiblePieces[(int)m_cell].size()) {
		return  PosiblePieces[(int)m_cell][pos.y * 3 + pos.x];
	}
	return '\0';
}
