#ifndef DEF_SOUND_H
#define DEF_SOUND_H
#include <dsound.h>
#include <windows.h>
#include <mmsystem.h>
#include <mmreg.h>

class sound
{
	public:
		sound(HWND hwnd);
		~sound();
		bool initDirectSound(HWND hwnd);
		LPDIRECTSOUNDBUFFER loadSound(LPCSTR filename);
		
	private:
		LPDIRECTSOUND8 g_pDSound = nullptr;

};

#endif
