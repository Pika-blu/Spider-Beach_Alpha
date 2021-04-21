#include "Explosion.h"


Explosion::Explosion(SDL_Renderer* renderer, int dstX, int dstY)
{
	this->renderer = renderer;


	pSpriteTex = IMG_LoadTexture(renderer, "explosion_small.png");

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

bool Explosion::animate()
{

	//Row number: floor(displayFrame / numRows)
	//Column number: floor(displayFrame % numColumns)

	src.x = (displayFrame % numColumns) * frameWidth;
	src.y = (displayFrame / numRows) * frameHeight;

	SDL_RenderCopy(renderer, pSpriteTex, &src, &dst);

	//increment by 2 to speed up the animation
	displayFrame += 1;
	if (displayFrame == frameCount)
	{
		cleanup();
		return false;
	}

	return true;
}

void Explosion::cleanup()
{
	SDL_DestroyTexture(pSpriteTex);
}
