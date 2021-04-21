#pragma once
#include <SDL_image.h>
#include <iostream>

class Web
{
	SDL_Texture* pWebTex = nullptr;
	SDL_Rect src;
	SDL_Rect dst;

	int velY = 0;
	int velX = 0;
public:

	bool isActive = false;

	SDL_Rect getRect();
	// constructors -- these are used when initializing an object
	Web();
	Web(SDL_Renderer* renderer);

	// destructor -- used when the object is to be removed from memory
	~Web();

	void draw(SDL_Renderer* renderer);

	void cleanup();

	void move();
	void initialize();
	int getX() { return dst.x; }
	int getY() { return dst.y; }

};