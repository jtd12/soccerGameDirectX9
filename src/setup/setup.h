#ifndef DEf_SETUP_H
#define DEF_SETUP_H
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include<vector>
#include<iostream>
#define SCREEN_WIDTH 960 
#define SCREEN_HEIGHT 540
#include"../together/putthemtogether.hpp"
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)


class setup
{
	public:
		
		
	setup();
	~setup();
	void initD3D(HWND hwnd,bool windowed);
	void Clear(D3DCOLOR color);
	void begin();
	void end();
	void update();
	void present();
	void render_frame();
	void init_Light();
	void init_graphics(HWND hwnd);

	private:

	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddev;			// the pointer to the device class
	LPD3DXFONT dxfont; 	
	together *p;
	D3DXVECTOR3 camPos,lookAt,up;
	
};
#endif
