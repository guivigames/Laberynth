#ifndef __GAME__
#define __GAME__

#ifdef WIN32
#include <SDL.h>
#pragma comment (lib, "SDL2.lib")
#pragma comment (lib, "SDL2main.lib")
#pragma comment (lib, "SDL2test.lib")
#else
#include <SDL2/SDL.h>
#endif
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include "GameMap.h"
#include "Player.h"

#define _DEBUG  ///< Defined for some debuging messages.

struct rect {
    rect(vec2i pos, vec2i pieces, int piecesize) { m_pos = pos; m_pieces = pieces; m_piecesize = piecesize; m_size = m_pieces * m_piecesize; };
    vec2i m_pos;
    vec2i m_pieces;
    int m_piecesize;
    vec2i m_size;
};


class Game 
{
private:
    static Game* s_pInstance;
    Game();
    SDL_Renderer    *m_pRenderer;   ///< Pointer to the SDL Renderer.
	SDL_Window      *m_pWindow;     ///< Pointer to the SDL Window.
    bool    m_bGameOver;        ///< Indicate if the game is still running.
    int     m_nWidth;           ///< Width of the main window.
    int     m_nHeight;          ///< Height of hte main window.    
    std::string m_strTitle;     /// Game title.
    rect    m_board;        /// Board size.

    //Uint8* m_keystate;
    /**
    *   vector with all the objects in the game.
    * First Object is map.
    * Second is player.
    */
    //GameMap *m_map;
    std::vector<BaseObject*> m_objects;
#ifdef _DEBUG
    std::chrono::time_point<std::chrono::steady_clock> m_stdChrono;
    double m_nFPS;
#endif

public:
    ~Game();
    static Game* Instance();
    void Init(std::string title = "The Game", int width = 600, int height = 400, rect board = rect(vec2i(100, 100), vec2i(7, 7), 60));
    void HandleEvents();
    void Update();
    void Draw();
    bool IsGameOver();
};
typedef Game TheGame;
#endif