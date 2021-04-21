#include "Boss.h"



SDL_Rect Boss::getRect()
{
	return dst;	
}


Boss::Boss()
{
}

Boss::~Boss()
{
}

void Boss::draw(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, pBossTex, &src, &dst);
}

void Boss::cleanup()
{
}

void Boss::move()
{
		if (dst.x > 400)
		{
			dst.x -= velX;
		}
		else if (dst.x <= 400)
		{
			velX = 0;
			
		}
	

	if (dst.x <= 400)
	{

		if (dst.y > 410)
		{
			velY = -4;
		}

		if (dst.y < 100)
		{
			velY = 4;
		}
	}
	
	dst.y += velY;
}

void Boss::initialize()
{
	isActive = true;
	cout << "initalize\n";
	
	
	velX = 4;
	velY = -2;


	dst.x = 640 + 200;
	dst.y = 480;
	dst.w = 200;
	dst.h = 200;

}

Boss::Boss(SDL_Renderer* renderer)
{
	pBossTex = IMG_LoadTexture(renderer, "Valrogio2.png");

	SDL_QueryTexture(pBossTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;

	initialize();
}


//void Boss::moveBy(int x, int y)
//{
//	dst.x += x * speedX;
//	dst.y += y * speedY;
//
//	if (dst.y <= 0)
//	{
//		speedY = 2.0;
//		velY = 5;
//	}
//
//
//	if (dst.y >= 420)
//	{
//		speedY = 2.0;
//		velY = -5;
//	}
//
//	if (dst.x <= 0)
//	{
//		speedX = 1.5;
//		velX = 5;
//	}
//	if (dst.x == 250)
//	{
//		speedX = 1;
//		velX = 5;
//	}
//	if (dst.x >= 480)
//	{
//		speedX = 1;
//		velX = -5;
//	}
//
//}

