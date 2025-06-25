#ifndef DEF_WINDOWSAPI_HPP
#define DEF_WINDOWSAPI_HPP
#include<windows.h>
#include"../setup/setup.h"

class windowsAPI
{

public:
windowsAPI();
~windowsAPI();
bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int width, int height,HWND& hwnd);
bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd);
static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int bouclePrincipale(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow,HWND hwnd);
private:
void update(setup * game,float gameTime);
void draw(setup * game,float gameTime);
};

#endif
