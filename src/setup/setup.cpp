#include"setup.h"

setup::setup()
{
	
}

void setup::init_graphics(HWND hwnd)
{
		
	p=new together(d3ddev, hwnd);
	
}
setup::~setup()
{
	
if(d3d)
{

    d3d->Release();			// close and release Direct3D
    d3d=NULL;
}
if(d3ddev)
{
	  d3ddev->Release();		// close and release the 3D device
	  d3ddev=NULL;
}

delete p;

}
void setup::initD3D(HWND hwnd,bool windowed) {
    d3d = Direct3DCreate9(D3D_SDK_VERSION);

    D3DPRESENT_PARAMETERS d3dpp;

    ZeroMemory(&d3dpp, sizeof(d3dpp));
    
    d3dpp.Windowed 					= windowed;
    d3dpp.SwapEffect 				= D3DSWAPEFFECT_DISCARD;
    d3dpp.hDeviceWindow 			= hwnd;
    d3dpp.BackBufferFormat	 		= D3DFMT_X8R8G8B8;
    d3dpp.BackBufferWidth 			= SCREEN_WIDTH;
    d3dpp.BackBufferHeight 			= SCREEN_HEIGHT;
    d3dpp.EnableAutoDepthStencil 	= true;        // Manage SetDepthStencil for us
    d3dpp.AutoDepthStencilFormat 	= D3DFMT_D16;	// 16-bit pixel format for the z-buffer

    // create a device class using this information and the info from the d3dpp stuct
    d3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_MIXED_VERTEXPROCESSING, &d3dpp, &d3ddev);

	// Create resources
   

    d3ddev->SetRenderState(D3DRS_LIGHTING, true);    		// turn off the 3D lighting
   // d3ddev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);	// both sides of the triangles
    d3ddev->SetRenderState(D3DRS_ZENABLE,  true);			// turn on the z-buffer
    d3ddev->SetRenderState(D3DRS_AMBIENT,D3DCOLOR_XRGB(110,120,120));
    
    
    D3DXCreateFontW(d3ddev,    // the D3D Device
                   30,    // font height of 30
                   0,    // default font width
                   FW_NORMAL,    // font weight
                   1,    // not using MipLevels
                   true,    // italic font
                   DEFAULT_CHARSET,    // default character set
                   OUT_DEFAULT_PRECIS,    // default OutputPrecision,
                   DEFAULT_QUALITY,    // default Quality
                   DEFAULT_PITCH | FF_DONTCARE,    // default pitch and family
                   L"Arial",    // use Facename Arial
                   &dxfont);    // the font object

    
    
}

void setup::Clear(D3DCOLOR color)
{
	  d3ddev->Clear(0, NULL, D3DCLEAR_TARGET,  color, 1.0f, 0);
    d3ddev->Clear(0, NULL, D3DCLEAR_ZBUFFER, color, 1.0f, 0);
}
void setup::begin()
{
	
    d3ddev->BeginScene();
}
void setup::end()
{
	   d3ddev->EndScene();
}
void setup::present()
{
	  d3ddev->Present(NULL, NULL, NULL, NULL);
}
void setup::init_Light()
{
	
 
	D3DLIGHT9 light;
	 D3DMATERIAL9 material;
	ZeroMemory(&light,sizeof(light));
	light.Type=D3DLIGHT_DIRECTIONAL;
	light.Diffuse=D3DXCOLOR(70.9,70.9,10.0,1.0);
	light.Direction=D3DXVECTOR3(-5.0,800.0,2500.0);
	d3ddev->SetLight(0,&light);
	d3ddev->LightEnable(0,true);
	ZeroMemory(&material,sizeof(D3DMATERIAL9));
	material.Diffuse=D3DXCOLOR(20.9,20.9,20.0,1.0);
	material.Ambient=D3DXCOLOR(1.0,1.0,1.0,1.0);
	d3ddev->SetMaterial(&material);
	d3ddev->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(100, 100, 100));
	
	D3DLIGHT9 light2;
	 D3DMATERIAL9 material2;
	ZeroMemory(&light2,sizeof(light2));
	light2.Type=D3DLIGHT_DIRECTIONAL;
	light2.Diffuse=D3DXCOLOR(1.9,1.9,1.0,1.0);
	light2.Direction=D3DXVECTOR3(-5.0,-850.0,-250.0);
	d3ddev->SetLight(1,&light2);
	d3ddev->LightEnable(1,true);
	ZeroMemory(&material,sizeof(D3DMATERIAL9));
	material2.Diffuse=D3DXCOLOR(20.9,20.9,20.0,1.0);
	material2.Ambient=D3DXCOLOR(1.0,1.0,1.0,1.0);
	d3ddev->SetMaterial(&material2);
	d3ddev->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(120, 120, 120));

	
}


void setup::update()
{

p->update(d3ddev);
/*
for(int i=0;i<player.size();i++)
	   player[i]->setRotate(0.05f);
	   
for(int i=0;i<playerAI.size();i++)
	   playerAI[i]->setRotate(0.05f);
	   */	
}


void setup::render_frame()
{

	p->draw(d3ddev,dxfont);
	
}



