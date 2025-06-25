#include"skybox.hpp"
	sky::sky(LPDIRECT3DDEVICE9 d3ddev)
	{
	init(d3ddev);
	}
	
	sky::~sky()
		{
			meshSpaceship->Release();    // close and release the spaceship mesh

		    d3d->Release();    // close and release Direct3D
		}
		
	void sky::init(LPDIRECT3DDEVICE9 d3ddev)
		{
			 LPD3DXBUFFER bufShipMaterial;

	
    D3DXLoadMeshFromX("data/skybox.x",    // load this file
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
		
	void sky::update(){
			rot+=0.0005f;
		}
		
	void sky::draw(LPDIRECT3DDEVICE9 d3ddev)
		{
		
    D3DXMATRIX matRotateY;    // a matrix to store the rotation for each triangle
    D3DXMatrixRotationY(&matRotateY, rot);    // the rotation matrix
    D3DXMatrixScaling(&matScale, 4.02f, 4.02f, 4.02f);
    D3DMATRIX matTemp(matScale*matRotateY);
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
