#pragma once
#include "Boss.h"
#include <vector>

class BossList
{
 SDL_Renderer* renderer;


public:
		std::vector<Boss> bossArray;
		int bossLimit = 1;
		BossList();
		BossList(SDL_Renderer* renderer);
		~BossList();

		void spawnBoss();
		void update();
		void draw();


	
};


