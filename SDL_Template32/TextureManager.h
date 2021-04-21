#pragma once
#include "Smoke.h"
#include "Spark.h"
#include "Explosion.h"


#include "SDL.h"

class TextureManager
{
private:
	TextureManager() {}; //default constructor, it is private so TextureManager cannot be instantiated from outside of the class
	static TextureManager* s_pInstance; //we store a private pointer to the instance

	TextureManager(TextureManager const&) {};				// copy constructor is private
	TextureManager& operator=(TextureManager const&) {};	// assignment operator is private

	SDL_Renderer* renderer;

	Explosion e;
	Smoke s;
	Spark sp;


public:

	static TextureManager* Instance();
	static void SetRenderer(SDL_Renderer* renderer);
	void AddSmoke(int x, int y);
	void AddSpark(int x, int y);
	void AddExplosion(int x, int y);
	void AnimateExplosion();
	void AnimateSmoke();
	void AnimateSpark();
	

};