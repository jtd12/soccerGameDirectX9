#include<windows.h>
#include"setup.h"

bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int width, int height,HWND& hwnd);
bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd);
 LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
 void update(setup * game,float gameTime);
 void draw(setup * game,float gameTime);
 
 int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
 HWND hwnd;
 	if(Generatewindow(hInstance,nCmdShow,"api window directX","soccer game directx9!",10,10,960,540,hwnd))
 	{
 		  MSG msg;
 		 setup * game=new setup();
 		 game->initD3D( hwnd,true);
 		 game->init_graphics();
 		 game->init_Light();
 		    while(true) {
        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        if(msg.message==WM_QUIT) break;
        else
        {
       	update(game,0.0f);
        draw(game,0.0f);
		}
	}
	 delete game;
	 return msg.wParam;
	 
}
	 return 0;
 }
 bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle, int width, int height,HWND& hwnd)
 {
 	return Generatewindow(hInstance,nCmdShow,className,windowTitle,(GetSystemMetrics(SM_CXSCREEN)-width)/2,(GetSystemMetrics(SM_CXSCREEN)-height)/2,width, height, hwnd);
 }
 bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd)
 {

   WNDCLASSEX wc;
    //memset(&wc,0,sizeof(wc));
    ZeroMemory(&wc,sizeof(WNDCLASSEX));
	wc.cbSize		 = sizeof(wc);
	wc.style=CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc	 = WindowProc;
	wc.hInstance	 = hInstance;
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wc.lpszClassName = className;
	wc.hIcon		 = NULL;
	wc.hIconSm		 = NULL;
	
	if(!RegisterClassEx(&wc))
	{
	
return false;
}
	
	hwnd = CreateWindowEx(NULL, className, windowTitle, WS_OVERLAPPEDWINDOW|WS_SYSMENU, x, y, width, height, NULL, NULL, hInstance, NULL);
	
	  ShowWindow(hwnd, nCmdShow);
	  
	  return true;
   
 }
 LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)  {
	switch(message) {
		case WM_DESTROY: {
			PostQuitMessage(0);
			return 0;
		}break;
		
		}
		return DefWindowProc (hWnd, message, wParam, lParam);
		
    
}
void update(setup * game,float gameTime)
{
	game->update();
}
void draw(setup * game,float gameTime)
{
	game->Clear(  D3DCOLOR_XRGB(200, 200, 200));
	game->begin();
	game->render_frame();
	game->end();
	game->present();
}



 
