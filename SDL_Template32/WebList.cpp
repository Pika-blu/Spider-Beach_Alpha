#include "WebList.h"

WebList::WebList()
{
}

WebList::WebList(SDL_Renderer* renderer)
{
	this->renderer = renderer;
}

WebList::~WebList()
{
}

void WebList::spawnWeb()
{
	//Go through all asteroids that are inside the vector. 
	for (auto web = webArray.begin(); web != webArray.end(); web++)
	{
		//if the current asteroid is not active, we will initialize it and stop processing the rest of the function
		if (!web->isActive)
		{
			if (webArray.size() < webLimit)
			{
				web->initialize();
				web->isActive = true;
			}
			
			return;
		}
	}

	//execution will get here if no inactive asteroids are found. here we will add a new asteroid to the vector
	webArray.emplace_back(Web(renderer));
	/*std::cout << "        " << enemyArray.size() << std::endl;*/
}

void WebList::update()
{
	//Go through all asteroids that are inside the vector. 
	for (auto web = webArray.begin(); web != webArray.end(); web++)
	{
		//if the current asteroid is active, we will move it
		if (web->isActive)
		{
			web->move();
		}
	}
}


void WebList::draw()
{
	/*std::cout << "        " << enemyArray.size() << std::endl;*/

	//Go through all asteroids that are inside the vector. 
	for (auto web = webArray.begin();web != webArray.end(); web++)
	{
		//if the current asteroid is active, we will draw it
		if (web->isActive)
		{
			web->draw(renderer);
		}
	}
}