#pragma once
#include <SDL_image.h>
class GameWin
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	// constructors -- these are used when initializing an object
	GameWin();
	GameWin(SDL_Renderer* renderer, int w, int h);

	// destructor -- used when the object is to be removed from memory
	~GameWin();

	void draw(SDL_Renderer* renderer);
	void cleanup();

};