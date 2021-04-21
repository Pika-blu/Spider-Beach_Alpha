#include "Spark.h"



Spark::Spark(SDL_Renderer* renderer, int dstX, int dstY)
{
	this->renderer = renderer;


	pSpriteTex = IMG_LoadTexture(renderer, "spark.png");

	SDL_QueryTexture(pSpriteTex, NULL, NULL, &src.w, &src.h);

	src.x = 0;
	src.y = 0;
	src.w = frameWidth;
	src.h = frameHeight;


	dst.x = dstX - targetWidth / 2;
	dst.y = dstY - targetHeight / 2;
	dst.w = targetWidth;
	dst.h = targetHeight;
}

bool Spark::animate()
{
	src.x = displayFrame * frameWidth;
	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);

	displayFrame++;
	if (displayFrame == frameCount)
	{
		cleanup();
		return false;
	}

	return true;
}

void Spark::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}