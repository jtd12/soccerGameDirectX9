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
#include"robot.hpp"
#include"balle.hpp"
#include"decor.hpp"
#include"zones.hpp"
#include"skybox.hpp"
#include"supporter.hpp"
#include"passsystem.hpp"
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
	void init_graphics();
	void loadCameraMatrix();
	void loadSupporters();
	void prepareTeams();
	void movement();
	void movementAI();
	void movementBall();
	void collision();
	void collisionAI();
	void passer(robot* player);
	void follow();
	void followAI();
	void camFollowBall();
	void input(robot* p);
	void input2();
	void input3();
	void input4();
	void input5();
	void input6();
	void input7();
	void input8();
	void input9();
	void loadCinematik1();
	float delay;

	private:

	LPDIRECT3D9 d3d;
	LPDIRECT3DDEVICE9 d3ddev;			// the pointer to the device class	
	std::vector<robot *> player;
	std::vector<robot *> playerAI;
	balle* b;
	decor * dec;
	decor * water;
	decor* tribunes;
	sky* skybox;
	pass* p;
	int menu,startgame;
	float temps;
	std::vector<zone*> z;
	std::vector<supporter*> support;
	D3DXVECTOR3 camPos,lookAt,up;
	float speed;
	bool controls;

};
#endif
