#include "TextureManager.h"

//global static pointer which will ensure a single instance of the class
TextureManager* TextureManager::s_pInstance = NULL;

TextureManager* TextureManager::Instance()
{
	if (s_pInstance == NULL)
	{
		s_pInstance = new TextureManager();
	}

	return s_pInstance;
}

void TextureManager::SetRenderer(SDL_Renderer* renderer)
{
	if (s_pInstance == NULL)
	{
		s_pInstance = new TextureManager();
	}

	s_pInstance->renderer = renderer;
}

void TextureManager::AddSmoke(int x, int y)
{
	s = Smoke(renderer, x, y);
}

void TextureManager::AddSpark(int x, int y)
{
	sp = Spark(renderer, x, y);
}
void TextureManager::AnimateSmoke()
{
	s.animate();
}

void TextureManager::AnimateSpark()
{
	sp.animate();
}

void TextureManager::AddExplosion(int x, int y)
{
	e = Explosion(renderer, x, y);
}

void TextureManager::AnimateExplosion()
{
	e.animate();
}

