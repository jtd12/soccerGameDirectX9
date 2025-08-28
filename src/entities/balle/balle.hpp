#ifndef DEF_BALLE_HPP
#define DEF_BALLE_HPP
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

class balle
{
	public:
		balle(LPDIRECT3DDEVICE9 d3ddev);
		~balle();
		void init(LPDIRECT3DDEVICE9 d3ddev);
		void update();
		void draw(LPDIRECT3DDEVICE9 d3ddev);
		void setLocationIncremente(float deltaTime);
		void setLocationIncremente(D3DXVECTOR3 l);
		void setVelocity(const D3DXVECTOR3& vel);
		D3DXVECTOR3 getLocation();
		void setLocation(D3DXVECTOR3 l);
		bool centrer_();
		bool centrerAvant_();
		bool centrerArriere_();
		bool centrerCoteArriereGauche_();
		bool centrerCoteArriereDroite_();
		bool centrerCoteGauche_();
		bool centrerCoteDroit_();
		void centrer_(bool c);
		void  centrerAvant_(bool c);
		void  centrerArriere_(bool c);
		void  centrerCoteArriereGauche_(bool c);
		void  centrerCoteArriereDroite_(bool c);
		void  centrerCoteGauche_(bool c);
		void  centrerCoteDroit_(bool c);
		void setGravity(float s);
		
	private:
		LPDIRECT3D9 d3d;    // the pointer to our Direct3D interface
		LPDIRECT3DSURFACE9 z_buffer = NULL;    // the pointer to the z-buffer
		LPD3DXMESH meshSpaceship;    // define the mesh pointer
		D3DMATERIAL9* material;    // define the material object
		DWORD numMaterials;    // stores the number of materials in the mesh
		D3DXMATRIX matScale; 
		D3DXMATRIX matTranslateFinal; 
		D3DXVECTOR3 position;
		D3DXVECTOR3 velocity;
		float gravity;
		LPDIRECT3DTEXTURE9* texture;    // a pointer to a texture
		bool centrer,centreravant,centrercotedroit,centrercotegauche,centrerarriere,centrercotearrieredroit,centrercotearrieregauche;
};

#endif
