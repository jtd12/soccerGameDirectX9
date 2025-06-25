#ifndef DEF_PASSSYSTEM_HPP
#define DEF_PASSSYSTEM_HPP
#include <windows.h>
#include <windowsx.h>
#include <windows.h>
#include <mmsystem.h>
#include <mmreg.h>
#include<iostream>
#include<dos.h>   //for delay()
#include<conio.h>   //for getch()
#include<cstdlib>
#include <cmath>
#include <ctime>
#include"../entities/player/robot.hpp"
#include"../entities/balle/balle.hpp"
#include"../sound/sound.hpp"
#include<vector>
#include <limits>
#include <cstdlib>  // pour rand()
#include <ctime>    // pour time()
using namespace std;

inline int randMToN(int M, int N);
inline float distance3D(float x1, float y1, float z1, float x2, float y2, float z2);

	struct Zone
    {
         float xMin, xMax;
         float zMin, zMax;
         int playerMin, playerMax;
    };
    
class pass
{
	public:
		
	pass(HWND hwnd);
	~pass();
	void update(balle* b,std::vector<robot*> player,
		std::vector<robot*> playerAI);
		void TirerVersBut(robot* player, balle* b);
	void PasserAI(std::vector<robot*>playerAI,robot* player, float xmin, float xmax, float zmin, float zmax, balle* b);
	void setTir(bool t);
	bool getTir();
	void setSpeed(float s);
	
	
	private:
		std::vector<Zone*> zones;
		float rand;
		float timer;
		bool tir;
		float delay;
		float speed;
		D3DXVECTOR3 targetGoal;
		LPDIRECTSOUNDBUFFER balleSound = nullptr;
		sound* son;
		
};

#endif
