#pragma once
#include <SDL_image.h>
#include <math.h>
#include <iostream>
using namespace std;
class Boss
{
	SDL_Texture* pBossTex = nullptr;
	SDL_Rect src;
	SDL_Rect dst;

	int velY = 0;
	int velX = 0;
	bool pos = false;
public:

	bool isActive = false;

	SDL_Rect getRect();

	// constructors -- these are used when initializing an object
	Boss();
	Boss(SDL_Renderer* renderer);

	// destructor -- used when the object is to be removed from memory
	~Boss();

	void draw(SDL_Renderer* renderer);

	void cleanup();

	void move();
	void initialize();
	int getX() { return dst.x; }
	int getY() { return dst.y; }

};