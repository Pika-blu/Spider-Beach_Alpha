#pragma once
#include "BulletList.h"
#include "EnemyList.h"
#include "Hero.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "BossList.h"
#include "WebList.h"
#include "ProjectileList.h"
#include "bProjectileList.h"

class CollisionManager
{
	BulletList* m_pBulletList;
	EnemyList* m_pEnemyList;
	Hero* m_pHero;
	BossList* m_pBoss;
	WebList* m_pWebList;
	ProjectileList* m_pProjectile;
	bProjectileList* m_pBossProj;
	void checkBulletToWebCollisions();
	void checkBulletToEnemyCollisions();
	void checkBulletToBossCollisions();
	bool checkHeroToEnemyCollisions();
	
	int counter = 0;
	int digit = 0;
	int heroHp = 0;
	int bossHP = 0;
	bool bossDead = false;
	

public:

	bool getBossDead() {return bossDead;}
	int getCounter() { return counter; }
	int getDigit() { return digit; }
	void setCounter(int c) { counter = c; }
	CollisionManager();
	~CollisionManager();
	CollisionManager(BulletList* bulletList, EnemyList* enemyList, Hero* hero, BossList* boss, WebList* web ,ProjectileList* projectile, bProjectileList* bprojectile);

	bool checkCollisions();

};


