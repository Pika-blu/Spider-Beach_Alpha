#pragma once

#include <map>
#include <string>
#include "SDL_mixer.h"
#include <iostream>
using namespace std;

enum sound_type
{
	SOUND_MUSIC = 0,
	SOUND_SFX = 1
};

class SoundManager
{
private:

	static SoundManager* s_pInstance;

	map<string, Mix_Chunk*> m_sfx;
	map<string, Mix_Music*> m_music;



	SoundManager();
	~SoundManager();

	SoundManager(const SoundManager&) {};
	SoundManager& operator=(const SoundManager&) {};


	int masterVolume = MIX_MAX_VOLUME / 2;
	int sfxVolumeOffset = 0;
	int musicVolumeOffset = 0;


public:

	static SoundManager* Instance();

	bool load(string fileName, string id, sound_type type);
	void playSound(string id, int loop);
	void playMusic(string id, int loop);
	void IncreaseMusicVolume();
	void DecreaseMusicVolume();
	void InitAll();

};

