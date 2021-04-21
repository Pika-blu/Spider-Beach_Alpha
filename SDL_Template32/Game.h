#ifndef __GAME__
#define __GAME__

#include "SDL.h"
#include "Sprite.h"
#include "Hero.h"
#include "BulletList.h"
#include "EnemyList.h"
#include "Smoke.h"
#include "Spark.h"
#include "CollisionManager.h"
#include "TextureManager.h"
#include "Background.h"
#include "Projectile.h"
#include "ProjectileList.h"
#include "bProjectile.h"
#include "bProjectileList.h"
#include "Boss.h"
#include "BossList.h"
#include "SoundManager.h"
#include "Explosion.h"
#include "WebList.h"
#include "GameOver.h"
#include "GameWin.h"
#include "Parallax.h"
#include "Counter.h"
#include <time.h>
#include <thread>

class Game
{

public:

	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	//we do one time preparation stuff here
	void prepare();

	//these four functions make our game loop
	void handleEvents();
	void update();
	void render();
	void waitForNextFrame();
	void gameReset();
	//another single call function which runs just before the game is closed
	void cleanup();

	//function to aaccess the running variable
	bool running() { return m_bRunning; }
	bool getReset() { return reset; }

	


private:

	Hero hero;
	BossList bosses;
	bProjectileList bprojectile;
	BulletList bullets;
	ProjectileList projectiles;
	WebList web;
	Smoke smoke;
	Spark spark;
	Explosion boom;
	bool animateSmoke = true;
	EnemyList enemys;
	Background background;
	Parallax ground;
	CollisionManager collisionManager;
	GameOver gg;
	GameWin win;
	Counter enemykilled;
	Counter digit;






	/* 
	A pointer points to an object and is denoted by a "*" in declaration. 
	So m_pWindow is a Pointer which *points* to an object of type SDL_Window
	*/
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	
	bool m_bRunning;
	bool reset;

	//For framerate
	int targetFramerate = 30;
	int frameDelayMs = 1000 / targetFramerate;

	Uint32 currentFrameEndTime;
	Uint32 currentFrameStartTime;
	Uint32 timeSinceLastFrame;

	//for gameplay
	float deltaTime;

	//Keep gameTime in seconds
	float gameTime = 0;

	float enemySpawnTimer = 0;
	float enemySpawnInterval = 1.5;
	void enemySpawner();

	float projectileSpawnTimer = 0;
	float projectileSpawnInterval =2.0; 
	void projectileSpawner();

	float bossProjectileSpawnTimer = 0;
	float bossProjectileSpawnInterval = 0.7;
	void bossProjectileSpawner();

	float bossSpawnTimer = 0;
	float bossSpawnInterval = 59.5;
	bool bossPhase = false;
	void bossSpawner();

	int volume = 6;
	int volumeControl();
};


#endif /* defined (__Game__) */

