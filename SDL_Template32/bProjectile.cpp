#include "bProjectile.h"

SDL_Rect bProjectile::getRect()
{
	return dst;
}

bProjectile::bProjectile()
{
}

bProjectile::bProjectile(SDL_Renderer* renderer, int x, int y)
{
	pSpriteTex = IMG_LoadTexture(renderer, "bullet.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;


	dst.x = x + offsetBulletX;
	dst.y = y + offSetBulletY;
	dst.w = 18;
	dst.h = 12;

}

bProjectile::~bProjectile()
{
}

void bProjectile::aim()
{

}

void bProjectile::update()
{
	
	dst.x -= velX;
	dst.y += velY;


}

void bProjectile::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);
}

void bProjectile::cleanup()
{
}

bool bProjectile::checkCollision(SDL_Rect r)
{
	return
		r.x < dst.x + dst.w &&
		r.x + r.w > dst.x &&
		r.y < dst.y + dst.h &&
		r.h + r.y > dst.y;
}
