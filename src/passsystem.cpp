#include"passsystem.hpp"
#include<dos.h>   //for delay()

inline int randMToN(int M, int N)
{

    return M + (rand() / ( RAND_MAX / (N-M) ) ) ;  
}


pass::pass(){
rand=0.0f;
tir=false;
timer=0.1f;	
delay=15;
speed=0.002f;
}
pass::~pass()
{
	
}
void pass::update(balle* b, robot* aiplayer ,float xpos,float xpos2,float zpos,float zpos2,int randX,int randZ,std::vector<robot*> player,
		std::vector<robot*> playerAI){
	
		passer(b,aiplayer, xpos, zpos2, zpos, zpos2,randX,randZ,player,playerAI);
	}
	
void pass::passer(balle* b, robot* aiplayer, float xpos,float xpos2,float zpos,float zpos2,int randX,int randZ,std::vector<robot*> player,
		std::vector<robot*> playerAI){
	
	float distPlayerAIX= aiplayer->getLocation().x-b->getLocation().x;
	float distPlayerAIZ= aiplayer->getLocation().z-b->getLocation().z;
	
	float dist=sqrt(distPlayerAIX*distPlayerAIX)+(distPlayerAIZ*distPlayerAIZ);


	if(tir && dist<6.5f && delay<=2)
	{
  rand=randMToN(randX,randZ);

		
	}
	
	for(int i=0;i<player.size();i++)
	{
	
	 float distPlayerX= player[i]->getLocation().x-b->getLocation().x;
	 
	 float distPlayerZ= player[i]->getLocation().z-b->getLocation().z;
	
	float dist2=sqrt(distPlayerX*distPlayerX)+(distPlayerZ*distPlayerZ);

	if( tir&& aiplayer->gethastheball() && delay<=2)
	{ 
		tir=false;
	}
		
	
	

	
	if(dist<6.5f &&dist2<45.0f &&aiplayer->getLocation().x<xpos && aiplayer->getLocation().x>xpos2 && aiplayer->getLocation().z<zpos && aiplayer->getLocation().z>zpos2 )
	{
		aiplayer->sethastheball(false);
		
		playerAI[rand]->setSpeed(0.2f);
		tir=true;
	
	
}
else
{
		playerAI[rand]->setSpeed(1.3f);
}
 }
 if(delay<0)
  delay=10;



	if(tir && aiplayer->gethastheball()==false)
	{
			setSpeed(0.004f);
		//	playerAI[rand]->setSpeed(0.0f);
	//	std::cout<<"Tir"<<std::endl;
			delay-=0.008f;	
			D3DXVECTOR3 dir=playerAI[rand]->getLocation() - b->getLocation();
			b->setLocationIncremente(D3DXVECTOR3(dir.x*speed,0,dir.z*speed));
		
		
	//	dir.y+=10.5f;

	}



	//std::cout<<tir<<std::endl;
}

void pass::setTir(bool t)
{
	tir=t;
}
bool pass::getTir()
{
	return tir;
}

void pass::setSpeed(float s)
{
	speed=s;
}



	
	
		
	
