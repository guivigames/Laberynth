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
    std::string m_strTitle;     ///< Game title.

    GameMap *m_map;
#ifdef _DEBUG
    std::chrono::time_point<std::chrono::steady_clock> m_stdChrono;
    double m_nFPS;
#endif

public:
    ~Game();
    static Game* Instance();
    void Init(std::string title = "The Game", int width = 600, int height = 400);
    void HandleEvents();
    void Update();
    void Draw();
    bool IsGameOver();
};
typedef Game TheGame;
#endif