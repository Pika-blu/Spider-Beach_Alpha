#include "Web.h"

SDL_Rect Web::getRect()
{
	return dst;
}

Web::Web()
{
}

Web::~Web()
{
}

void Web::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pWebTex, &src, &dst);

}

void Web::cleanup()
{
}

void Web::move()
{
	dst.x -= velX;
	if (dst.x <= 0)
	{
		initialize();
	}

}

void Web::initialize()
{
	int randomSpawn = 1 + rand() % 7;

	velY = 4 + rand() % 6;
	velX = 2;

	dst.x = 640 + 50;
	if (randomSpawn == 1) { dst.y = 530; }
	if (randomSpawn == 2) { dst.y = 490; }
	if (randomSpawn == 3) { dst.y = 450; }
	if (randomSpawn == 4) { dst.y = 310; }
	if (randomSpawn == 5) { dst.y = 270; }
	if (randomSpawn == 6) { dst.y = 230; }
	if (randomSpawn == 7) { dst.y = 190; }
	if (randomSpawn == 8) { dst.y = 150; }

	dst.w = 40;
	dst.h = 40;
}

Web::Web(SDL_Renderer* renderer)
{
	pWebTex = IMG_LoadTexture(renderer, "web.png");

	SDL_QueryTexture(pWebTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	initialize();
}