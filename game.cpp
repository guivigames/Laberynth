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
    , m_board( rect (vec2i(100, 100), vec2i(7, 7), 60))
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
void Game::Init(std::string title, int width, int height, rect board)
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
    m_board = board;
    //m_map = new GameMap(vec2d{ 100.0, 100.0 }, vec2d{ (double)30.0, (double)30.0 }, vec2d{ 7, 7 });
    double Onecell;
    Onecell = m_board.m_piecesize / 3;
    m_objects.push_back( new GameMap( m_board.m_pos, vec2d{ (double)m_board.m_piecesize, (double)m_board.m_piecesize }, m_board.m_pieces));
    m_objects.push_back(new Player(m_board.m_pos + (Onecell + Onecell / 2)/*vec2d{ 100.0 + (Onecell + Onecell/2), 100.0 + (Onecell + Onecell/2) }*/, (Onecell / 2) - 2));
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
                    //char cell;
                    //cell = ((GameMap*)m_objects[0])->GetCell(vec2d{ (double)event.button.x, (double)event.button.y});
                    //cell = m_map->GetCell(vec2d{ (double)event.button.x, (double)event.button.y });
                    //printf("Cell is: %c\n", cell);
                }
                break;
            //case SDL_KEYDOWN:
            //    printf("%d\n", event.key.keysym.sym);
            //    break;
            //case SDL_KEYUP:
            //    break;
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
    const Uint8* m_keystate = SDL_GetKeyboardState(0);
    if (m_keystate != NULL) {
        
        /// Movement Calculation
        vec2d vel{ 0.0, 0.0 };
        vec2d pos = m_objects[1]->getPos();
        if (m_keystate[SDL_SCANCODE_W]) vel += { 0.0f, -1.0f};
        if (m_keystate[SDL_SCANCODE_S]) vel += { 0.0f, 1.0f};
        if (m_keystate[SDL_SCANCODE_A]) vel += {-1.0f, 0.0f};
        if (m_keystate[SDL_SCANCODE_D]) vel += { 1.0f, 0.0f};
        vel = vel.norm() * 100;
        vec2d vPotentaialPosition = pos + vel * m_nFPS;

        /// Collition Detection
        /*vec2d vCurrentCell = pos.floor();
        vec2d vTargetCell = vPotentaialPosition;
        vec2d vAreaTL = (vCurrentCell.min(vTargetCell) - vec2d(1, 1)).max({ 0, 0 });
        vec2d vAreaBR = (vCurrentCell.max(vTargetCell) + vec2d(1, 1)).min(vWorldSize);

        vec2d vCell;
        for (vCell.y = vAreaTL.y; vCell.y <= vAreaBR.y; vCell.y++)
        {
            for (vCell.x = vAreaTL.x; vCell.x <= vAreaBR.x; vCell.x++)
            {
                if (sWorldMap[vCell.y * vWorldSize.x + vCell.x] == '#')
                {
                    olc::vf2d vNearestPoint;
                    vNearestPoint.x = std::max(float(vCell.x), std::min(vPotentaialPosition.x, float(vCell.x + 1)));
                    vNearestPoint.y = std::max(float(vCell.y), std::min(vPotentaialPosition.y, float(vCell.y + 1)));
                    olc::vf2d vRayToNeares = vNearestPoint - vPotentaialPosition;
                    float fOvelap = object.fRadius - vRayToNeares.mag();
                    if (std::isnan(fOvelap)) fOvelap = 0;
                    if (fOvelap > 0)
                    {
                        vPotentaialPosition = vPotentaialPosition - vRayToNeares.norm() * fOvelap;
                    }
                }
            }
        }*/


        /// Update Position
        m_objects[1]->setPos(vPotentaialPosition);
    }
}
// Redraw the game state.
void Game::Draw()
{
    SDL_SetRenderDrawColor(m_pRenderer, 96, 128, 255, 255);
	SDL_RenderClear(m_pRenderer);
    //m_map->Draw(m_pRenderer);
    
    for (auto object: m_objects)
        object->Draw(m_pRenderer);

    SDL_RenderPresent(m_pRenderer);
}
// Check if the game is over.
bool Game::IsGameOver()
{
    return m_bGameOver;
}
