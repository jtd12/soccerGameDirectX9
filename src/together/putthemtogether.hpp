#ifndef DEF_PUTTHEMTOGETHER_HPP
#define DEF_PUTTHEMTOGETHER_HPP
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <d3d9.h>
#include <d3dx9.h>
#include<vector>
#include <sstream>
#include<iostream>
#define SCREEN_WIDTH 960 
#define SCREEN_HEIGHT 540
#include"../entities/player/robot.hpp"
#include"../entities/balle/balle.hpp"
#include"../entities/decor/decor.hpp"
#include"../entities/zones/zones.hpp"
#include"../entities/skybox/skybox.hpp"
#include"../entities/supporter/supporter.hpp"
#include"../passLogic/passsystem.hpp"
#include <cstdlib>  // pour rand() et srand()
#include <ctime>    // pour time()
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

inline int randMToN(int M, int N);

class together
{
	public:
		
	together(LPDIRECT3DDEVICE9 d3ddev,HWND hwnd);
	~together();
	void update(LPDIRECT3DDEVICE9 d3ddev);
	void draw(LPDIRECT3DDEVICE9 d3ddev, LPD3DXFONT dxfont);
	
	void prepareTeams();
	void movement();
	void movementAI();
	void movementBall();
	void collision();
	void collisionAI();
	void passer(robot* player);
	void tirer(robot* player);
	void tirerAI(robot* playerAI);
	void collisionStadePlayer(robot* player);
	void collisionStadePlayerAI(robot* playerAI);
	void collisionStadeBall(balle* b);
	void follow();
	void followAI();
	void camFollowBall(LPDIRECT3DDEVICE9 d3ddev);
	void separatePlayer();
	void separatePlayerAI();
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
	void movementGoal();
	void loadSupporters(LPDIRECT3DDEVICE9 d3ddev);
	D3DXVECTOR3 getCamPos();
	D3DXVECTOR3 getLookAt();
	D3DXVECTOR3 getUp();
	void loadCameraMatrix(LPDIRECT3DDEVICE9 d3ddev);
	void goal_();
	
	private:
	float delay;
	std::vector<robot *> player;
	std::vector<robot *> playerAI;
	std::vector<robot*> goal;
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
	int speedCamZ;
	int numberSupport;
	int minNumberSupport;
	bool speedTirAI;
	bool speedTirGoal;
	bool speedTirGoal2;
	float delay2;
	float speedPlayer;
	float rand;
	float rand2;
	int scoreA,scoreB,miTemps;
	float puissancePasse;
    bool chargingPasse;
    LPDIRECTSOUNDBUFFER balleSound = nullptr;
	sound* son;
};
#endif
