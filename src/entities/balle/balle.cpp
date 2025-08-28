 #include"balle.hpp"
 
 	balle::	balle(LPDIRECT3DDEVICE9 d3ddev)
	{
		
	init(d3ddev);
	position=D3DXVECTOR3(0,15,0);
	gravity=2.0f;
	}
	
	balle::~balle()
		{
			meshSpaceship->Release();    // close and release the spaceship mesh

		    d3d->Release();    // close and release Direct3D
		}
		
	void balle::init(LPDIRECT3DDEVICE9 d3ddev)
		{
			 LPD3DXBUFFER bufShipMaterial;

	
    D3DXLoadMeshFromX("data/balle.x",    // load this file
                      D3DXMESH_SYSTEMMEM,    // load the mesh into system memory
                      d3ddev,    // the Direct3D Device
                      NULL,    // we aren't using adjacency
                      &bufShipMaterial,    // put the materials here
                      NULL,    // we aren't using effect instances
                      &numMaterials,    // the number of materials in this model
                      &meshSpaceship);    // put the mesh here

    // retrieve the pointer to the buffer containing the material information
    D3DXMATERIAL* tempMaterials = (D3DXMATERIAL*)bufShipMaterial->GetBufferPointer();

    // create a new material buffer for each material in the mesh
    material = new D3DMATERIAL9[numMaterials];
	texture = new LPDIRECT3DTEXTURE9[numMaterials];
	 for(DWORD i = 0; i < numMaterials; i++)    // for each material...
    {
	 std::string str=std::string("data/")+tempMaterials[i].pTextureFilename;

   
        material[i] = tempMaterials[i].MatD3D;    // get the material info
        material[i].Ambient = material[i].Diffuse;    // make ambient the same as diffuse
        if(FAILED(D3DXCreateTextureFromFileA(d3ddev,
                                         str.c_str(),
                                         &texture[i])))
        texture[i] = NULL;    // if there is no texture, set the texture to NULL
    
}
		}
		
	void balle::update(){
		float deltaTime=.25f;
		  position += velocity * deltaTime;

    // Appliquer un ralentissement progressif (friction)
    velocity *= 0.98f; // tu peux ajuster ce facteur (proche de 1.0) selon ton besoin

    // Si la vitesse est tr�s faible, on l'arr�te compl�tement

    
			position.y-=gravity;
			if(position.y<8)
			  position.y=8;
		}
		
	void balle::draw(LPDIRECT3DDEVICE9 d3ddev)
		{
		

    static float index = 0.0f; index+=0.03f;    // an ever-increasing float value
    D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle
    D3DXMatrixTranslation(&matTranslateFinal, position.x, position.y, position.z);
    D3DXMatrixRotationY(&matRotateY, index);    // the rotation matrix
    D3DXMatrixScaling(&matScale, 10.0f, 10.0f, 10.0f);
    D3DXMATRIX matTemp(matScale*matTranslateFinal);
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);    // set the world transform


    // draw the spaceship
    for(DWORD i = 0; i < numMaterials; i++)    // loop through each subset
    {
        d3ddev->SetMaterial(&material[i]);    // set the material for the subset
        if(texture[i] != NULL)    // if the subset has a texture (if texture is not NULL)
        d3ddev->SetTexture(0, texture[i]);    // ...then set the texture
        
        meshSpaceship->DrawSubset(i);    // draw the subset
    }
    
   
  

    d3ddev->Present(NULL, NULL, NULL, NULL);
		}
		
		D3DXVECTOR3 balle::getLocation()
		{
			return position;
		}
		void balle::setLocation(D3DXVECTOR3 l)
		{
			position=l;
		}
		
		void balle::setLocationIncremente(D3DXVECTOR3 l)
		{
		position+=l;	
		}
		
		  void balle::setVelocity(const D3DXVECTOR3& vel) 
		  { 
		  velocity = vel;
		   }
		  
		  
		void balle::setLocationIncremente(float deltaTime)
		{
			position+=velocity;
			velocity *= 0.98f; // par exemple pour ralentir doucement
		}
		bool balle::centrer_()
		 	{
		 		return centrer;
			 }
		bool balle::centrerAvant_()
		{
			return centreravant;
		}
		bool balle::centrerArriere_()
		{
			return centrerarriere;
		}
		bool balle::centrerCoteArriereGauche_()
		{
		
		return centrercotearrieregauche;
	}
	
		bool balle::centrerCoteArriereDroite_()
		{
		return centrercotearrieredroit;
		}
		bool balle::centrerCoteGauche_()
		{
		return centrercotegauche;
		}
		bool balle::centrerCoteDroit_()
		{
			return centrercotedroit;
		}
		
			void balle::centrer_(bool c)
		 	{
		 	 centrer=c;
			 }
	void balle::centrerAvant_(bool c)
		{
		 centreravant=c;
		}
		void balle::centrerArriere_(bool c)
		{
		centrerarriere=c;
		}
			void balle::centrerCoteArriereGauche_(bool c)
		{
		
		 centrercotearrieregauche=c;
	}
	
			void balle::centrerCoteArriereDroite_(bool c)
		{
		 centrercotearrieredroit=c;
		}
		void balle::centrerCoteGauche_(bool c)
		{
		centrercotegauche=c;
		}
		void balle::centrerCoteDroit_(bool c)
		{
		 centrercotedroit=c;
		}
		
		void balle::setGravity(float s)
		{
			 gravity=s;
		}
