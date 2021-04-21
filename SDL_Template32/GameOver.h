#pragma once
#include <SDL_image.h>
class GameOver
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	// constructors -- these are used when initializing an object
	GameOver();
	GameOver(SDL_Renderer* renderer, int w, int h);

	// destructor -- used when the object is to be removed from memory
	~GameOver();

	void draw(SDL_Renderer* renderer);
	void cleanup();

};