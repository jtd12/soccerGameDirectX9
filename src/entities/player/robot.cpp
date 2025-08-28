#include"robot.hpp"

robot::robot(D3DXVECTOR3 pos,LPDIRECT3DDEVICE9 d3ddev,float r,D3DXVECTOR3 col)
{

	init_graphics(d3ddev);
	rot=r;
	color=col;
	position=pos;
	speed=1.5f;
}

robot::~robot()
{

vertexbuffer->Release();
vertexbuffer=NULL;
i_buffer->Release();
i_buffer=NULL;
}


void robot::init_graphics(	LPDIRECT3DDEVICE9 d3ddev)
{

 CUSTOMVERTEX vertices[] =
    {
    	
    {-3.0f, -3.0f, 3.0f, 0.0f, 0.0f, 1.0f,D3DCOLOR_XRGB(250, 250, 220),}, // côté 1 
        {3.0f, -3.0f, 3.0f, 0.0f, 0.0f, 1.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        {-3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 1.0f,D3DCOLOR_XRGB(250, 250,220),}, 
        {3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 1.0f,D3DCOLOR_XRGB(250, 250, 220),}, 

        {-3.0f, -3.0f, -3.0f, 0.0f, 0.0f, -1.0f,D3DCOLOR_XRGB(250, 250, 220),}, // côté 2 
        {-3.0f, 3.0f, -3.0f, 0.0f, 0.0f, -1.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        {3.0f, -3.0f, -3.0f, 0.0f, 0.0f, -1.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        {3.0f, 3.0f, -3.0f, 0.0f, 0.0f, -1.0f,D3DCOLOR_XRGB(250, 250, 220),}, 

        {-3.0f, 3.0f , -3.0f, 0.0f, 1.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, // face 3 
        {-3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f,D3DCOLOR_XRGB(250, 250,220),}, 
        {3.0f, 3.0f, - 3.0f, 0.0f, 1.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        {3.0f, 3.0f, 3.0f, 0.0f, 1.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),},

        {-3.0f, -3.0f, -3.0f, 0.0f, -1.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, // côté 4 
        {3.0f, -3.0f, -3.0f, 0.0f, -1.0f, 0.0f ,D3DCOLOR_XRGB(250, 250, 220),}, 
        {-3.0f, -3.0f, 3.0f, 0.0f, -1.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        {3.0f, -3.0f, 3.0f, 0.0f, -1.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, 

        {3.0f, -3.0f, -3.0f, 1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, // côté 5 
        {3.0f, 3.0f, -3.0f, 1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        { 3.0f, -3.0f, 3.0f, 1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250,220),}, 
        {3.0f, 3.0f, 3.0f, 1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, 

        {-3.0f, -3.0f , -3.0f, -1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, // côté 6 
        {-3.0f, -3.0f, 3.0f, -1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        {-3.0f, 3.0f, -3.0f, -1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),}, 
        {-3.0f, 3.0f, 3.0f, -1.0f, 0.0f, 0.0f,D3DCOLOR_XRGB(250, 250, 220),},
        
       
                
    };

    // create a vertex buffer interface called v_buffer
    d3ddev->CreateVertexBuffer(24  * sizeof(CUSTOMVERTEX), 0, CUSTOMFVF, D3DPOOL_MANAGED, &vertexbuffer, NULL);
  
	
    VOID* pVoid;

    // lock v_buffer and load the vertices into it
    vertexbuffer->Lock(0, 0, (void**)&pVoid, 0);
    memcpy(pVoid, vertices, sizeof(vertices));
    vertexbuffer->Unlock();
      courts indices [] = 
    { 
        0, 1, 2, // côté 1 
        2, 1, 3,
        4, 5, 6, // côté 2 
        6, 5, 7, 
        8, 9, 10, // côté 3 
        10, 9, 11, 
        12, 13, 14, // côté 4 
        14, 13, 15, 
        16, 17, 18, // face 5 
        18, 17, 19, 
        20, 21, 22, // face 6 
        22, 21, 23,
    }; 

    // crée une interface de tampon d'index appelée i_buffer 
    d3ddev-> CreateIndexBuffer (36 * sizeof (short), 
                              0, 
                              D3DFMT_INDEX16, 
                              D3DPOOL_MANAGED, 
                              & i_buffer, 
                              NULL); 

    // verrouille i_buffer et charge les index dedans
    i_buffer-> Lock (0, 0, (void **) & pVoid, 0); 
    memcpy (pVoid, indices, sizeof (indices)); 
    i_buffer-> Unlock (); 

}

bool robot::movement(D3DXVECTOR3 playerLoc,float speedDir)
{
		   	D3DXVECTOR3 u=D3DXVECTOR3(playerLoc.x, playerLoc.y, playerLoc.z);
		   	D3DXVECTOR3 v=D3DXVECTOR3(position.x-playerLoc.x, position.y-playerLoc.y, position.z-playerLoc.z);
		   	D3DXVECTOR3* direction;
	
    		
			D3DXVECTOR3 newpos(position);
			
			direction=D3DXVec3Normalize(&u,&v);
		
			newpos.y-=0.005f;
			
			if(newpos.y<=13.5f)
			{ 
			newpos.y=13.5f;
			}
			newpos.x-=direction->x*0.7f*speed;
			newpos.y-=direction->y*0.7f*speed;
			newpos.z-=direction->z*0.7f*speed;
			
			setLocation(newpos);
			  

			 	  	rot=acos(direction->z*speedDir);
		
				   
				   	if(direction->z<0 )
			 	  {
			 	  	rot=-rot;
				   }

}

void robot::movementGoal(D3DXVECTOR3 balleLoc,float speedDir)
{
			D3DXVECTOR3 u=D3DXVECTOR3(balleLoc.x, balleLoc.y, balleLoc.z);
		   	D3DXVECTOR3 v=D3DXVECTOR3(position.x-balleLoc.x, position.y-balleLoc.y, position.z-balleLoc.z);
		   	D3DXVECTOR3* direction;
		   	
		   	direction=D3DXVec3Normalize(&u,&v);
		   	
			rot=acos(direction->z*speedDir);
			 	
			 	if(direction->z>0)
			 	  {
			 	  	rot=-rot;
				   }
				   
			position.z=balleLoc.z;
			if(position.z>40)
			  position.z=40;
			else if(position.z<-40)
			  position.z=-40;
}

void robot::tirGoal(D3DXVECTOR3 ballLoc,float speed)
{
	float d=sqrt(((getLocation().x-ballLoc.x)*(getLocation().x-ballLoc.x))
	+((getLocation().y-ballLoc.y)*(getLocation().y-ballLoc.y))
	+((getLocation().z-ballLoc.z)*(getLocation().z-ballLoc.z)));
	
	if(d<8)
	{
		ballLoc+=D3DXVECTOR3(20*speed,0,0);
	}
}


		
void robot::update(D3DXVECTOR3 translation)
{
	position+=translation*speed;
}

void robot::update()
{
	setRotBrasInc(0.025f);
}

void robot::setRotBrasInc(float r)
{
	rotX2+=r;
	if(rotX2>0.75f)
	  rotX2=-0.2f;
	  
	rotX-=r;
	if(rotX<-0.75f)
	  rotX=0.2f;
}




void robot::render(	LPDIRECT3DDEVICE9 d3ddev) {


    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

  
	
	
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer); 
    // select the vertex buffer to display
    d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
   
	
	
    static float index = 0.0f; index+=0.05f; // an ever-increasing float value
	D3DXMatrixTranslation(&matTranslateFinal, position.x, position.y, position.z);	
    // build MULTIPLE matrices to translate the model and one to rotate
    D3DXMatrixTranslation(&matTranslateA, 0.0f, -1.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateB, 0.0f, 10.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateC, -15.0f, -2.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateD, 15.0f, -2.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateE, -5.0f, -6.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateF, 5.0f, -6.0f, 0.0f);
    
    D3DXMatrixRotationY(&matRotateY, rot);    // the front side
    D3DXMatrixRotationX(&matRotateX, rotX);    // the front side
    D3DXMatrixRotationX(&matRotateX2, rotX2);    // the front side
    
    D3DXMatrixScaling(&matScale, 2.0f, 2.0f, 1.0f);
    D3DXMatrixScaling(&matScaleFinal, 0.15f, 0.15f, 0.15f);
	D3DXMatrixScaling(&matScaleB, 1.0f, 4.5f, 1.0f);
		 
    // tell Direct3D about each world transform, and then draw another triangle
    D3DMATRIX matTemp(matTranslateA *matScale*matRotateY*matScaleFinal*matTranslateFinal);
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
	ZeroMemory(&mat,sizeof(D3DMATERIAL9));
    mat.Diffuse.r = 0.1f;
	mat.Diffuse.g = 2.5f;
	mat.Diffuse.b = 2.5f;
	mat.Diffuse.a = 1.0f;

	// Set the RGBA for ambient reflection.


    HRESULT hr;
	hr = d3ddev->SetMaterial(&mat);

 	d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);

	matTemp = matTranslateB*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
	ZeroMemory(&mat2,sizeof(D3DMATERIAL9));
    mat2.Diffuse.r = color.x;
	mat2.Diffuse.g = color.y;
	mat2.Diffuse.b = color.z;
	mat2.Diffuse.a = 1.0f;

	// Set the RGBA for ambient reflection.


    HRESULT hr2;
	hr2 = d3ddev->SetMaterial(&mat2);
d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
    
	 	matTemp = matTranslateC*matScaleB*matRotateX*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);



	 	matTemp = matTranslateD*matScaleB*matRotateX2*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);

	matTemp = matTranslateE*matScaleB*matRotateX2*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
   d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
	
d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);

matTemp = matTranslateF*matScaleB*matRotateX*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
  
}

void robot::setRotate(float r)
{
	rot+=r;
}
float robot::getRot()
{
	return rot;
}
void robot::setRot(float r)
{
	rot=r;
}
void robot::setLocation(D3DXVECTOR3 pos)
{
	position=pos;
}
void robot::setLocationincremente(D3DXVECTOR3 pos)
{
	position+=pos*speed;
}
D3DXVECTOR3 robot::getLocation()
{
	return position;
}
void robot::setNext(bool s)
{
	next=s;

}
bool robot::getNext()
{
	return next;
}
bool robot::getTirer()
 {
 	return tirer;
 }
 void robot::setTirer(bool t)
 {
 	tirer=t;
 }


		void robot::sethastheball(bool has)
		{
			hastheball=has;
		}
		bool robot::gethastheball()
		{
			return hastheball;
		}
			 void robot::setattaquer(bool x)
		 {
		 	attaquer_=x;
		 }
		 	 void robot::setdefendre(bool x)
		 {
		 	defendre_=x;
		 }
		 bool robot::getattaquer()
		 {
		 	return attaquer_;
		 }
		 	 bool robot::getdefendre()
		 {
		 	return defendre_;
		 }
		 float robot::getSpeed()
		 {
		 	return speed;
		 }
		 void robot::setSpeed(float s)
		 {
		 	speed=s;
		 }
		 

