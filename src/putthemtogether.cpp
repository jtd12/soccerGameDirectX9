#include"putthemtogether.hpp"


together::together(LPDIRECT3DDEVICE9 d3ddev)
{
		player.push_back(new robot(D3DXVECTOR3(10,13.5,100),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,110),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,120),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,130),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,140),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,150),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,160),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,70),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,80),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		player.push_back(new robot(D3DXVECTOR3(10,13.5,90),d3ddev,0.0f,D3DXVECTOR3(1.5f,0.1f,0.1f)));
		
		
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,100),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,110),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,120),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,130),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,140),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,150),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,160),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,70),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,80),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		playerAI.push_back(new robot(D3DXVECTOR3(20,13.5,90),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		goal.push_back(new robot(D3DXVECTOR3(20,13.5,100),d3ddev,0.0f,D3DXVECTOR3(0.25f,0.2f,0.4f)));
		goal.push_back(new robot(D3DXVECTOR3(20,13.5,110),d3ddev,0.0f,D3DXVECTOR3(0.75f,0.2f,0.1f)));

		dec=new decor(d3ddev,"data/stade.x");
		tribunes=new decor(d3ddev,"data/tribunes_nord.x");
		b=new balle(d3ddev);
		
		startgame=0;
		menu=1;
		
		z.push_back(new zone(D3DXVECTOR3(50,13,50),d3ddev));
		z.push_back(new zone(D3DXVECTOR3(50,13,-50),d3ddev));
		z.push_back(new zone(D3DXVECTOR3(-50,13,50),d3ddev));
		z.push_back(new zone(D3DXVECTOR3(-50,13,-50),d3ddev));
		
		skybox=new sky(d3ddev);
		
		water=new decor(d3ddev,"data/water.x");
		
		loadSupporters(d3ddev);
		
	  	camPos=D3DXVECTOR3(32.0f, 200.0f, 250.0f);
        lookAt=D3DXVECTOR3(25.0f, 45.0f, 70.0f);
    	up=D3DXVECTOR3(0.0f, 1.0f, 0.0f);
    	speed=0.2f;
		delay=5.0f;
		speedCamZ=200;
		p=new pass();
		numberSupport=0;
		minNumberSupport=0;
		speedTirAI=false;
	    delay2=10.0f;
	    speedPlayer=0.2;
	    speedTirGoal=false;
	    speedTirGoal2=false;
	    rand=0.0f;
	    rand2=0.0f;
	    scoreA=0;
	    scoreB=0;
	    miTemps=0;
}

together::~together()
{
for(int i=0;i<player.size();i++)
  delete player[i];
  
for(int i=0;i<playerAI.size();i++)
  delete playerAI[i]; 

for(int i=0;i<support.size();i++)
  delete support[i]; 
    
for(int i=0;i<z.size();i++)
 delete z[i];
 
delete skybox; 	
delete dec;
delete b;
delete water;
delete tribunes;

delete goal[0];
delete goal[1];
}


void together::goal_()
{
	if(b->getLocation().x>190 &&  b->getLocation().x<194.5f && b->getLocation().z>-15 && b->getLocation().z<15)
	{
		scoreA+=1;
		b->setLocation(D3DXVECTOR3(0,b->getLocation().y,0));
	
		
		  player[0]->setLocation(D3DXVECTOR3(0,5,0));
		  player[1]->setLocation(D3DXVECTOR3(-10,5,2));
		  player[2]->setLocation(D3DXVECTOR3(-15,5,5));
		  player[3]->setLocation(D3DXVECTOR3(-20,5,-10));
		  player[4]->setLocation(D3DXVECTOR3(-20,5,-10));
		  player[5]->setLocation(D3DXVECTOR3(-30,5,5));
		  player[6]->setLocation(D3DXVECTOR3(-30,5,-10));
		  player[7]->setLocation(D3DXVECTOR3(-40,5,0));
		  player[8]->setLocation(D3DXVECTOR3(-40,5,-5));
		  player[9]->setLocation(D3DXVECTOR3(-40,5,-10));
		  
		  playerAI[0]->setLocation(D3DXVECTOR3(0,5,0));
		  playerAI[1]->setLocation(D3DXVECTOR3(10,5,10));
		  playerAI[2]->setLocation(D3DXVECTOR3(10,5,5));
		  playerAI[3]->setLocation(D3DXVECTOR3(20,5,-20));
		  playerAI[4]->setLocation(D3DXVECTOR3(20,5,-10));
		  playerAI[5]->setLocation(D3DXVECTOR3(30,5,10));
		  playerAI[6]->setLocation(D3DXVECTOR3(30,5,-10));
		  playerAI[7]->setLocation(D3DXVECTOR3(40,5,0));
		  playerAI[8]->setLocation(D3DXVECTOR3(40,5,-5));
		  playerAI[9]->setLocation(D3DXVECTOR3(40,5,-10));
	}
		if(b->getLocation().x<-180 && b->getLocation().x>-184.5f && b->getLocation().z>-15 && b->getLocation().z<15)
	{
		b->setLocation(D3DXVECTOR3(0,b->getLocation().y,0));
		scoreB+=1;
		
		
	  player[0]->setLocation(D3DXVECTOR3(0,5,0));
	  player[1]->setLocation(D3DXVECTOR3(-10,5,2));
	  player[2]->setLocation(D3DXVECTOR3(-15,5,5));
	  player[3]->setLocation(D3DXVECTOR3(-20,5,-10));
	  player[4]->setLocation(D3DXVECTOR3(-20,5,-10));
	  player[5]->setLocation(D3DXVECTOR3(-30,5,5));
	  player[6]->setLocation(D3DXVECTOR3(-30,5,-10));
	  player[7]->setLocation(D3DXVECTOR3(-40,5,0));
	  player[8]->setLocation(D3DXVECTOR3(-40,5,-5));
	  player[9]->setLocation(D3DXVECTOR3(-40,5,-10));
	  
	  playerAI[0]->setLocation(D3DXVECTOR3(0,5,0));
	  playerAI[1]->setLocation(D3DXVECTOR3(10,5,10));
	  playerAI[2]->setLocation(D3DXVECTOR3(10,5,5));
	  playerAI[3]->setLocation(D3DXVECTOR3(20,5,-20));
	  playerAI[4]->setLocation(D3DXVECTOR3(20,5,-10));
	  playerAI[5]->setLocation(D3DXVECTOR3(30,5,10));
	  playerAI[6]->setLocation(D3DXVECTOR3(30,5,-10));
	  playerAI[7]->setLocation(D3DXVECTOR3(40,5,0));
	  playerAI[8]->setLocation(D3DXVECTOR3(40,5,-5));
	  playerAI[9]->setLocation(D3DXVECTOR3(40,5,-10));
	}
}

void together::update(LPDIRECT3DDEVICE9 d3ddev)
{
	skybox->update();
	for(int i=0;i<support.size();i++)
	 support[i]->update();
	 
	for(int i=0;i<player.size();i++)
	 player[i]->update();
	
	for(int i=0;i<playerAI.size();i++)
	 playerAI[i]->update();
	 

	 
	 goal[0]->update();
	 goal[1]->update();
	
	
	std::cout<<"start:"<<startgame<<std::endl;
	std::cout<<"temps:"<<temps<<std::endl;
	
	if(KEY_DOWN(VK_SPACE))
	{
		menu++;
	  			
				  if(menu>2)
				  {
				  	menu=2;
					  }	
					  
					  if(menu==2)
					  {
					  	startgame++;
					  
					  if(startgame>15)
					  {
					  	startgame=0;
					  }
				}
	}
	
	if(temps>95)
{
	miTemps+=1;
	temps=0;
	b->setLocation(D3DXVECTOR3(0,2.3f,0));
}

if(miTemps>=2)
{
	miTemps=2;
}

	
	if(startgame<3)
	{
	loadCameraMatrix(d3ddev);		
	temps+=0.01f;
	loadCinematik1();
	prepareTeams();
 	numberSupport=3000;
 	minNumberSupport=0;
	}


	
	
	
	if(startgame>3 && startgame<10 && temps>3)
	{
	printf("position ballX: %2f ",b->getLocation().x);
	printf("position ballY: %2f ",b->getLocation().y);
	printf("position ballZ: %2f ",b->getLocation().z);
	minNumberSupport=150;
	numberSupport=2000;
	camFollowBall( d3ddev);
	temps+=0.01f;
	collision();
	collisionAI();
	movementBall();
	movement();
	movementAI();
	movementGoal();
	separatePlayer();
	separatePlayerAI();
	
	passer(player[0]);
	passer(player[1]);
	passer(player[2]);
	passer(player[3]);
	passer(player[4]);
	passer(player[5]);
	passer(player[6]);
	passer(player[7]);
	passer(player[8]);
	passer(player[9]);
	
	
	tirer(player[0]);
	tirer(player[1]);
	tirer(player[2]);
	tirer(player[3]);
	tirer(player[4]);
	tirer(player[5]);
	tirer(player[6]);
	tirer(player[7]);
	tirer(player[8]);
	tirer(player[9]);
	
	tirerAI(playerAI[0]);
	tirerAI(playerAI[1]);
	tirerAI(playerAI[2]);
	tirerAI(playerAI[3]);
	tirerAI(playerAI[4]);
	tirerAI(playerAI[5]);
	tirerAI(playerAI[6]);
	tirerAI(playerAI[7]);
	tirerAI(playerAI[8]);
	tirerAI(playerAI[9]);
	
	follow();
	followAI();
	b->update();
	collisionStadePlayer(player[0]);
	collisionStadePlayer(player[1]);
	collisionStadePlayer(player[2]);
	collisionStadePlayer(player[3]);
	collisionStadePlayer(player[4]);
	collisionStadePlayer(player[5]);
	collisionStadePlayer(player[6]);
	collisionStadePlayer(player[7]);
	collisionStadePlayer(player[8]);
	collisionStadePlayer(player[9]);
	
	collisionStadePlayerAI(playerAI[0]);
	collisionStadePlayerAI(playerAI[1]);
	collisionStadePlayerAI(playerAI[2]);
	collisionStadePlayerAI(playerAI[3]);
	collisionStadePlayerAI(playerAI[4]);
	collisionStadePlayerAI(playerAI[5]);
	collisionStadePlayerAI(playerAI[6]);
	collisionStadePlayerAI(playerAI[7]);
	collisionStadePlayerAI(playerAI[8]);
	collisionStadePlayerAI(playerAI[9]);
	
	collisionStadeBall(b);
	
	
	p->update(b,playerAI[0],80,-700,100,-150,4,9,player,playerAI);
	p->update(b,playerAI[1],80,-700,100,-150,6,9,player,playerAI);
	p->update(b,playerAI[2],80,-700,100,-150,3,9,player,playerAI);
	p->update(b,playerAI[3],80,-700,100,-150,5,9,player,playerAI);
	p->update(b,playerAI[4],80,-700,100,-150,7,9,player,playerAI);
	p->update(b,playerAI[5],80,-700,100,-150,1,3,player,playerAI);
	p->update(b,playerAI[6],80,-700,100,-150,1,3,player,playerAI);
	p->update(b,playerAI[7],80,-700,100,-150,1,3,player,playerAI);
	p->update(b,playerAI[8],80,-700,100,-150,1,3,player,playerAI);
	p->update(b,playerAI[9],80,-700,100,-150,1,3,player,playerAI);
	
	goal_();
		
	}


}

void together::draw(LPDIRECT3DDEVICE9 d3ddev, LPD3DXFONT dxfont)
{
	for(int i=0;i<player.size();i++)
	  player[i]->render(d3ddev);
	   
	for(int i=0;i<playerAI.size();i++)
	  playerAI[i]->render(d3ddev);
	  

	
	for(int i=minNumberSupport;i<numberSupport;i++)
	  support[i]->render(d3ddev);
	  
	goal[0]->render(d3ddev);
	goal[1]->render(d3ddev);
	  
	b->draw(d3ddev);
	
	water->draw(d3ddev);
	
	dec->draw(d3ddev);
	
	tribunes->draw(d3ddev);
	
	skybox->draw(d3ddev);
	

	for(int i=0;i<z.size();i++)
  	z[i]->draw(d3ddev);
  	
  	  static RECT textbox; SetRect(&textbox, 300, 0, 700, 480); 
  	  static RECT textbox2; SetRect(&textbox2, 10, 10, 200, 120); 
  	  static RECT textbox3; SetRect(&textbox3, 50, 450, 310, 550);

if(startgame<3)
{
    // draw the Hello World text
    dxfont->DrawTextA(NULL,
                      "Press Space To Start Game!",
                      27,
                      &textbox,
                      DT_CENTER | DT_VCENTER,
                      D3DCOLOR_ARGB(255, 255, 255, 255));
  }
  
std::stringstream ss;
ss << "Temps: " << temps;
std::string tempsText = ss.str();

	dxfont->DrawTextA(NULL,
                      tempsText.c_str(),
                      10,
                      &textbox2,
                      DT_CENTER | DT_VCENTER,
                      D3DCOLOR_ARGB(255, 255, 255, 255));
                      

std::stringstream ss2;
ss2 << "Visiteur " << scoreA <<"  -  "<< scoreB <<" Local ";
std::string scoreTxt = ss2.str();

	dxfont->DrawTextA(NULL,
                      scoreTxt.c_str(),
                      23,
                      &textbox3,
                      DT_CENTER | DT_VCENTER,
                      D3DCOLOR_ARGB(255, 255, 255, 255));
                      
                      
}


void together::loadCameraMatrix(LPDIRECT3DDEVICE9 d3ddev)
{
	camPos= getCamPos();
	lookAt= getLookAt();
	up= getUp();
  // set the view transform
    D3DXMATRIX matView;    // the view transform matrix
  	
    
    D3DXMatrixLookAtLH(&matView,
                       &camPos,		// the camera position
                       &lookAt,		// the look-at position
                       &up);		// the up direction
    d3ddev->SetTransform(D3DTS_VIEW, &matView);

    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
                               D3DXToRadian(80),			// the vertical field of view
                               960.0f/540.0f,			// aspect ratio
                               0.5f,						// the near view-plane
                               10000.0f);						// the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);	
}



void together::camFollowBall(LPDIRECT3DDEVICE9 d3ddev)
{
	if(b->getLocation().z>80)
	 speedCamZ=90;
	else
	 speedCamZ=200;
	 
	D3DXVECTOR3 camPos2=D3DXVECTOR3(0+b->getLocation().x,80,speedCamZ+b->getLocation().z);
	D3DXVECTOR3 camTarget=D3DXVECTOR3(b->getLocation().x,-20,b->getLocation().z);
	
	// set the view transform
    D3DXMATRIX matView;    // the view transform matrix
  
    
    D3DXMatrixLookAtLH(&matView,
                       &camPos2,		// the camera position
                       &camTarget,		// the look-at position
                       &up);		// the up direction
    d3ddev->SetTransform(D3DTS_VIEW, &matView);

    // set the projection transform
    D3DXMATRIX matProjection;    // the projection transform matrix
    D3DXMatrixPerspectiveFovLH(&matProjection,
                               D3DXToRadian(40),			// the vertical field of view
                               960.0f/540.0f,			// aspect ratio
                               4.0f,						// the near view-plane
                               10000.0f);						// the far view-plane
    d3ddev->SetTransform(D3DTS_PROJECTION, &matProjection);	
	
}


	D3DXVECTOR3 together::getCamPos()
	{
		return camPos;
	}
	
	D3DXVECTOR3 together::getLookAt()
	{
	return lookAt;
	}
	
	D3DXVECTOR3 together::getUp()
	{
	return up;
	}
	
void together::movementAI()
{
	
		
							
								for(int j=0;j<playerAI.size();j++)
	{
										
										
											
													
												if(playerAI[j]->gethastheball()==false  &&  playerAI[j]->getNext()==false)
												{
													playerAI[j]->setattaquer(true);
												
												}
											
												else
												{
													playerAI[j]->setattaquer(false);
												
												}
											
											
										
									}
												for(int i=0;i<playerAI.size();i++)
											{
											if(playerAI[i]->gethastheball() && playerAI[i]->movement(D3DXVECTOR3 (-130+i,4,0),-1))
			{
				
			}
		}
//centrer
										for(int i=0;i<4;i++)
											{
										if( b->centrer_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (110+i,4,-20+(19*i)),-1))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrer_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (50+i,4,-125+(27*i)),-1))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( b->centrer_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (90+i,4,-175+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
									
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerAvant_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (160+i,4,-20+(12*i)),-1))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrerAvant_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-90+i,4,-25+(7*i)),-1))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( b->centrerAvant_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-20+i,4,-25+(7*i)),-1))
											 {
											 	
											 }
										}
									}
									
									
									//centreravant
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerArriere_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (20+i,4,-20+(19*i)),-1))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrerArriere_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-150+i,4,-85+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( b->centrerArriere_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-60+i,4,-75+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
									//centrercotedroit
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerCoteDroit_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (175+i,4,-5+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrerCoteDroit_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-50+i,4,-75+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( b->centrerCoteDroit_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-100+i,4,-45+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
										//centrercotegauche
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerCoteGauche_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (110+i,4,-105+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrerCoteGauche_()  && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-100+i,4,-190+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( b->centrerCoteGauche_()  && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movement(D3DXVECTOR3 (-20+i,4,-210+(17*i)),-1))
											 {
											 	
											 }
										}
									}
									
									
									
									
												
							
										
//centrer
									
											
							
		
	
}


void together::input(robot* p)
{
	
		if(KEY_DOWN(VK_UP) )
	{
		
			p->update(D3DXVECTOR3(speedPlayer,0,0));
			p->setRot(1.5f);
	}

		if(KEY_DOWN(VK_DOWN) )
	{
		
			p->setRot(-1.5f);
			p->update(D3DXVECTOR3(-speedPlayer,0,0));
	}
	
	if(KEY_DOWN(VK_RIGHT) )
	{

		p->setRot(3.0f);
			p->update(D3DXVECTOR3(0.0,0,speedPlayer));
	}
	if(KEY_DOWN(VK_LEFT) )
	{

		p->setRot(0.0f);
			p->update(D3DXVECTOR3(0.0,0,-speedPlayer));
	}
	if(KEY_DOWN(VK_UP)  && KEY_DOWN(VK_RIGHT))
	{
	
			p->setRot(-2.25f);
	}
		if(KEY_DOWN(VK_UP)  && KEY_DOWN(VK_LEFT) )
	{
	
			p->setRot(2.25f);
	}
		if(KEY_DOWN(VK_DOWN)  && KEY_DOWN(VK_RIGHT) )
	{

			p->setRot(-0.75f);
	}
		if(KEY_DOWN(VK_DOWN)  && KEY_DOWN(VK_LEFT) )
	{
		
			p->setRot(0.75f);
	}
	
		if(KEY_DOWN(VK_SHIFT) )
	{
		
		       speedPlayer=0.35;
	}
	else
	{
			speedPlayer=0.2;
	}
		

}

void together::collision()
{
	for(int i=0;i<player.size();i++)
	 	for(int j=0;j<playerAI.size();j++)
	{
	
	float d=sqrt(((player[i]->getLocation().x-b->getLocation().x)*(player[i]->getLocation().x-b->getLocation().x))
	+((player[i]->getLocation().y-b->getLocation().y)*(player[i]->getLocation().y-b->getLocation().y))
	+((player[i]->getLocation().z-b->getLocation().z)*(player[i]->getLocation().z-b->getLocation().z)));
	
//	d = sqrt(((p1x - p2x) * (p1x – p2x)) + ((p1y – p2y) * (p1y – p2y)) + ((p1z – p2z) * (p1z – p2z)));

		if(d<8.0f &&  player[i]->getTirer()==false )
		{
			speedTirGoal=false;
			player[i]->sethastheball(true);
			player[i]->setTirer(false);
			playerAI[j]->sethastheball(false);
			speedTirAI=false;
			speedTirGoal2=false;
			p->setTir(false);
		//	controls=true;
			
			
		}
		else
		{
			player[i]->sethastheball(false);
		
		}
		if(player[i]->gethastheball() )
		{
			b->setLocation(D3DXVECTOR3(player[i]->getLocation().x-6.5f,b->getLocation().y,player[i]->getLocation().z));
		}
			if(player[i]->gethastheball() && KEY_DOWN(VK_UP))
		{
			b->setLocation(D3DXVECTOR3(player[i]->getLocation().x+1.4f,b->getLocation().y,player[i]->getLocation().z));
		}
			if(player[i]->gethastheball() && KEY_DOWN(VK_DOWN))
		{
			b->setLocation(D3DXVECTOR3(player[i]->getLocation().x-0.4f,b->getLocation().y,player[i]->getLocation().z));
		}
		if(player[i]->gethastheball() && KEY_DOWN(VK_RIGHT))
		{
			b->setLocation(D3DXVECTOR3(player[i]->getLocation().x,b->getLocation().y,player[i]->getLocation().z+0.4f));
		}
		if(player[i]->gethastheball() && KEY_DOWN(VK_LEFT))
		{
			b->setLocation(D3DXVECTOR3(player[i]->getLocation().x,b->getLocation().y,player[i]->getLocation().z-0.4f));
		}
		
		
	}	
}

void together::collisionAI()
{
	for(int i=0;i<playerAI.size();i++)
 {
 
	float d=sqrt(((playerAI[i]->getLocation().x-b->getLocation().x)*(playerAI[i]->getLocation().x-b->getLocation().x))
	+((playerAI[i]->getLocation().y-b->getLocation().y)*(playerAI[i]->getLocation().y-b->getLocation().y))
	+((playerAI[i]->getLocation().z-b->getLocation().z)*(playerAI[i]->getLocation().z-b->getLocation().z)));
	
//	d = sqrt(((p1x - p2x) * (p1x – p2x)) + ((p1y – p2y) * (p1y – p2y)) + ((p1z – p2z) * (p1z – p2z)));

		if(d<6.0f &&  playerAI[i]->getTirer()==false)
		{
			playerAI[i]->sethastheball(true);
			speedTirGoal=false;
			speedTirGoal2=false;
			
		//	p->setTir(false);
			
		}
	
		if(d>7.0f)
		{
			playerAI[i]->sethastheball(false);
		}
	
		
		if(playerAI[i]->gethastheball() &&  p->getTir()==false && playerAI[i]->getTirer()==false && speedTirAI==false)
		{
			
			b->setLocation(D3DXVECTOR3(playerAI[i]->getLocation().x-1.3f,b->getLocation().y,playerAI[i]->getLocation().z));
		
		}
		
	
	}
		
	
	
}

void together::follow()
{//si joueur proche de lennemi alors suivre ennemi
	D3DXVECTOR3 Distance = player[0]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance2 = player[1]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance3 = player[2]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance4 = player[3]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance5 = player[4]->getLocation() - b->getLocation();
	D3DXVECTOR3 Distance6 = player[5]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance7 = player[6]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance8 = player[7]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance9 = player[8]->getLocation()-b->getLocation();
	D3DXVECTOR3 Distance10 = player[9]->getLocation()-b->getLocation();
	float hyp1 = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
	float hyp2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
	float hyp3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
	float hyp4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
	float hyp5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
	float hyp6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
	float hyp7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
	float hyp8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
	float hyp9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
	float hyp10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));



if(hyp1<=hyp2 && hyp1<=hyp3 && hyp1<=hyp4 && hyp1<=hyp5 && hyp1<=hyp6  && hyp1<=hyp7 && hyp1<=hyp8 && hyp1<=hyp9 && hyp1<=hyp10
   )
   {
     
    player[0]->setNext(true);
  
    
     
   }
    else
   {
       player[0]->setNext(false);
    
   
   }
      if(hyp2<=hyp1 && hyp2<=hyp3 && hyp2<=hyp4 && hyp2<=hyp5 && hyp2<=hyp6 && hyp2<=hyp7 && hyp2<=hyp8 && hyp2<=hyp9 && hyp2<=hyp10
      )
   {
     

       player[1]->setNext(true);
    
    
     
   }
   else
   {
       player[1]->setNext(false);
   }
   if(hyp3<=hyp1 && hyp3<=hyp2 && hyp3<=hyp4 && hyp3<=hyp5 && hyp3<=hyp6 && hyp3<=hyp7 && hyp3<=hyp8 && hyp3<=hyp9 && hyp3<=hyp10)
   {
      
       player[2]->setNext(true);
     
   }
   else
   {
       player[2]->setNext(false);
   }
  
  if(hyp4<=hyp1 && hyp4<=hyp2 && hyp4<=hyp3 && hyp4<=hyp5 && hyp4<=hyp6 && hyp4<=hyp7 && hyp4<=hyp8 && hyp4<=hyp9 && hyp4<=hyp10)
   {
    
       player[3]->setNext(true);
   
   }
   else
   {
       player[3]->setNext(false);
   }
   if(hyp5<=hyp1 && hyp5<=hyp2 && hyp5<=hyp3 && hyp5<=hyp4 && hyp5<=hyp6  && hyp5<=hyp7 && hyp5<=hyp8 && hyp5<=hyp9 && hyp5<=hyp10)
   {
    
       player[4]->setNext(true);
   
   }
   else
   {
       player[4]->setNext(false);
   }
  
 if(hyp6<=hyp1 && hyp6<=hyp2 && hyp6<=hyp3 && hyp6<=hyp4 && hyp6<=hyp5  && hyp6<=hyp7 && hyp6<=hyp8 && hyp6<=hyp9 && hyp6<=hyp10
 )
   {
    
       player[5]->setNext(true);
   
   }
   else
   {
       player[5]->setNext(false);
   }
  
 if(hyp7<=hyp1 && hyp7<=hyp2 && hyp7<=hyp3 && hyp7<=hyp4 && hyp7<=hyp5  && hyp7<=hyp6 && hyp7<=hyp8 && hyp7<=hyp9 && hyp7<=hyp10 )
   {
    
       player[6]->setNext(true);
   
   }
   else
   {
       player[6]->setNext(false);
   }
  if(hyp8<=hyp1 && hyp8<=hyp2 && hyp8<=hyp3 && hyp8<=hyp4 && hyp8<=hyp5  && hyp8<=hyp6 && hyp8<=hyp10
 )
   {
    
       player[7]->setNext(true);
   
   }
   else
   {
       player[7]->setNext(false);
   }

   
    if(hyp9<=hyp1 && hyp9<=hyp2 && hyp9<=hyp3 && hyp9<=hyp4 && hyp9<=hyp5   && hyp9<=hyp10
 )
   {
    
       player[8]->setNext(true);
   
   }
   else
   {
       player[8]->setNext(false);
   }

    if(hyp10<=hyp1  && hyp10<=hyp2 && hyp10<=hyp3 && hyp10<=hyp4  && hyp10<=hyp6 && hyp10<=hyp7 && hyp10<=hyp8 && hyp10<=hyp9
 )
   {
    
       player[9]->setNext(true);
   
   }
   else
   {
  
       player[9]->setNext(false);
   }
  
 
   
    if(player[0]->getNext())
{

	input(player[0]);

									//	input();
										
}

if(player[1]->getNext())
{

	input(player[1]);

									//	input2();
										
}
if(player[2]->getNext())
{

	input(player[2]);

									//	input3();
										
}
if(player[3]->getNext())
{


	input(player[3]);
									//	input4();
										
}
if(player[4]->getNext())
{

	input(player[4]);

									//	input5();
										
}
if(player[5]->getNext())
{

	input(player[5]);

									//	input6();
										
}
if(player[6]->getNext())
{

	input(player[6]);

									//	input7();
										
}
if(player[7]->getNext())
{


	input(player[7]);
									//	input8();
										
}
if(player[8]->getNext())
{

	input(player[8]);

									//	input9();
										
}
if(player[9]->getNext())
{



	input(player[9]);
									
}
   
if(player[0]->gethastheball())
{
	input(player[0]);
}
	
if(player[1]->gethastheball())
{
	input(player[1]);
}
	
if(player[2]->gethastheball())
{
	input(player[2]);
}
	
if(player[3]->gethastheball())
{
	input(player[3]);
}
	
if(player[4]->gethastheball())
{
	input(player[4]);
}
	
if(player[5]->gethastheball())
{
	input(player[5]);
}
	
if(player[6]->gethastheball())
{
	input(player[6]);
}
	
if(player[7]->gethastheball())
{
	input(player[7]);
}
	
if(player[8]->gethastheball())
{
	input(player[8]);
}
	
if(player[9]->gethastheball())
{
	input(player[9]);
}


	

}



void together::followAI()
{
D3DXVECTOR3 Distance = playerAI[0]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance2 = playerAI[1]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance3 = playerAI[2]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance4 = playerAI[3]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance5 = playerAI[4]->getLocation()- b->getLocation();
D3DXVECTOR3 Distance6 = playerAI[5]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance7 = playerAI[6]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance8 = playerAI[7]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance9 = playerAI[8]->getLocation()-b->getLocation();
D3DXVECTOR3 Distance10 = playerAI[9]->getLocation()-b->getLocation();
float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));

	if(hypotenuse<hypotenuse2 && hypotenuse<hypotenuse3 && hypotenuse<hypotenuse4 && hypotenuse<hypotenuse5 && hypotenuse<hypotenuse6 && hypotenuse<hypotenuse7 && hypotenuse<hypotenuse8 && hypotenuse<hypotenuse9 
&& hypotenuse<hypotenuse10 && hypotenuse>0.9f)
{
playerAI[0]->setNext(true);
}
else
{
playerAI[0]->setNext(false);
}
if(playerAI[0]->getNext()  )
{



											playerAI[0]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
										
}


if(hypotenuse2<hypotenuse && hypotenuse2<hypotenuse3 && hypotenuse2<hypotenuse4 && hypotenuse2<hypotenuse5 && hypotenuse2<hypotenuse6 && hypotenuse2<hypotenuse7 && hypotenuse2<hypotenuse8 && hypotenuse2<hypotenuse9 
&& hypotenuse2<hypotenuse10 &&hypotenuse2>0.9f)
{
			
playerAI[1]->setNext(true);
}
else
{
playerAI[1]->setNext(false);
}
			if(playerAI[1]->getNext() )
			{
										playerAI[1]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
										
}
if(hypotenuse3<hypotenuse && hypotenuse3<hypotenuse2 && hypotenuse3<hypotenuse4 && hypotenuse3<hypotenuse5 && hypotenuse3<hypotenuse6 && hypotenuse3<hypotenuse7 && hypotenuse3<hypotenuse8 && hypotenuse3<hypotenuse9 
&& hypotenuse3<hypotenuse10 &&hypotenuse3>0.9f)
{
playerAI[2]->setNext(true);
}
else
{
playerAI[2]->setNext(false);
}
if(playerAI[2]->getNext()   )
{


										playerAI[2]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
}

if(hypotenuse4<hypotenuse && hypotenuse4<hypotenuse2 && hypotenuse4<hypotenuse3 && hypotenuse4<hypotenuse5 && hypotenuse4<hypotenuse6 && hypotenuse4<hypotenuse7 && hypotenuse4<hypotenuse8 && hypotenuse4<hypotenuse9 
&& hypotenuse4<hypotenuse10 &&hypotenuse4>0.9f)
{
playerAI[3]->setNext(true);
}
else
{
playerAI[3]->setNext(false);
}
if(playerAI[3]->getNext()  )
{


											playerAI[3]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
}


if(hypotenuse5<hypotenuse && hypotenuse5<hypotenuse2 && hypotenuse5<hypotenuse3 && hypotenuse5<hypotenuse4 && hypotenuse5<hypotenuse6 && hypotenuse5<hypotenuse7 && hypotenuse5<hypotenuse8 && hypotenuse5<hypotenuse9
&& hypotenuse5<hypotenuse10  &&hypotenuse5>0.9f)
{
playerAI[4]->setNext(true);
}
else
{
playerAI[4]->setNext(false);
}
if(playerAI[4]->getNext()  )
{

				
											playerAI[4]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
}


if(hypotenuse6<hypotenuse && hypotenuse6<hypotenuse2 && hypotenuse6<hypotenuse3 && hypotenuse6<hypotenuse4 && hypotenuse6<hypotenuse5 && hypotenuse6<hypotenuse7 && hypotenuse6<hypotenuse8 && hypotenuse6<hypotenuse9 
&& hypotenuse6<hypotenuse10 &&hypotenuse6>0.9f )
{
playerAI[5]->setNext(true);
}
else
{
playerAI[5]->setNext(false);
}
if(playerAI[5]->getNext() )
{


											playerAI[5]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
										
}


if(hypotenuse7<hypotenuse && hypotenuse7<hypotenuse2 && hypotenuse7<hypotenuse3 && hypotenuse7<hypotenuse4 && hypotenuse7<hypotenuse5 && hypotenuse7<hypotenuse6 && hypotenuse7<hypotenuse8 && hypotenuse7<hypotenuse9 
&& hypotenuse7<hypotenuse10 &&hypotenuse7>0.9f )
{
playerAI[6]->setNext(true);
}
else
{
playerAI[6]->setNext(false);
}
if(playerAI[6]->getNext()  )
{

							playerAI[6]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
}




if(hypotenuse8<hypotenuse && hypotenuse8<hypotenuse2 && hypotenuse8<hypotenuse3 && hypotenuse8<hypotenuse4 && hypotenuse8<hypotenuse5 && hypotenuse8<hypotenuse6 && hypotenuse8<hypotenuse7 && hypotenuse8<hypotenuse9 
&& hypotenuse8<hypotenuse10 &&hypotenuse8>0.9f )
{

playerAI[7]->setNext(true);
}
else
{
playerAI[7]->setNext(false);
}
if(playerAI[7]->getNext()  )
{


									playerAI[7]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
							
}


if(hypotenuse9<hypotenuse && hypotenuse9<hypotenuse2 && hypotenuse9<hypotenuse3 && hypotenuse9<hypotenuse4 && hypotenuse9<hypotenuse5 && hypotenuse9<hypotenuse6 && hypotenuse9<hypotenuse7 && hypotenuse9<hypotenuse8 
&& hypotenuse9<hypotenuse10  &&hypotenuse9>0.9f)
{
playerAI[8]->setNext(true);
}
else
{
playerAI[8]->setNext(false);
}
if(playerAI[8]->getNext()  )
{


											playerAI[8]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
										
}


if(hypotenuse10<hypotenuse && hypotenuse10<hypotenuse2 && hypotenuse10<hypotenuse3 && hypotenuse10<hypotenuse4 && hypotenuse10<hypotenuse5 && hypotenuse10<hypotenuse6 && hypotenuse10<hypotenuse7 && hypotenuse10<hypotenuse8 
&&  hypotenuse10<hypotenuse9&&hypotenuse10>0.9f)
{
playerAI[9]->setNext(true);
}
else
{
playerAI[9]->setNext(false);
}
if(playerAI[9]->getNext()   )
{



	playerAI[9]->movement(D3DXVECTOR3(b->getLocation().x,3.5f,b->getLocation().z),-1.0f);
										
}


	
								
									
								
							

}

void together::prepareTeams()
{
player[0]->movement(D3DXVECTOR3(-150,13,50),-1.0f);
player[1]->movement(D3DXVECTOR3(-150,13,0),-1.0f);
player[2]->movement(D3DXVECTOR3(-150,13,-50),-1.0f);
player[3]->movement(D3DXVECTOR3(-150,13,-90),-1.0f);
player[4]->movement(D3DXVECTOR3(-80,13,-70),-1.0f);
player[5]->movement(D3DXVECTOR3(-80,13,-40),-1.0f);
player[6]->movement(D3DXVECTOR3(-80,13,0),-1.0f);
player[7]->movement(D3DXVECTOR3(-80,13,70),-1.0f);
player[8]->movement(D3DXVECTOR3(-30,13,-70),-1.0f);
player[9]->movement(D3DXVECTOR3(-30,13,-30),-1.0f);

playerAI[0]->movement(D3DXVECTOR3(150,13,50),1.0f);
playerAI[1]->movement(D3DXVECTOR3(150,13,0),1.0f);
playerAI[2]->movement(D3DXVECTOR3(150,13,-50),1.0f);
playerAI[3]->movement(D3DXVECTOR3(80,13,50),1.0f);
playerAI[4]->movement(D3DXVECTOR3(80,13,0),1.0f);
playerAI[5]->movement(D3DXVECTOR3(80,13,-40),1.0f);
playerAI[6]->movement(D3DXVECTOR3(80,13,-80),1.0f);
playerAI[7]->movement(D3DXVECTOR3(50,13,0),1.0f);
playerAI[8]->movement(D3DXVECTOR3(20,13,50),1.0f);
playerAI[9]->movement(D3DXVECTOR3(20,13,10),1.0f);

goal[0]->movement(D3DXVECTOR3(-190,13,0),1.0f);
goal[1]->movement(D3DXVECTOR3(190,13,0),1.0f);
}

void together::movementBall()
{
	
	
										
									if( b->getLocation().x>=0 && b->getLocation().x<=100 && b->getLocation().z>=-50 && b->getLocation().z<=50  )
												{
													b->centrer_(true);
													b->centrerAvant_(false);
													b->centrerArriere_(false);
													b->centrerCoteArriereDroite_(false);
													b->centrerCoteArriereGauche_(false);
													b->centrerCoteDroit_(false);
													b->centrerCoteGauche_(false);
													
												}
												
												
													
													if( b->getLocation().x>=100.0f && b->getLocation().x<=180 && b->getLocation().z>=-50 && b->getLocation().z<=50  )
												{
													b->centrer_(false);
													b->centrerAvant_(true);
													b->centrerArriere_(false);
													b->centrerCoteArriereDroite_(false);
													b->centrerCoteArriereGauche_(false);
													b->centrerCoteDroit_(false);
													b->centrerCoteGauche_(false);
													
												}
												
												
														if( b->getLocation().x>=0 && b->getLocation().x<=180 && b->getLocation().z>=50 && b->getLocation().z<=150  )
												{
													b->centrer_(false);
													b->centrerAvant_(false);
													b->centrerArriere_(false);
													b->centrerCoteArriereDroite_(false);
													b->centrerCoteArriereGauche_(false);
													b->centrerCoteDroit_(true);
													b->centrerCoteGauche_(false);
													
												}
											
													
														if( b->getLocation().x>=0 && b->getLocation().x<=180 && b->getLocation().z>=-150 && b->getLocation().z<=-50  )
												{
														b->centrer_(false);
													b->centrerAvant_(false);
													b->centrerArriere_(false);
													b->centrerCoteArriereDroite_(false);
													b->centrerCoteArriereGauche_(false);
													b->centrerCoteDroit_(false);
													b->centrerCoteGauche_(true);
													
												}
											
											
											
											
											
											
												if( b->getLocation().x>=-100 && b->getLocation().x<=-10 && b->getLocation().z>=-50.5f && b->getLocation().z<=50  )
												{
														b->centrer_(false);
													b->centrerAvant_(false);
													b->centrerArriere_(true);
													b->centrerCoteArriereDroite_(false);
													b->centrerCoteArriereGauche_(false);
													b->centrerCoteDroit_(false);
													b->centrerCoteGauche_(false);
													
												}
												
													
													if( b->getLocation().x>=-150.0f && b->getLocation().x<-40 && b->getLocation().z>=20.5f && b->getLocation().z<=180  )
												{
														b->centrer_(false);
													b->centrerAvant_(false);
													b->centrerArriere_(false);
													b->centrerCoteArriereDroite_(true);
													b->centrerCoteArriereGauche_(false);
													b->centrerCoteDroit_(false);
													b->centrerCoteGauche_(false);
													
												}
												
												
														if( b->getLocation().x>=-150.5f && b->getLocation().x<=-40 && b->getLocation().z<=-20.5f && b->getLocation().z>=-180  )
												{
													b->centrer_(false);
													b->centrerAvant_(false);
													b->centrerArriere_(false);
													b->centrerCoteArriereDroite_(false);
													b->centrerCoteArriereGauche_(true);
													b->centrerCoteDroit_(false);
													b->centrerCoteGauche_(false);
													
												}
											
												
											
											
									
												
											
											
											
												
											
										
}

void together::movement()
{
	
									
									
										for(int i=0;i<10;i++)
											{
											
													
												if(   player[i]->gethastheball()==false && player[i]->getNext()==false
												)
												{
													player[i]->setattaquer(true);
												}
												else
												{
													player[i]->setattaquer(false);
												}
											
											
										
									}
									
										
//centrerarriere
										for(int i=0;i<4;i++)
											{
											if( b->centrerArriere_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										
											 if(player[i]->movement(D3DXVECTOR3 (-180+i,4,-80+(40*i)),1.0f))
											 {
											 	
											 }
										
									}
									
										}
									
									
										for(int i=4;i<6;i++)
											{
										if( b->centrerArriere_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
								
											 if(player[i]->movement(D3DXVECTOR3(-120+i,4,-125+(35*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
											for(int i=6;i<10;i++)
											{
										if( b->centrerArriere_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
									
											 if(player[i]->movement(D3DXVECTOR3(-100+i,4,-255+(40*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
							
									//centrercotearrieredroit
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerCoteArriereDroite_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											 
											 if(player[i]->movement(D3DXVECTOR3(-145+i,4,45+(30*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<6;i++)
											{
										if( b->centrerCoteArriereDroite_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
									
											 if(player[i]->movement(D3DXVECTOR3(-180+i,4,25+(25*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
										for(int i=6;i<10;i++)
											{
										if( b->centrerCoteArriereDroite_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
								
											 if(player[i]->movement(D3DXVECTOR3(-100+i,4,-185+(25*i)),1.0f))
											 {
											 	
											 }
										}
									}
										//centrercotearrieregauche
									
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerCoteArriereGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
								
											 if(player[i]->movement(D3DXVECTOR3(-125+i,4,-115+(25*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
										
									
									
										for(int i=4;i<6;i++)
											{
										if( b->centrerCoteArriereGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										
											 if(player[i]->movement(D3DXVECTOR3(-50+i,4,-85+(25*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
										for(int i=6;i<10;i++)
											{
										if( b->centrerCoteArriereGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
									
											 if(player[i]->movement(D3DXVECTOR3(-20+i,4,-105+(25*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
								
									//centrer
									
											for(int i=0;i<4;i++)
											{
										if( b->centrer_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										
											 if(player[i]->movement(D3DXVECTOR3(-110+i,4,-20+(30*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
										
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrer_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										
											 if(player[i]->movement(D3DXVECTOR3(80+i,4,-130+(30*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
										for(int i=8;i<10;i++)
											{
										if( b->centrer_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
								
											 if(player[i]->movement(D3DXVECTOR3(0+i,4,-180+(30*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
		
									
									//centreravant
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerAvant_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											
											 if(player[i]->movement(D3DXVECTOR3(-125+i,4,-50+(20*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrerAvant_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
							
											 if(player[i]->movement(D3DXVECTOR3(120+i,4,-165+(20*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( b->centrerAvant_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
						 
											 if(player[i]->movement(D3DXVECTOR3(140+i,4,-125+(20*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
									//centrercotedroit
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerCoteDroit_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										
											 if(player[i]->movement(D3DXVECTOR3(-100+i,4,20+(20*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrerCoteDroit_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
								
											 if(player[i]->movement(D3DXVECTOR3(50+i,4,-50+(20*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( b->centrerCoteDroit_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										
											 if(player[i]->movement(D3DXVECTOR3(0+i,4,-100+(20*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
										//centrercotegauche
									
										for(int i=0;i<4;i++)
											{
										if( b->centrerCoteGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										
											 if(player[i]->movement(D3DXVECTOR3(-105+i,4,-125+(20*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( b->centrerCoteGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										 
											 if(player[i]->movement(D3DXVECTOR3(80+i,4,-195+(25*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( b->centrerCoteGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
							
											 if(player[i]->movement(D3DXVECTOR3(140+i,4,-285+(25*i)),1.0f))
											 {
											 	
											 }
										}
									}
									
									
									
									
							
		
									
									
									
}


void together::movementGoal()
{
	goal[0]->movementGoal(b->getLocation(),1.0f);
	goal[1]->movementGoal(b->getLocation(),1.0f);
	
	//goal[0]->tirGoal(b->getLocation(),1.0f);
	//goal[1]->tirGoal(b->getLocation(),-1.0f);
	float d=sqrt(((goal[0]->getLocation().x-b->getLocation().x)*(goal[0]->getLocation().x-b->getLocation().x))
	+((goal[0]->getLocation().y-b->getLocation().y)*(goal[0]->getLocation().y-b->getLocation().y))
	+((goal[0]->getLocation().z-b->getLocation().z)*(goal[0]->getLocation().z-b->getLocation().z)));
	
	if(d<15)
	{
		speedTirGoal=true;
		speedTirGoal2=false;
		speedTirAI=false;
		p->setTir(false);
		rand=randMToN(-2.5f,2.5f);
		rand2=randMToN(3.0f,12.0f);
	
	}
	
	if(speedTirGoal)
	{
	
		b->setLocationIncremente(D3DXVECTOR3(rand2,0,rand));
	
		delay2-=0.002f;
		if(delay2<0)
		  delay2=10;


	
	
	
	
}
		
	if(speedTirGoal && d>15 && delay2<=2)
	{
		speedTirGoal=false;

	}
	

	
	

	
		float d2=sqrt(((goal[1]->getLocation().x-b->getLocation().x)*(goal[1]->getLocation().x-b->getLocation().x))
	+((goal[1]->getLocation().y-b->getLocation().y)*(goal[1]->getLocation().y-b->getLocation().y))
	+((goal[1]->getLocation().z-b->getLocation().z)*(goal[1]->getLocation().z-b->getLocation().z)));
	
		if(d2<15)
	{
		speedTirGoal2=true;
		speedTirGoal=false;
		speedTirAI=false;
		p->setTir(false);
		rand=randMToN(-2.5f,2.5f);
		rand2=randMToN(3.0f,12.0f);
		
	}
		if(speedTirGoal2)
	{
		
		b->setLocationIncremente(D3DXVECTOR3(-rand2,0,rand));

		delay2-=0.002f;
		if(delay2<0)
		  delay2=10;

	
}
	
		
	if(speedTirGoal2 && d2>15 && delay2<=2)
	{
		speedTirGoal2=false;
	
	}
	

	
	
	
	
}

void together::collisionStadePlayer(robot* player)
{
	if(player->getLocation().x>200)
	{
		player->setLocation(D3DXVECTOR3(200,player->getLocation().y,player->getLocation().z));
	}
	if(player->getLocation().x<-200)
	{
		player->setLocation(D3DXVECTOR3(-200,player->getLocation().y,player->getLocation().z));
	}
	
		if(player->getLocation().z>130)
	{
		player->setLocation(D3DXVECTOR3(player->getLocation().x,player->getLocation().y,130));
	}
	if(player->getLocation().z<-130)
	{
		player->setLocation(D3DXVECTOR3(player->getLocation().x,player->getLocation().y,-130));
	}
	
	
		
	
	
}

void together::collisionStadePlayerAI( robot* playerAI)
{
		if(playerAI->getLocation().x>200)
	{
		playerAI->setLocation(D3DXVECTOR3(200,playerAI->getLocation().y,playerAI->getLocation().z));
	}
	if(playerAI->getLocation().x<-200)
	{
		playerAI->setLocation(D3DXVECTOR3(-200,playerAI->getLocation().y,playerAI->getLocation().z));
	}
	
		if(playerAI->getLocation().z>130)
	{
		playerAI->setLocation(D3DXVECTOR3(playerAI->getLocation().x,playerAI->getLocation().y,130));
	}
	if(playerAI->getLocation().z<-130)
	{
		playerAI->setLocation(D3DXVECTOR3(playerAI->getLocation().x,playerAI->getLocation().y,-130));
	}
}

void together::collisionStadeBall(balle* b)
 {
 	
			if(b->getLocation().x>195)
	{
		b->setLocation(D3DXVECTOR3(195,b->getLocation().y,b->getLocation().z));
	}
	if(b->getLocation().x<-195)
	{
		b->setLocation(D3DXVECTOR3(-195,b->getLocation().y,b->getLocation().z));
	}
	
		if(b->getLocation().z>120)
	{
		b->setLocation(D3DXVECTOR3(b->getLocation().x,b->getLocation().y,125));
	}
	if(b->getLocation().z<-120)
	{
		b->setLocation(D3DXVECTOR3(b->getLocation().x,b->getLocation().y,-120));
	}
	
 }

void together::passer(robot* player)
{

	 
	float x,y,z;

   
	float dist=sqrt(((player->getLocation().x-b->getLocation().x)*(player->getLocation().x-b->getLocation().x))
	+((player->getLocation().y-b->getLocation().y)*(player->getLocation().y-b->getLocation().y))
	+((player->getLocation().z-b->getLocation().z)*(player->getLocation().z-b->getLocation().z)));
	
    

	

		if( player->gethastheball()==false && delay<25 && speedTirAI==false)
		{
		
			player->setTirer(false);
			
		
			
		}
	if(player->gethastheball() || player->gethastheball()==false)
	{
			delay-=0.8f;
	}
	//std::cout<<delay<<std::endl;

					if(KEY_DOWN(VK_LCONTROL) && player->gethastheball() )
					{
						
						//z+=sin(player[i]->getRot());
							 controls=false;
						player->setTirer(true);
						
					delay=150;
						 
					//	playerAI[i]->sethastheball(false);
					}
				else if(KEY_DOWN(VK_LCONTROL)==false && delay<25 )
				{
					
					 controls=true;
					 
				
				}
			
			
						
					if(player->getTirer() && player->getRot()==-1.5f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(-speed,0,0));
							
				}
				
						
				else	if(player->getTirer() &&  player->getRot()==1.5f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(speed,0,0));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==0.75f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(-speed,0,-speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==-0.75f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(-speed,0,speed));
							
				}
				
					
					else	if(player->getTirer() &&  player->getRot()==-2.25f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(speed,0,speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==2.25f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(speed,0,-speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==3.0f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(0,0,speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==0.0f)
					{
					
					speed=2.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(0,0,-speed));
							
		
				
			}
						
			
	}
	
	
	void together::tirer(robot* player)
{

	 
	float x,y,z;

   
	float dist=sqrt(((player->getLocation().x-b->getLocation().x)*(player->getLocation().x-b->getLocation().x))
	+((player->getLocation().y-b->getLocation().y)*(player->getLocation().y-b->getLocation().y))
	+((player->getLocation().z-b->getLocation().z)*(player->getLocation().z-b->getLocation().z)));
	
    

	

		if( player->gethastheball()==false && delay<25 && speedTirAI==false)
		{
		
			player->setTirer(false);
			
		
			
		}
	if(player->gethastheball() || player->gethastheball()==false)
	{
			delay-=0.2f;
	}
	//std::cout<<delay<<std::endl;

					if(KEY_DOWN(VK_RCONTROL) && player->gethastheball() )
					{
						
						//z+=sin(player[i]->getRot());
							 controls=false;
						player->setTirer(true);
						
					delay=150;
						 
					//	playerAI[i]->sethastheball(false);
					}
				else if(KEY_DOWN(VK_RCONTROL)==false && delay<25 )
				{
					
					 controls=true;
					 
				
				}
			
			
						
					if(player->getTirer() && player->getRot()==-1.5f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(-speed,0,0));
							
				}
				
						
				else	if(player->getTirer() &&  player->getRot()==1.5f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(speed,0,0));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==0.75f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(-speed,0,-speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==-0.75f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(-speed,0,speed));
							
				}
				
					
					else	if(player->getTirer() &&  player->getRot()==-2.25f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(speed,0,speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==2.25f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(speed,0,-speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==3.0f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(0,0,speed));
							
				}
				
					else	if(player->getTirer() &&  player->getRot()==0.0f)
					{
					
					speed=7.9f;
			
			
					
	  			
	  				
	  						 
					 b->setLocationIncremente(D3DXVECTOR3(0,0,-speed));
							
		
				
			}
						
			
	}
	
	void together::tirerAI(robot* playerAI)
	{

	D3DXVECTOR3 pointTir=D3DXVECTOR3(-120,8,0);
	float dist=sqrt(((playerAI->getLocation().x-pointTir.x)*(playerAI->getLocation().x-pointTir.x))
	+((playerAI->getLocation().y-pointTir.y)*(playerAI->getLocation().y-pointTir.y))
	+((playerAI->getLocation().z-pointTir.z)*(playerAI->getLocation().z-pointTir.z)));
	
	if(playerAI->gethastheball() && dist<35)
	{
		speedTirAI=true;
		playerAI->setTirer(false);
	}
	if(speedTirAI)
	  {
		b->setLocationIncremente(D3DXVECTOR3(-0.99f,0,0));
		delay2-=0.002f;
		if(delay2<0)
		  delay2=10;
	}
	

  
	if(playerAI->gethastheball()==false && delay2<=2 && speedTirAI)
	{
		speedTirAI=false;
	}
		
	}
	
	
	void together::separatePlayer()
{
		
		  D3DXVECTOR3 Distance = D3DXVECTOR3(player[0]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance2 = D3DXVECTOR3(player[1]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance3 = D3DXVECTOR3(player[2]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance4 = D3DXVECTOR3(player[3]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance5 = D3DXVECTOR3(player[4]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance6 = D3DXVECTOR3(player[5]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance7 = D3DXVECTOR3(player[6]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance8 = D3DXVECTOR3(player[7]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance9 = D3DXVECTOR3(player[8]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance10 = D3DXVECTOR3(player[9]->getLocation()-b->getLocation());

float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));

for(int i=0;i<player.size();i++)
{

											if(player[i]->gethastheball()==true && player[0]->gethastheball()==false && hypotenuse<10)
											{
												player[0]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[1]->gethastheball()==false&& hypotenuse2<10)
											{
												player[1]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[2]->gethastheball()==false&& hypotenuse3<10)
											{
												player[2]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[3]->gethastheball()==false&& hypotenuse4<10)
											{
												player[3]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[4]->gethastheball()==false&& hypotenuse5<10)
											{
												player[4]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[5]->gethastheball()==false&& hypotenuse6<10)
											{
												player[5]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[6]->gethastheball()==false&& hypotenuse7<10)
											{
												player[6]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[7]->gethastheball()==false&& hypotenuse8<10)
											{
												player[7]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[8]->gethastheball()==false&& hypotenuse9<10)
											{
												player[8]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(player[i]->gethastheball()==true && player[9]->gethastheball()==false && hypotenuse10<10)
											{
												player[9]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
										}
										
										


}

void together::separatePlayerAI()
{
		D3DXVECTOR3 Distance = D3DXVECTOR3(playerAI[0]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance2 = D3DXVECTOR3(playerAI[1]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance3 = D3DXVECTOR3(playerAI[2]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance4 = D3DXVECTOR3(playerAI[3]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance5 = D3DXVECTOR3(playerAI[4]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance6 = D3DXVECTOR3(playerAI[5]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance7 = D3DXVECTOR3(playerAI[6]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance8 = D3DXVECTOR3(playerAI[7]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance9 = D3DXVECTOR3(playerAI[8]->getLocation()-b->getLocation());
		  D3DXVECTOR3 Distance10 = D3DXVECTOR3(playerAI[9]->getLocation()-b->getLocation());

float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));
	

for(int i=0;i<playerAI.size();i++)
{

											if(playerAI[i]->gethastheball()==true && playerAI[0]->gethastheball()==false && hypotenuse<10)
											{
												playerAI[0]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[1]->gethastheball()==false&& hypotenuse2<10)
											{
												playerAI[1]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[2]->gethastheball()==false&& hypotenuse3<10)
											{
												playerAI[2]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[3]->gethastheball()==false&& hypotenuse4<10)
											{
												playerAI[3]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[4]->gethastheball()==false&& hypotenuse5<10)
											{
												playerAI[4]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[5]->gethastheball()==false&& hypotenuse6<10)
											{
												playerAI[5]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[6]->gethastheball()==false&& hypotenuse7<10)
											{
												playerAI[6]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[7]->gethastheball()==false&& hypotenuse8<10)
											{
												playerAI[7]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[8]->gethastheball()==false&& hypotenuse9<10)
											{
												playerAI[8]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
													if(playerAI[i]->gethastheball()==true && playerAI[9]->gethastheball()==false && hypotenuse10<10)
											{
												playerAI[9]->setLocationincremente(D3DXVECTOR3(-5.5,0,5.5));
											}
										}
										
										


}



void together:: loadCinematik1()
{

	camPos.x-=0.1f;
	
	if(camPos.x<-100)
	 camPos.x=100;
	

}

void together::loadSupporters(LPDIRECT3DDEVICE9 d3ddev)
{
	
	
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(0+(i*10),25,190),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
			
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(0+(i*10),35,205),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(0+(i*10),30,195),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(0+(i*10),50,225),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
			
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(0+(i*10),55,230),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(0+(i*10),60,235),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
	
		
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),110,285),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
			
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),115,290),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),120,295),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),105,280),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),100,275),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<40;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),95,270),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		
		
		
		
		
		
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-100+(i*10),25,-190),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
			
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-100+(i*10),35,-205),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-100+(i*10),30,-195),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-100+(i*10),50,-225),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
			
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-100+(i*10),55,-230),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-100+(i*10),60,-235),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),110,-285),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
			
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),115,-290),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),120,-295),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),105,-280),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),100,-275),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<100;i++)
		support.push_back(new supporter(D3DXVECTOR3(-150+(i*10),95,-270),d3ddev,0.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		
		
		
		
		
			
	
			
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-350,115,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-345,120,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-340,105,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-335,100,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-330,85,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-315,70,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-310,65,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-305,60,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-300,55,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(-295,50,-120+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		
		
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(-285,45,-80+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(-280,40,-80+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(-275,35,-80+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(-270,30,-80+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(-265,25,-80+(i*10)),d3ddev,-90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
	
		
		
		
			
		for(int i=0;i<30;i++)
		support.push_back(new supporter(D3DXVECTOR3(360,115,-120+(i*25)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<30;i++)
		support.push_back(new supporter(D3DXVECTOR3(350,120,-120+(i*25)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<30;i++)
		support.push_back(new supporter(D3DXVECTOR3(340,105,-120+(i*20)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<30;i++)
		support.push_back(new supporter(D3DXVECTOR3(335,100,-120+(i*20)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<30;i++)
		support.push_back(new supporter(D3DXVECTOR3(330,95,-120+(i*20)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
			
		for(int i=0;i<90;i++)
		support.push_back(new supporter(D3DXVECTOR3(325,75,-120+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<90;i++)
		support.push_back(new supporter(D3DXVECTOR3(320,70,-120+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<90;i++)
		support.push_back(new supporter(D3DXVECTOR3(315,65,-120+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(310,60,-120+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<50;i++)
		support.push_back(new supporter(D3DXVECTOR3(305,50,-120+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		
		
			
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(285,45,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(280,40,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(275,35,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(270,30,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));	
	
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(265,25,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
		
		
		
				
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(285,240,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.5f,1.1f,0.9f)));
		
				
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(280,235,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.25f,1.1f,0.29f)));
		
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(275,230,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.25f,1.1f,0.29f)));
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(270,225,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.25f,1.1f,0.29f)));	
	
		
		for(int i=0;i<20;i++)
		support.push_back(new supporter(D3DXVECTOR3(265,215,-80+(i*10)),d3ddev,90.0f,D3DXVECTOR3(0.25f,1.1f,0.29f)));
	
	
}

