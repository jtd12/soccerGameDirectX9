#ifndef DEF_WINDOWSAPI_HPP
#define DEF_WINDOWSAPI_HPP
#include<windows.h>
#include <dinput.h>
#include <tchar.h>
#include"../setup/setup.h"


extern LPDIRECTINPUT8          g_pDI;
extern LPDIRECTINPUTDEVICE8    g_pJoystick;
 
class windowsAPI
{

public:
windowsAPI();
~windowsAPI();
bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int width, int height,HWND& hwnd,DWORD style);
bool Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd,DWORD style);
static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
int bouclePrincipale(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow,HWND hwnd,HWND hwndGUI);
static LRESULT CALLBACK EditMax3000Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static LRESULT CALLBACK EditMax10Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
static BOOL CALLBACK EnumJoysticksCallback(const DIDEVICEINSTANCE* pdidInstance, VOID* pContext);
static BOOL CALLBACK EnumObjectsCallback(const DIDEVICEOBJECTINSTANCE* pdidoi, VOID* pContext);
static HRESULT InitDirectInput(HINSTANCE hInstance, HWND hWnd);
void Cleanup();
void PollJoystick(DIJOYSTATE& js);

private:
void update(DIJOYSTATE& js,setup * game,float gameTime);
void draw(setup * game,float gameTime);
static setup* set;
static HINSTANCE hInst;
static HWND hEditVitesse;
static HWND hEditGravity;
static HWND hEditNumberSupport;


};

#endif
