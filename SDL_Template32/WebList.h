#pragma once
#include "Web.h"
#include <vector>


class WebList
{
	SDL_Renderer* renderer;


public:
	std::vector<Web> webArray;
	int webLimit = 4;
	WebList();
	WebList(SDL_Renderer* renderer);
	~WebList();

	void spawnWeb();
	void update();
	void draw();


};