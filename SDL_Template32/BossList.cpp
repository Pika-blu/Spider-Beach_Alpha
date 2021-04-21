#include "BossList.h"
BossList::BossList()
{
}

BossList::BossList(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

BossList::~BossList()
{
}

void BossList::spawnBoss()
{
	cout << "spawnBoss()\n";
	//Go through all asteroids that are inside the vector. 
	for (auto boss = bossArray.begin(); boss != bossArray.end(); boss++)
	{
		//if the current asteroid is not active, we will initialize it and stop processing the rest of the function
		if (!boss->isActive)
		{
			boss->initialize();
			return;
		}
	}

	//execution will get here if no inactive asteroids are found. here we will add a new asteroid to the vector
	bossArray.emplace_back(Boss(renderer));
	/*std::cout << "        " << enemyArray.size() << std::endl;*/
}

void BossList::update()
{
	//Go through all asteroids that are inside the vector. 
	for (auto boss = bossArray.begin(); boss != bossArray.end(); boss++)
	{
		//if the current asteroid is active, we will move it
		if (boss->isActive)
		{
			boss->move();
		}
	}
}


void BossList::draw()
{
	/*std::cout << "        " << enemyArray.size() << std::endl;*/

	//Go through all asteroids that are inside the vector. 
	for (auto boss = bossArray.begin(); boss != bossArray.end(); boss++)
	{
		//if the current asteroid is active, we will draw it
		if (boss->isActive)
		{
			boss->draw(renderer);
		}
	}
}