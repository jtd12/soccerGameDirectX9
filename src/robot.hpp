#ifndef DEF_ROBOT_HPP
#define DEF_ROBOT_HPP
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL)




class robot
{
	public:
		
		robot(D3DXVECTOR3 pos,LPDIRECT3DDEVICE9 d3ddev,float r,D3DXVECTOR3 col);
		~robot();
		void init_graphics(	LPDIRECT3DDEVICE9 d3ddev);
		void update(D3DXVECTOR3 translation);
		void setRotate(float r);
		void setLocation(D3DXVECTOR3 pos);
		bool movement(D3DXVECTOR3 playerLoc,float speedDir);
		void render(	LPDIRECT3DDEVICE9 d3ddev);
		D3DXVECTOR3 getLocation();
		void setLocationincremente(D3DXVECTOR3 pos);
		void movementGoal(D3DXVECTOR3 balleLoc,float speedDir);
		void setNext(bool s);
		bool getNext();
		void setTirer(bool t);
		bool getTirer();
		void sethastheball(bool has);
		bool gethastheball();
		void setattaquer(bool x);
		void setdefendre(bool x);
		bool getattaquer();
		bool getdefendre();
		float getRot();
    	void setRot(float r);
    	void setRotBrasInc(float r);
    	void setRotBras(float r);
    	void  update();
    	float getSpeed();
    	void setSpeed(float s);
    	void tirGoal(D3DXVECTOR3 ballLoc,float speed);
	struct CUSTOMVERTEX {
		float X;
		float Y;
		float Z;
		D3DVECTOR normal;
		DWORD COLOR;
	};
	
	struct courts {
	short int x;
	
	};
		
	private:
		
		LPDIRECT3DVERTEXBUFFER9 vertexbuffer = NULL;	// the pointer to the vertex buffer
						// the pointer to the device class
		LPDIRECT3DINDEXBUFFER9 i_buffer = NULL;	
		D3DXMATRIX matTranslateFinal;  
	    D3DXMATRIX matTranslateA;    // a matrix to store the translation for triangle A
	    D3DXMATRIX matTranslateB;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matTranslateC;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matTranslateD;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matTranslateE;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matTranslateF;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matScale;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matScaleB;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matScaleFinal;    // a matrix to store the translation for triangle B
	    D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle	
	    D3DXMATRIX matRotateX;    // a matrix to store the rotation for each triangle
	    D3DXMATRIX matRotateX2;    // a matrix to store the rotation for each triangle
		D3DMATERIAL9 mat,mat2;	
		D3DXVECTOR3 position;
		D3DXVECTOR3 color;
		float rot;	
		float rotX;
		float rotX2;
		bool next;
		bool hastheball;
		bool attaquer_,defendre_;
		bool tirer;	
		float speed;	
};

#endif
