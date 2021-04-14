/*
compile in linux: g++ -std=c++17 game.cpp main.cpp -o game `pkg-config --cflags --libs sdl2`
*/
#include "game.h"
#include "GameMath.h"
int main(int argc, char *argv[])
{
    TheGame::Instance()->Init("Laberynth", 800, 600);
    while (TheGame::Instance()->IsGameOver())
    {
        TheGame::Instance()->HandleEvents();
        TheGame::Instance()->Update();
        TheGame::Instance()->Draw();
    }
    return 0;
}
