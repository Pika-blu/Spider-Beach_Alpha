#include "Game.h"
#include <iostream>
Game::Game()
{
}

Game::~Game()
{
}

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	reset = true;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		//initialization successful

		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}


		//initialize the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);



		if (m_pWindow != 0)
		{
			//window creation successful

			//set up renderer
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

			if (m_pRenderer != 0)
			{
				//renderer creation successful
				SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 255, 255);
			}
			else
			{
				//renderer init failed
				return false;
			}
		}
		else
		{
			//SDL Init failed
			return false;
		}

		//init success! 
		//we are going to move on to the prepare function

		return true;
	}

	//init failed
	return false;
}

void Game::prepare()
{

	background = Background(m_pRenderer,  640, 296);
	ground = Parallax(m_pRenderer, 640, 213);
	hero = Hero(m_pRenderer);
	bosses = BossList(m_pRenderer);
	bullets = BulletList(m_pRenderer);
	projectiles = ProjectileList(m_pRenderer);
	bprojectile = bProjectileList(m_pRenderer);
	enemys = EnemyList(m_pRenderer);
	web = WebList(m_pRenderer);
	collisionManager = CollisionManager(&bullets, &enemys, &hero, &bosses, &web, &projectiles, &bprojectile);
	gg = GameOver(m_pRenderer, 500, 305);
	win = GameWin(m_pRenderer, 400, 340);
	digit = Counter(m_pRenderer, 0, 0);
	enemykilled = Counter(m_pRenderer,45,0);
	
	TextureManager::SetRenderer(m_pRenderer);
	SoundManager::Instance()->InitAll(); 
	SoundManager::Instance()->playMusic("bgmusic", -1);
	

	//set initial deltaTime, and current frame's start time
	deltaTime = 1.0f / targetFramerate;
	currentFrameStartTime = SDL_GetTicks();

	//we are ready to start our game loop
	m_bRunning = true;
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			m_bRunning = false;
		}
		else if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				hero.velY = -1;
				break;

			case SDLK_s:
				hero.velY = 1;
				break;

			case SDLK_a:
				hero.velX = -1;
				break;

			case SDLK_d:
				hero.velX = 1;
				break;

			case SDLK_SPACE:
				bullets.addBullet(hero.getWeaponX(), hero.getWeaponY());
				SoundManager::Instance()->playSound("fire", 0);
				break;

			case SDLK_ESCAPE:
				m_bRunning = false;
				reset = false;
				break;

			case SDLK_KP_PLUS:
				SoundManager::Instance()->IncreaseMusicVolume();
				break;

			case SDLK_KP_MINUS:
				SoundManager::Instance()->DecreaseMusicVolume();
				break;

			default:
				break;
			}

		}
		else if (event.type == SDL_KEYUP)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				hero.velY = 0;
				break;

			case SDLK_s:
				hero.velY = 0;
				break;

			case SDLK_a:
				hero.velX = 0;
				break;

			case SDLK_d:
				hero.velX = 0;
				break;

			default:
				break;
			}
		}
	}

}

void Game::update()
{
	
	ground.moveX();
	background.moveX();

	enemys.update();

	web.update();

	hero.moveBy(hero.velX, hero.velY);

	bosses.update();

	enemySpawner();

	bossSpawner();

	web.spawnWeb();

	projectileSpawner();
	
	bossProjectileSpawner();
	
	volumeControl();

}

void Game::render()
{
	m_bRunning = !collisionManager.checkCollisions();
	//clear the renderer to draw color
	SDL_RenderClear(m_pRenderer);

	//render the background
	ground.draw(m_pRenderer);
	background.draw(m_pRenderer);

	web.draw();
	enemys.draw();
	bosses.draw();

	//update the bullets
	bullets.updateBullets();
	projectiles.updateBullets();
	bprojectile.updateBullets();
	 
	hero.draw(m_pRenderer);
	enemykilled.draw(m_pRenderer, collisionManager.getCounter());
	digit.draw(m_pRenderer, collisionManager.getDigit());


	if (m_bRunning == false && collisionManager.getBossDead() == false)
	{
		gg.draw(m_pRenderer);
		Mix_FadeOutChannel(-1, 15);
		SoundManager::Instance()->playSound("gameover", 0);
		this_thread::sleep_for(0.50s);
		SoundManager::Instance()->playSound("gameovervoice", 0);
	}

	if (collisionManager.getBossDead() == true)
	{
		Mix_FadeOutChannel(-1, 10);
		SoundManager::Instance()->playSound("endingmusic", 0);
		win.draw(m_pRenderer);
		this_thread::sleep_for(1.25s);
		m_bRunning = false;
		reset = false;
	}
	
	TextureManager::Instance()->AnimateSmoke();
	TextureManager::Instance()->AnimateSpark();
	TextureManager::Instance()->AnimateExplosion();
	//draw everything to the screen
	SDL_RenderPresent(m_pRenderer);
}



void Game::waitForNextFrame()
{
	//In this function, we are going to ensure that our game waits until the time we allocated for each frame passes

	//Step 1: Get the current time (how much time elapsed in milliseconds since SDL was initialized
	Uint32 gameTimeMs = SDL_GetTicks();

	//Step 2: Calculate how much time has passed since the current frame started
	timeSinceLastFrame = gameTimeMs - currentFrameStartTime;

	//Step 3: If the frame started less than the total allocated time for the frame
	if (timeSinceLastFrame < frameDelayMs)
	{
		//Step 4: Halt the execution until the allocated time for the frame passes
		SDL_Delay(frameDelayMs - timeSinceLastFrame);
	}

	//Step 5: Store the time when this frame ends
	currentFrameEndTime = SDL_GetTicks();

	//Step 6: Calculate deltaTime (how much time it took for the frame to be completed)
	deltaTime = (currentFrameEndTime - currentFrameStartTime) / 1000.f;

	//Step 7: Set current game time (in seconds)
	gameTime = currentFrameEndTime / 1000.0f;

	//Step 8: Set the start time of the current frame to be the end time, so that the next time this function runs, 
	//		  we take the current end time as the new frame's start time
	currentFrameStartTime = currentFrameEndTime;

	//for testing:
	//std::cout << gameTime << " - " << deltaTime << std::endl;
}

void Game::gameReset()
{
	collisionManager.setCounter(0);
	enemySpawnTimer = 0;
	bossSpawnTimer = 0;
	bossPhase = false;
	this_thread::sleep_for(3.0s);

	

	
}

void Game::cleanup()
{
	//cleaning game

	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}


//Below are all spawn timers and not game functions

void Game::enemySpawner()
{
	enemySpawnTimer += deltaTime;
	if (enemySpawnTimer >=enemySpawnInterval && bossPhase == false)
	{
		enemys.spawnEnemy();
		enemySpawnTimer = 0;
	}
}

void Game::bossSpawner()
{
	
	bossSpawnTimer += deltaTime;
	if (bossSpawnTimer >= bossSpawnInterval && bossPhase == false)
	{
		bosses.spawnBoss();
		bossPhase = true;
		Mix_FadeOutChannel(-1, 15);
		SoundManager::Instance()->playSound("bossmusic", 0);
	}
}

void Game::projectileSpawner()
{
	projectileSpawnTimer += deltaTime;
	if (projectileSpawnTimer >= projectileSpawnInterval)
	{
		for (auto enemy = enemys.enemyArray.begin(); enemy != enemys.enemyArray.end(); ++enemy)
		{
			SoundManager::Instance()->playSound("spidershoot", 0);
			projectiles.addBullet(enemy->getX(), enemy->getY());
		}
		projectileSpawnTimer = 0;

	}
}


int Game::volumeControl()
{

	if (volume == 1)
	{
		volume = 6;
	}
	if (volume == 2)
	{
		Mix_Volume(-1, 24);
	}
	if (volume == 3)
	{
		Mix_Volume(-1, 46);
	}
	if (volume == 4)
	{
		Mix_Volume(-1, 72);
	}
	if (volume == 5)
	{
		Mix_Volume(-1, 100);
	}
	if (volume == 6)
	{
		Mix_Volume(-1, 128);
	}
	return volume;
}

void Game::bossProjectileSpawner()
{
	bossProjectileSpawnTimer += deltaTime;
	if(bossProjectileSpawnTimer  >= bossProjectileSpawnInterval)
	{
		for (auto boss = bosses.bossArray.begin(); boss != bosses.bossArray.end(); ++boss)
		{
			bprojectile.addBullet(boss->getX(), boss->getY());
			SoundManager::Instance()->playSound("bossshoot", 0);
		}
		bossProjectileSpawnTimer = 0;

	}
}

