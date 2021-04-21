#include "GameOver.h"
#include <iostream>


//constructor
GameOver::GameOver()
{
}

//constructor
GameOver::GameOver(SDL_Renderer* renderer, int w, int h)
{
	pSpriteTex = IMG_LoadTexture(renderer, "game_over.png");

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
GameOver::~GameOver()
{
}


void GameOver::cleanup()
{

	
	SDL_DestroyTexture(pSpriteTex);
}

void GameOver::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}