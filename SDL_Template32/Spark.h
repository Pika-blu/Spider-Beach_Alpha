#pragma once
#include <SDL_image.h>


class Spark
{
	SDL_Texture* pSpriteTex = nullptr;

	SDL_Rect src;
	SDL_Rect dst;

	SDL_Renderer* renderer;

	//Animation related variables

	//Which frame we are displaying
	int displayFrame = 0;

	//How mnay frames there are
	int frameCount = 16;


	/*
	Total size of the image: 768x32
	Each frame size: 32x32
		Width: Total Width / Frame Count; 768/24 = 32 pixels
		Height: 32 pixels because there's only a single row
	*/
	int frameWidth = 181;
	int frameHeight = 206;
	int targetWidth = 60;
	int targetHeight = 60;





public:
	Spark() { };
	Spark(SDL_Renderer* renderer, int posX, int posY);


	~Spark() {};

	bool animate();
	void cleanup();
};