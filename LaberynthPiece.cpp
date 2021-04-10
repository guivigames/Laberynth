#include "LaberynthPiece.h"

static std::string PosiblePieces[10] =
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
	double square = sqrt(m_cell.size());
	for (int i = 0; i < square; i++) {
		for (int j = 0; j < square; j++){
			rect.x = m_pos.x + (m_size.x / square * i);
			rect.y = m_pos.y + (m_size.y / square * j);
			rect.w = m_size.x / square;
			rect.h = m_size.y / square;
			if (m_cell[j * square + i] == '#')
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // the rect color (solid red)	
			else if (m_cell[j * square + i] == '.')
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
	m_cell	= PosiblePieces[dice];
}

char LaberynthPiece::GetCell(vec2i pos)
{
	if (pos.y * 3 + pos.x < m_cell.size()) {
		return m_cell[pos.y * 3 + pos.x];
	}
	return '\0';
}
