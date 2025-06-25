#include<windows.h>
#include"windowsAPI/windowsAPI.hpp"
 
 windowsAPI* app;
 
 int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
 HWND hwnd;
 app=new windowsAPI();
 app->bouclePrincipale( hInstance,  hPrevInstance,  lpCmdLine,  nCmdShow, hwnd);
 delete app;
 return 0;
 }
 


 
