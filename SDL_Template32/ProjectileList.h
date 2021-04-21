#pragma once
#include "Projectile.h"
#include <vector>

class ProjectileList {
	SDL_Renderer* renderer;

public:

	ProjectileList();
	ProjectileList(SDL_Renderer* renderer);
	~ProjectileList();

	void addBullet(int x, int y);
	void updateBullets();

	std::vector<Projectile> projectileArray;

};