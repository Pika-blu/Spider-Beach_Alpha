#pragma once
#include <SDL_image.h>

class Explosion
{
	SDL_Texture* pSpriteTex = nullptr;

	SDL_Rect src;
	SDL_Rect dst;

	SDL_Renderer* renderer;

	//Animation related variables

	//Which frame we are displaying
	int displayFrame = 0;

	//How many frames there are
	int frameCount = 64;

	//Number of Columns and Rows
	int numColumns = 8;
	int numRows = 8;


	/*
	Total size of the image: 1024x1024
	Each frame size: 128x128
		Width: Total Width / Column Count; 1024/8 = 128 pixels
		Height: Total Height / Row Count; 1024/8 = 128 pixels
	*/


	int frameWidth = 128;
	int frameHeight = 128;

	int targetWidth = 400;
	int targetHeight = 400;


public:
	Explosion() { };
	Explosion(SDL_Renderer* renderer, int posX, int posY);


	~Explosion() {};

	bool animate();
	void cleanup();
};