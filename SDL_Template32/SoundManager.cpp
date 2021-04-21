#include "SoundManager.h"

SoundManager* SoundManager::s_pInstance = NULL;


SoundManager::SoundManager()
{
	Mix_OpenAudio(22050, AUDIO_S16, 2, 4096);
}

SoundManager::~SoundManager()
{
	Mix_CloseAudio();
}

SoundManager* SoundManager::Instance()
{
	if (s_pInstance == NULL)
	{
		s_pInstance = new SoundManager();
	}

	return s_pInstance;
}

bool SoundManager::load(string fileName, string id, sound_type type)
{
	if (type == SOUND_MUSIC)
	{
		Mix_Music* pMusic = Mix_LoadMUS(fileName.c_str());

		if (pMusic == 0)
		{
			printf("Could not load music: ERROR - %s\n", Mix_GetError());
			return false;
		}

		m_music[id] = pMusic;
		return true;
	}
	else if (type == SOUND_SFX)
	{
		Mix_Chunk* pChunk = Mix_LoadWAV(fileName.c_str());
		if (pChunk == 0)
		{
			printf("Could not load sfx: ERROR - %s\n", Mix_GetError());
			return false;
		}
		m_sfx[id] = pChunk;
		return true;
	}

	printf("Sound Type Not Recognized\n");
	return false;
}

void SoundManager::playSound(string id, int loop)
{
	Mix_PlayChannel(-1, m_sfx[id], loop);
}

void SoundManager::playMusic(string id, int loop)
{
	Mix_PlayMusic( m_music[id], loop);
}

void SoundManager::IncreaseMusicVolume()
{
	cout << "music up\n";
	if (masterVolume + musicVolumeOffset < MIX_MAX_VOLUME)
	{
		Mix_VolumeMusic(masterVolume + ++musicVolumeOffset);
		printf("Master: %i | Music: %i | SFX: %i \n", masterVolume, musicVolumeOffset, sfxVolumeOffset);
	}
	else
	{
		printf("Music already at max: %i\n", masterVolume + musicVolumeOffset);
	}
}

void SoundManager::DecreaseMusicVolume()
{
	cout << "music decrease\n";
	if (masterVolume + musicVolumeOffset > 0)
	{
		Mix_VolumeMusic(masterVolume + --musicVolumeOffset);
		printf("Master: %i | Music: %i | SFX: %i \n", masterVolume, musicVolumeOffset, sfxVolumeOffset);
	}
	else
	{
		printf("Music already at min: %i\n", masterVolume + musicVolumeOffset);
	}
}
void SoundManager::InitAll()
{
	if (!SoundManager::Instance()->load("intromusic.ogg", "bgmusic", SOUND_MUSIC))
	{
		printf("MUSIC LOAD FAILED!\n");
	}
	if (!SoundManager::Instance()->load("dvd.wav", "fire", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}

	if (!SoundManager::Instance()->load("Splat.wav", "splat", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}
	
	if (!SoundManager::Instance()->load("web.wav", "web", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}
	if (!SoundManager::Instance()->load("field2.wav", "bosshit", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}

	if (!SoundManager::Instance()->load("bossdeath2.wav", "bossdeath2", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}

	if (!SoundManager::Instance()->load("bossdeath.wav", "bossdeath", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}

	if (!SoundManager::Instance()->load("truesurvivor.wav", "endingmusic", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}

	if (!SoundManager::Instance()->load("gameovervoice.wav", "gameovervoice", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}
	if (!SoundManager::Instance()->load("bossmusic.wav", "bossmusic", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}

	if (!SoundManager::Instance()->load("intromusic.wav", "startmusic", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}
	if (!SoundManager::Instance()->load("bossshoot.wav", "bossshoot", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}
	if (!SoundManager::Instance()->load("spidershoot.wav", "spidershoot", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}

	if (!SoundManager::Instance()->load("gameover.wav", "gameover", SOUND_SFX))
	{
		printf("SFX LOAD FAILED!\n");
	}
	
	
}
