#include "GameWin.h"
#include <iostream>


//constructor
GameWin::GameWin()
{
}

//constructor
GameWin::GameWin(SDL_Renderer* renderer, int w, int h)
{
	pSpriteTex = IMG_LoadTexture(renderer, "you win.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.h = h; 
	src.y = 0;
	src.w = w;

	dst.x = 70;
	dst.y = 88;
	dst.w = w;
	dst.h = h;
}


//destructor
GameWin::~GameWin()
{
}


void GameWin::cleanup()
{


	SDL_DestroyTexture(pSpriteTex);
}

void GameWin::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}