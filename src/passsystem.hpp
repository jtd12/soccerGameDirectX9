#ifndef DEF_PASSSYSTEM_HPP
#define DEF_PASSSYSTEM_HPP
#include<iostream>
#include<dos.h>   //for delay()
#include<conio.h>   //for getch()
#include<cstdlib>
#include <ctime>
#include"robot.hpp"
#include"balle.hpp"
#include<vector>

using namespace std;

inline int randMToN(int M, int N);


class pass
{
	public:
		
	pass();
	~pass();
	void update(balle* b, robot* aiplayer, float xpos,float xpos2,float zpos,float zpos2,int randX,int randZ,std::vector<robot*> player,
		std::vector<robot*> playerAI);
	void passer(balle* b, robot* aiplayer, float xpos,float xpos2,float zpos,float zpos2,int randX,int randZ,std::vector<robot*> player,
		std::vector<robot*> playerAI);
	void setTir(bool t);
	bool getTir();
	void setSpeed(float s);
	
	private:
		float rand;
		float timer;
		bool tir;
		float delay;
		float speed;
		
};

#endif
