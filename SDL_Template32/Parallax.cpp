#include "Parallax.h"
#include <iostream>


//constructor
Parallax::Parallax()
{
}

//constructor
Parallax::Parallax(SDL_Renderer* renderer, int w, int h)
{
	pSpriteTex = IMG_LoadTexture(renderer, "sky.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.h = h;
	src.y = 0;
	src.w = w;

	dst.x = 0;
	dst.y = 0;
	dst.w = w;
	dst.h = h;
}


//destructor
Parallax::~Parallax()
{
}


void Parallax::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

void Parallax::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}

void Parallax::moveX()
{

	/*std::cout << src.x << "\n";*/
	src.x += 1;
	if (src.x == 512)
	{
		src.x = 0;
	}

}