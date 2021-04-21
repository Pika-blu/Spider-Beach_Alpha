#include "Hero.h"
#include <iostream>

//constructor
Hero::Hero()
{
}

//constructor


//constructor
Hero::Hero(SDL_Renderer* renderer)
{
	pSpriteTex = IMG_LoadTexture(renderer, "hero2.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;
	src.w = 35;
	src.h = 41;


	dst.x = 0;
	dst.y = 195;
	dst.w = 60;
	dst.h = 65;
}


//destructor
Hero::~Hero()
{
}


void Hero::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}

void Hero::setPosition(int x, int y)
{
	dst.x = x;
	dst.y = y;
}

void Hero::moveBy(int x, int y)
{
	dst.x += x * speedX;
	dst.y += y * speedY;

	if (dst.x < 0 || dst.x > 600)
	{
		speedX = 0.0f;

		if (dst.x < 0) dst.x += x + 1.5f;

		else if (dst.x > 600) dst.x += x - 1.5f;

	}
	else if (dst.x >= 0 || dst.x <= 600) speedX = 10.0f;


	if (dst.y < 190 || dst.y > 400)
	{
		speedY = 0.0f;

		if (dst.y < 190) dst.y += y + 3.0f;

		else if (dst.y > 400) dst.y += y - 3.0f;

	}
	else if (dst.y >= 0 || dst.y <= 400) speedY = 7.5f;
}

void Hero::draw(SDL_Renderer* renderer)
{
	if (velX == 1 && velY == 0)
	{
		pSpriteTex = IMG_LoadTexture(renderer, "hero_d.png");
	}
	else if (velX == -1 && velY == 0)
	{
		pSpriteTex = IMG_LoadTexture(renderer, "hero_a.png");
	}
	else if (velY == -1 && velX == 0)
	{
		pSpriteTex = IMG_LoadTexture(renderer, "hero_s.png");
	}
	else if (velY == 1 && velX == 0)
	{
		pSpriteTex = IMG_LoadTexture(renderer, "hero_w.png");
	}
	else if (velX == 0 && velY == 0)
	{
		pSpriteTex = IMG_LoadTexture(renderer, "hero2.png");
	}
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}


bool Hero::checkCollision(SDL_Rect r)
{
	return
		r.x < dst.x + dst.w &&
		r.x + r.w > dst.x &&
		r.y < dst.y + dst.h &&
		r.h + r.y > dst.y;
}