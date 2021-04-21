#pragma once
#include "bProjectile.h"
#include <vector>

class bProjectileList {
	SDL_Renderer* renderer;

public:

	bProjectileList();
	bProjectileList(SDL_Renderer* renderer);
	~bProjectileList();

	void addBullet(int x, int y);
	void updateBullets();

	std::vector<bProjectile> bProjectileArray;

};