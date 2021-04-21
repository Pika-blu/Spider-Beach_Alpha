#pragma once
#include <SDL_image.h>
#include <math.h>
#include <iostream>
#include <time.h>
// Sprite class which contains a texture, position, velocity, size, and functions for drawing it.

class bProjectile
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	SDL_Rect getRect();
	// velocity (maybe not necessary for every sprite)
	float velY = 1.5;
	float velX = 12;
	float offSetBulletY = 90.0;
	float offsetBulletX = 60.0;

	// constructors -- these are used when initializing an object
	bProjectile();
	bProjectile(SDL_Renderer* renderer, int x, int y);

	// destructor -- used when the object is to be removed from memory
	~bProjectile();

	void aim();
	void update();
	void draw(SDL_Renderer* renderer);

	void cleanup();

	bool checkCollision(SDL_Rect r);
};
