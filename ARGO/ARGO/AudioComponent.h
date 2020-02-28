#ifndef AUDIOCOMPONENT
#define AUDIOCOMPONENT
#include <SDL_mixer.h>
#include <SDL.h>
#include <iostream>
#include <string>
#include "Component.h"
class AudioComponent: public Component
{
public:
	AudioComponent();
	~AudioComponent();
	void LoadMusicFile( const char * t_string);
	void LoadMusicFileBG(const char* t_string);
	void LoadMusicFileDeath(const char* t_string);
	void loadMusicFileLevel(const char* t_string);
	void playAudioBG();
	void playAudioCat();
	void playAudioDeath();
	void playAudioLevel();
	void closeAudio();
	void init() override;
	void update() override;
	void render() override;
private:
	Mix_Chunk* m_chunk;
	Mix_Music* m_musicBG;
	Mix_Chunk* m_deathChunk;
	Mix_Chunk* m_levelChunk;
	bool doOnceDie = false;
	bool doOnceBG = false;
};
#endif // !AUDIOCOMPONENT
