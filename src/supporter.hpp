#ifndef DEF_SUPPORTER_HPP
#define DEF_SUPPORTER_HPP
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#define CUSTOMFVF (D3DFVF_XYZ | D3DFVF_NORMAL)

class supporter
 {
 	
 	public:	
 		supporter(D3DXVECTOR3 pos,LPDIRECT3DDEVICE9 d3ddev,float r,D3DXVECTOR3 col);
 		~supporter();
 		void init_graphics(	LPDIRECT3DDEVICE9 d3ddev);
 		void update();
 		void render(LPDIRECT3DDEVICE9 d3ddev);
 		
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
	    D3DXMATRIX matRotateY,matRotateBras;    // a matrix to store the rotation for each triangle	
		D3DMATERIAL9 mat,mat2;	
		D3DXVECTOR3 position;
		D3DXVECTOR3 color;
		float rot,rot_bras;	
 };
 
 #endif
