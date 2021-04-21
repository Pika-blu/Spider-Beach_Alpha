#include "CollisionManager.h"

void CollisionManager::checkBulletToEnemyCollisions()
{
	for (auto bullet = m_pBulletList->bulletArray.begin(); bullet != m_pBulletList->bulletArray.end(); )
	{
		bool moveToNext = true;
		
		for (auto enemy = m_pEnemyList->enemyArray.begin(); enemy != m_pEnemyList->enemyArray.end(); ++enemy)
		{
			
			if (enemy->isActive && bullet->checkCollision(enemy->getRect()))
			{
				counter++;
				if (counter > 9)
				{
					digit += 1;
				    counter = 0;
				}
				SoundManager::Instance()->playSound("splat", 0);
				TextureManager::Instance()->AddSmoke(bullet->dst.x, bullet->dst.y);
				enemy->isActive = false;
				bullet = m_pBulletList->bulletArray.erase(bullet);
				enemy = m_pEnemyList->enemyArray.erase(enemy);
				moveToNext = false;
				
				break;
			}
		}
		if (moveToNext)
		{
			++bullet;
		}

	}
}

bool CollisionManager::checkHeroToEnemyCollisions()
{

	for (auto enemy = m_pEnemyList->enemyArray.begin(); enemy != m_pEnemyList->enemyArray.end(); ++enemy)
	{

		if (enemy->isActive && m_pHero->checkCollision(enemy->getRect()))
		{
				
				return true; //switched to false for play testing     
		}
	}

	for (auto web = m_pWebList->webArray.begin(); web != m_pWebList->webArray.end(); ++web)
	{

		if (web->isActive && m_pHero->checkCollision(web->getRect()))
		{
			
				return true; //switched to false for play testing     
			
		}
	}

	for (auto boss = m_pBoss->bossArray.begin(); boss != m_pBoss->bossArray.end(); ++boss)
	{

		if (boss->isActive && m_pHero->checkCollision(boss->getRect()))
		{
			
				return true; //switched to false for play testing     
		}
	}

	for (auto proj = m_pProjectile->projectileArray.begin(); proj != m_pProjectile->projectileArray.end(); ++proj)
	{

		if (m_pHero->checkCollision(proj->getRect()))
		{
			
			return true; //switched to false for play testing     
		}
	}

	for (auto bproj = m_pBossProj->bProjectileArray.begin(); bproj != m_pBossProj->bProjectileArray.end(); ++bproj)
	{

		if (m_pHero->checkCollision(bproj->getRect()))
		{
			return true; //switched to false for play testing
		}
	}
	


	//if the code execution came here, this means that there 
	// were no collisions detected between the ship and any asteroid
	return false;
}

void CollisionManager::checkBulletToWebCollisions()
{
	for (auto bullet = m_pBulletList->bulletArray.begin(); bullet != m_pBulletList->bulletArray.end(); )
	{
		bool moveToNext = true;

		for (auto web = m_pWebList->webArray.begin(); web != m_pWebList->webArray.end(); ++web)
		{
			if (web->isActive && bullet->checkCollision(web->getRect()))
			{
				SoundManager::Instance()->playSound("web", 0);
				bullet = m_pBulletList->bulletArray.erase(bullet);
				moveToNext = false;
				break;
			}
		}
		if (moveToNext)
		{
			++bullet;
		}

	}

}

void CollisionManager::checkBulletToBossCollisions()
{
	for (auto bullet = m_pBulletList->bulletArray.begin(); bullet != m_pBulletList->bulletArray.end(); )
	{
		bool moveToNext = true;
		
		for (auto boss = m_pBoss->bossArray.begin(); boss != m_pBoss->bossArray.end(); ++boss)
		{
			if (boss->isActive && bullet->checkCollision(boss->getRect()))
			{
				SoundManager::Instance()->playSound("bosshit", 0);
				TextureManager::Instance()->AddSpark(bullet->dst.x, bullet->dst.y);
				if (bossHP >= 20)
				{
					SoundManager::Instance()->playSound("bossdeath2", 0);
					TextureManager::Instance()->AddExplosion(bullet->dst.x+100, bullet->dst.y);
					boss = m_pBoss->bossArray.erase(boss);
					bossDead = true;
				}
				bullet = m_pBulletList->bulletArray.erase(bullet);
				bossHP++;
				moveToNext = false;
				break;
			}
		}
		if (moveToNext)
		{
			++bullet;
		}

	}
}



CollisionManager::CollisionManager()
{
}

CollisionManager::~CollisionManager()
{
}

CollisionManager::CollisionManager(BulletList* bulletList, EnemyList* enemyList, Hero* hero, BossList* boss, WebList* web, ProjectileList* projectile, bProjectileList* bprojectile)
{
	m_pProjectile = projectile;
	m_pBulletList = bulletList;
	m_pEnemyList = enemyList;
	m_pHero = hero;
	m_pBoss = boss;
	m_pWebList = web;
	m_pBossProj = bprojectile;
}




bool CollisionManager::checkCollisions()
{
	checkBulletToWebCollisions();
	checkBulletToEnemyCollisions();
	checkBulletToBossCollisions();
	return checkHeroToEnemyCollisions();

}