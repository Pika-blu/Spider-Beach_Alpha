#pragma once
#include <SDL_image.h>
#include <math.h>

// Sprite class which contains a texture, position, velocity, size, and functions for drawing it.

class Projectile
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	SDL_Rect getRect();
	// velocity (maybe not necessary for every sprite)
	float velY = 10;
	float velX = 12;
	float offSetBullet = 25.0;

	// constructors -- these are used when initializing an object
	Projectile();
	Projectile(SDL_Renderer* renderer, int x, int y);

	// destructor -- used when the object is to be removed from memory
	~Projectile();

	void update();
	void draw(SDL_Renderer* renderer);

	void cleanup();

	bool checkCollision(SDL_Rect r);
};
