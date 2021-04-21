#include "Enemy.h"

SDL_Rect Enemy::getRect()
{
	return dst;
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pEnemyTex, &src, &dst);
}

void Enemy::cleanup()
{
}

void Enemy::move()
{
	dst.x -= velX;
	if (dst.x <= 0)
	{
		initialize();
	}

}

void Enemy::initialize()
{
	isActive = true;

	int randomSize = 50 + rand() % 20;
	velY = 4 + rand() % 6;
	velX = 5 + rand() % 4;

	dst.x = 640 + randomSize;
	dst.y = 220 + rand() % 260 - randomSize;
	dst.w = randomSize;
	dst.h = randomSize;
	
}

Enemy::Enemy(SDL_Renderer* renderer)
{
	pEnemyTex = IMG_LoadTexture(renderer, "spider1.png");

	SDL_QueryTexture(pEnemyTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	initialize();
}

