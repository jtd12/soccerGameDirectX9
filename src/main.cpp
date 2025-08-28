#include<windows.h>
#include"windowsAPI/windowsAPI.hpp"
 
 windowsAPI* app;
 
 int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    HWND hwndGame = nullptr;
    HWND hwndGUI = nullptr;
 app=new windowsAPI();
 app->bouclePrincipale( hInstance,  hPrevInstance,  lpCmdLine,  nCmdShow, hwndGame,hwndGUI);
 delete app;
 return 0;
 }
 


 
