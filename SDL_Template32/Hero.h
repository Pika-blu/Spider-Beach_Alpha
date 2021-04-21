#pragma once
#include <SDL_image.h>
#include <math.h>

// Sprite class which contains a texture, position, velocity, size, and functions for drawing it.

class Hero
{
	SDL_Texture* pSpriteTex = nullptr;
	SDL_Rect src;

public:
	SDL_Rect dst;

	// velocity (maybe not necessary for every sprite)
	float velX = 0;
	float velY = 0;

	// constructors -- these are used when initializing an object
	Hero();
	Hero(SDL_Renderer* renderer);
		

	// destructor -- used when the object is to be removed from memory
	~Hero();

	void setPosition(int x, int y);
	void moveBy(int x, int y);
	void draw(SDL_Renderer* renderer);

	bool checkCollision(SDL_Rect r);

	void cleanup();

	int getWeaponX() { return dst.x + dst.w / 2; }
	int getWeaponY() { return dst.y; };
	int getX() { return dst.x; }
	int getY() {return dst.y;}

	float speedX = 15.0f;
	float speedY = 10.0f;
};