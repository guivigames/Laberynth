#include "game.h"
//The singleton.
Game* Game::s_pInstance = nullptr;
// Default Constructor.
Game::Game()
    : m_pRenderer(nullptr)
    , m_pWindow(nullptr)
    , m_bGameOver(false)
    , m_nWidth(600)
    , m_nHeight(400)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(1);
    }
    m_bGameOver = true;
#ifdef _DEBUG
    m_stdChrono = std::chrono::steady_clock::now();
    m_nFPS = 0.0;
#endif   
}
// Default Destructor.
Game::~Game()
{
    SDL_Quit();
}
// Return instsance of the game.
Game* Game::Instance()
{
    if (s_pInstance == nullptr){
        s_pInstance = new Game();
    }
    return s_pInstance;
}
// Initialize the game engien
void Game::Init(std::string title, int width, int height)
{
    /* initialize random seed: */
    srand(time(NULL));
    m_nWidth    = width;
    m_nHeight   = height;
    m_strTitle  = title;
    m_pWindow   = SDL_CreateWindow( m_strTitle.c_str(),
                                    SDL_WINDOWPOS_UNDEFINED,
                                    SDL_WINDOWPOS_UNDEFINED,
                                    m_nWidth,
                                    m_nHeight,
                                    0);
    if (m_pWindow == nullptr)
    {
        SDL_Log("Unable to create window SDL: %s", SDL_GetError());
        exit(1);
    }
    m_pRenderer = SDL_CreateRenderer( m_pWindow, -1, SDL_RENDERER_ACCELERATED);
    if (m_pRenderer == nullptr)
    {
        SDL_Log("Unable to create renderer SDL: %s", SDL_GetError());
        exit(1);
    }
    m_map = new GameMap(vec2d{ 100.0, 100.0}, vec2d{ (double) 30.0, (double) 30.0}, vec2d{ 7, 7});
}
// Handle Input Events
void Game::HandleEvents()
{
    SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;
            case SDL_MOUSEBUTTONDOWN:
                {
                    char cell;
                    cell = m_map->GetCell(vec2d{ (double)event.button.x, (double)event.button.y});
                    printf("Cell is: %c\n", cell);
                }
                break;
			default:
				break;
		}
    }
} 
// Update the game
void Game::Update()
{

#ifdef _DEBUG   
    ///< Updating the window title to display the lapsed time since last update.
    auto now = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_time = (now - m_stdChrono);
    m_nFPS = elapsed_time.count();
    std::string elapsed = std::to_string( m_nFPS);
    std::string newtitle = m_strTitle + " " + elapsed + " sec";
    SDL_SetWindowTitle(m_pWindow, newtitle.c_str());
    m_stdChrono = now;
    /**
        Line below could be uncommented to havea ~constant framerate but never a 
        good idea to use a delay. Better would be to use m_nFPS to adjust movements
    */
    //SDL_Delay((1000.0/60.0)-m_nFPS);      
#endif
}
// Redraw the game state.
void Game::Draw()
{
    SDL_SetRenderDrawColor(m_pRenderer, 96, 128, 255, 255);
	SDL_RenderClear(m_pRenderer);

    m_map->Draw(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}
// Check if the game is over.
bool Game::IsGameOver()
{
    return m_bGameOver;
}
