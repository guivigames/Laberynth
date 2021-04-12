#include "Player.h"
#include "SDLHelpFunctions.h"

Player::Player(vec2d pos, double radius)
{
    m_nRadius   = radius;
    m_pos       = pos;
}

Player::~Player()
{
}

void Player::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
    SDL_Fill_Circle(renderer, m_pos.x, m_pos.y, m_nRadius, 255, 0, 255, 255);    
}

void Player::Update()
{
}

void Player::Clean()
{
}
