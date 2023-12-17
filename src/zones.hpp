#ifndef DEF_ZONES_HPP
#define DEF_ZONES_HPP
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

class zone
{
	public:
		
		zone(D3DXVECTOR3 p,LPDIRECT3DDEVICE9 d3ddev);
		~zone();
		void init_graphics(	LPDIRECT3DDEVICE9 d3ddev);
		void update(D3DXVECTOR3 translation);
		void draw(	LPDIRECT3DDEVICE9 d3ddev);
	
	private:
		LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
		LPDIRECT3DSURFACE9 z_buffer = NULL;    // the pointer to the z-buffer
		LPD3DXMESH meshSpaceship;    // define the mesh pointer
		D3DMATERIAL9* material;    // define the material object
		DWORD numMaterials;    // stores the number of materials in the mesh
		D3DXMATRIX matScale; 
		LPDIRECT3DTEXTURE9* texture;    // a pointer to a texture
		D3DXMATRIX matTranslateA;    // a matrix to store the translation for triangle A
		D3DXVECTOR3 position;
};

#endif
