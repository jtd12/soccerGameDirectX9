#include"supporter.hpp"
supporter::supporter(D3DXVECTOR3 pos,LPDIRECT3DDEVICE9 d3ddev,float r,D3DXVECTOR3 col)
{

	init_graphics(d3ddev);
	color=col;
	position=pos;
	rot=r;
}

supporter::~supporter()
{

vertexbuffer->Release();
vertexbuffer=NULL;
i_buffer->Release();
i_buffer=NULL;
}
void supporter::init_graphics(	LPDIRECT3DDEVICE9 d3ddev)
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


void supporter::update()
{
	rot_bras+=0.01f;
	if(rot_bras>2.5f)
	 rot_bras=0.1f;
	
	 
}
void supporter::render(	LPDIRECT3DDEVICE9 d3ddev) {


    // select which vertex format we are using
    d3ddev->SetFVF(CUSTOMFVF);

  
	
	
	d3ddev->SetStreamSource(0, vertexbuffer, 0, sizeof(CUSTOMVERTEX));
	d3ddev-> SetIndices (i_buffer); 
    // select the vertex buffer to display
    d3ddev->SetRenderState(D3DRS_FILLMODE,D3DFILL_SOLID);
   
	
	D3DXMatrixTranslation(&matTranslateFinal, position.x, position.y, position.z);	
    // build MULTIPLE matrices to translate the model and one to rotate
    D3DXMatrixTranslation(&matTranslateA, 0.0f, -1.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateB, 0.0f, 10.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateC, -15.0f, -2.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateD, 15.0f, -2.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateE, -5.0f, -6.0f, 0.0f);
    D3DXMatrixTranslation(&matTranslateF, 5.0f, -6.0f, 0.0f);
    
    D3DXMatrixRotationY(&matRotateY, rot);    // the front side
    D3DXMatrixRotationX(&matRotateBras, rot_bras);    // the front side
    D3DXMatrixScaling(&matScale, 2.0f, 2.0f, 1.0f);
    D3DXMatrixScaling(&matScaleFinal, 0.35f, 0.35f, 0.35f);
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
    
	 	matTemp = matTranslateC*matScaleB*matRotateBras*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);



	 	matTemp = matTranslateD*matScaleB*matRotateBras*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);

	matTemp = matTranslateE*matScaleB*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
   d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    
	
d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);

matTemp = matTranslateF*matScaleB*matRotateY*matScaleFinal*matTranslateFinal;
    d3ddev->SetTransform(D3DTS_WORLD, &matTemp);
    

d3ddev-> DrawIndexedPrimitive (D3DPT_TRIANGLELIST, 0, 0, 24, 0, 12);
  
}

