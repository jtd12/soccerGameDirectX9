#include"zones.hpp"

		zone::zone(D3DXVECTOR3 p,LPDIRECT3DDEVICE9 d3ddev)
		{
			position=p;
			init_graphics(d3ddev);
		}
		
		zone::~zone()
		{
			meshSpaceship->Release();    // close and release the spaceship mesh

		    d3d->Release();    // close and release Direct3D
		}
		
		void zone::init_graphics(	LPDIRECT3DDEVICE9 d3ddev)
		{
	LPD3DXBUFFER bufShipMaterial;

	
    D3DXLoadMeshFromX("data/zones.x",    // load this file
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

	 for(DWORD i = 0; i < numMaterials; i++)    // for each material...
    {
	 
        material[i] = tempMaterials[i].MatD3D;    // get the material info
        material[i].Ambient = material[i].Diffuse;    // make ambient the same as diffuse
       
		}
	}
	
		void zone::update(D3DXVECTOR3 translation)
		{
			
		}
		
		void zone::draw(	LPDIRECT3DDEVICE9 d3ddev)
		{
			
	static float index = 0.0f; index+=0.03f;    // an ever-increasing float value
    D3DXMatrixTranslation(&matTranslateA, position.x, position.y, position.z);
    D3DXMatrixScaling(&matScale, 1.02f, 1.02f, 1.02f);
    D3DMATRIX matTemp(matTranslateA *matScale);
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);    // set the world transform


    // draw the spaceship
    for(DWORD i = 0; i < numMaterials; i++)    // loop through each subset
    {
        d3ddev->SetMaterial(&material[i]);    // set the material for the subset
  
        
        meshSpaceship->DrawSubset(i);    // draw the subset
    }

   

    d3ddev->Present(NULL, NULL, NULL, NULL);
		}
		
