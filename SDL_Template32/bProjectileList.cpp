#include "bProjectileList.h"

bProjectileList::bProjectileList() {}
bProjectileList::bProjectileList(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}
bProjectileList::~bProjectileList() {}

void bProjectileList::addBullet(int x, int y)
{
	//adds it to the tail end of the list

	bProjectileArray.emplace_back(bProjectile(renderer, x, y));
}

void bProjectileList::updateBullets()
{
	//for each bullet in the list
	
	for (auto bprojectile = bProjectileArray.begin(); bprojectile != bProjectileArray.end();) {
		//update the bullet (moves the bullet up)
		bprojectile->update();

		//if the bullet reached the top of the screen, erase it
		if (bprojectile->dst.y <= 0)
		{
			//erase returns us the next bullet in the list so we don't move our 
			//iterator to the next element in the list manually in this case
			bprojectile = bProjectileArray.erase(bprojectile);
		}
		else
		{
			//draw the bullet and move to next bullet in the list to check the next bullet
			bprojectile->draw(renderer);
			++bprojectile;
		}
	}
}
