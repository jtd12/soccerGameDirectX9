#ifndef DEF_DECOR_HPP
#define DEF_DECOR_HPP
#include <windows.h>
#include <windowsx.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <cstring>
#include <cwchar>
#include <stdexcept>
#include <string>
#include <cwchar>
#include <stdexcept>
#include <string>

class decor
{
	
	public:
		
		decor(LPDIRECT3DDEVICE9 d3ddev,const char * file);
		~decor();
		void init(const char * file,LPDIRECT3DDEVICE9 d3ddev);
		void update();
		void draw(LPDIRECT3DDEVICE9 d3ddev);
		
	private:
		
		LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
		LPDIRECT3DSURFACE9 z_buffer = NULL;    // the pointer to the z-buffer
		LPD3DXMESH meshSpaceship;    // define the mesh pointer
		D3DMATERIAL9* material;    // define the material object
		DWORD numMaterials;    // stores the number of materials in the mesh
		D3DXMATRIX matScale; 
		LPDIRECT3DTEXTURE9* texture;    // a pointer to a texture
};

#endif
