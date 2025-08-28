#include"windowsAPI.hpp"
HINSTANCE windowsAPI::hInst = nullptr;
HWND windowsAPI::hEditVitesse = nullptr;
HWND windowsAPI::hEditGravity = nullptr;
HWND windowsAPI::hEditNumberSupport = nullptr;
setup* windowsAPI::set = nullptr;
WNDPROC oldEditProc = nullptr; // globale ou membre statique

windowsAPI::windowsAPI()
{
	set=new setup();
}

windowsAPI::~windowsAPI()
{
	
}

 bool windowsAPI::Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle, int width, int height,HWND& hwnd,DWORD style)
 {
 	return Generatewindow(hInstance,nCmdShow,className,windowTitle,(GetSystemMetrics(SM_CXSCREEN)-width)/2,(GetSystemMetrics(SM_CXSCREEN)-height)/2,width, height, hwnd,style);
 }
 
 bool windowsAPI::Generatewindow(HINSTANCE hInstance,int nCmdShow,LPCSTR className,LPCSTR windowTitle,int x, int y, int width, int height,HWND& hwnd,DWORD style)
 {
hInst = hInstance;
   WNDCLASSEX wc;
    //memset(&wc,0,sizeof(wc));
    ZeroMemory(&wc,sizeof(WNDCLASSEX));
	wc.cbSize		 = sizeof(wc);
	wc.style=CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc	 = windowsAPI::WindowProc;
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
	
   hwnd = CreateWindowExA(
        0, 
        className,
        windowTitle,
        style,
        x, y, width, height,
        NULL, // Use nullptr instead of NULL
        NULL, // Use nullptr instead of NULL
        hInstance,
        NULL  // Use nullptr instead of NULL
    );

    if (!hwnd) {
        return false;
    }
	  ShowWindow(hwnd, nCmdShow);
	  
	  return true;
   
 }
 
 
 

LRESULT CALLBACK windowsAPI::EditMax3000Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_CHAR) {
        if ((wParam >= '0' && wParam <= '9') || wParam == VK_BACK) {
            // Lire le texte actuel
            char buffer[16];
            GetWindowTextA(hWnd, buffer, sizeof(buffer));
            int len = strlen(buffer);
      // Simuler ce que serait le texte après la saisie
            char tentative[16] = {};
            if (wParam == VK_BACK) {
                if (len == 0) return 0;

                strncpy(tentative, buffer, len - 1);
            } else if (len < 10) {
                strcpy(tentative, buffer);
                tentative[len] = (char)wParam;
                tentative[len + 1] = '\0';
            }

            // Si tentative vide, on bloque sauf si la valeur précédente était >= 20
            if (strlen(tentative) == 0) {
                int current = atoi(buffer);
                if (current < 10)
                    return 0; // blocage suppression totale si valeur < 20
                return CallWindowProc(oldEditProc, hWnd, msg, wParam, lParam);
            }
            // Convertir en nombre
             int valeur = atoi(tentative);
            if (valeur < 10 || valeur > 3000)
                return 0; // bloqué si hors plage
        } else {
            return 0; // bloquer les caractères non numériques
        }
    }

    return CallWindowProc(oldEditProc, hWnd, msg, wParam, lParam);
}



LRESULT CALLBACK windowsAPI::EditMax10Proc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    if (msg == WM_CHAR) {
        if ((wParam >= '0' && wParam <= '9') || wParam == VK_BACK) {
            // Lire le texte actuel
            char buffer[16];
            GetWindowTextA(hWnd, buffer, sizeof(buffer));
            int len = strlen(buffer);
      // Simuler ce que serait le texte après la saisie
            char tentative[16] = {};
            if (wParam == VK_BACK) {
                if (len == 0) return 0;

                strncpy(tentative, buffer, len - 1);
            } else if (len < 10) {
                strcpy(tentative, buffer);
                tentative[len] = (char)wParam;
                tentative[len + 1] = '\0';
            }

            // Si tentative vide, on bloque sauf si la valeur précédente était >= 20
            if (strlen(tentative) == 0) {
                int current = atoi(buffer);
                if (current < 0)
                    return 0; // blocage suppression totale si valeur < 20
                return CallWindowProc(oldEditProc, hWnd, msg, wParam, lParam);
            }
            // Convertir en nombre
             float valeur = atof(tentative);
            if (valeur < .3f || valeur > 10.0f)
                return 0; // bloqué si hors plage
        } else {
            return 0; // bloquer les caractères non numériques
        }
    }

    return CallWindowProc(oldEditProc, hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK windowsAPI::WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	
char className[256] = {};
GetClassNameA(hWnd, className, sizeof(className));

if (strcmp(className, "gui_class") == 0) {
        switch (message) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
             case WM_SHOWWINDOW:
            {
                
             
                    
              CreateWindowEx(0, "STATIC", "Vitesse Player:",
        WS_CHILD | WS_VISIBLE,
        10, 10, 60, 20,
        hWnd, nullptr, hInst, nullptr);
        
         CreateWindowEx(0, "STATIC", "Gravity Ball:",
        WS_CHILD | WS_VISIBLE,
        10, 50, 60, 20,
        hWnd, nullptr, hInst, nullptr);
        
         CreateWindowEx(0, "STATIC", "Number Supporter:",
        WS_CHILD | WS_VISIBLE,
        10, 100, 100, 50,
        hWnd, nullptr, hInst, nullptr);

    hEditVitesse = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "1.5",
        WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
        80, 10, 100, 20,
        hWnd, nullptr, hInst, nullptr);
        
        SendMessage(hEditVitesse, EM_LIMITTEXT, (WPARAM)2, 0);
		oldEditProc = (WNDPROC)SetWindowLongPtr(hEditVitesse, GWLP_WNDPROC, (LONG_PTR)EditMax10Proc);
        
    hEditGravity = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "3.0",
        WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
        80, 50, 100, 20,
        hWnd, nullptr, hInst, nullptr);
        
        SendMessage(hEditGravity, EM_LIMITTEXT, (WPARAM)2, 0);
		oldEditProc = (WNDPROC)SetWindowLongPtr(hEditGravity, GWLP_WNDPROC, (LONG_PTR)EditMax10Proc);
        
    hEditNumberSupport = CreateWindowEx(WS_EX_CLIENTEDGE, "EDIT", "2000",
        WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
        80, 100, 100, 20,
        hWnd, nullptr, hInst, nullptr);

		SendMessage(hEditNumberSupport, EM_LIMITTEXT, (WPARAM)4, 0);
		oldEditProc = (WNDPROC)SetWindowLongPtr(hEditNumberSupport, GWLP_WNDPROC, (LONG_PTR)EditMax3000Proc);
		
    CreateWindowEx(0, "BUTTON", "Appliquer",
        WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
        190, 10, 80, 20,
        hWnd, (HMENU)1, hInst, nullptr);
                
            }
                break;
            case WM_COMMAND:
                if (LOWORD(wParam) == 1) {
                    char buffer[32];
                    GetWindowTextA(hEditVitesse, buffer, sizeof(buffer));
                    float valeur = (float)atof(buffer);
                    
                    
                    	for(int i=0;i<set->themtogether()->playerInstance().size();i++)
	  						set->themtogether()->playerInstance()[i]->setSpeed(valeur);
	  					
	  						
	  					for(int i=0;i<set->themtogether()->playerInstanceAI().size();i++)
	  						set->themtogether()->playerInstanceAI()[i]->setSpeed(valeur);
	  	
		  	  
                    GetWindowTextA(hEditGravity, buffer, sizeof(buffer));
                    float valeurGravity = (float)atof(buffer);
					 set->themtogether()->getBalle()->setGravity(valeurGravity);
					 
					GetWindowTextA(hEditNumberSupport, buffer, sizeof(buffer));
                    int valeurSupport = (int)atoi(buffer);
					 set->themtogether()->setNumberSupporters(valeurSupport);
					 
			
				
                    // TODO: transmettre cette valeur à ta classe de jeu
                }
                break;
        }
    }
    else if (strcmp(className, "api window directX") == 0) {
        switch (message) {
            case WM_DESTROY:
                PostQuitMessage(0);
                return 0;
        }
    }

	return DefWindowProc(hWnd, message, wParam, lParam);
}
 
void windowsAPI::update(setup * game,float gameTime)
{
	game->update();

}
void windowsAPI::draw(setup * game,float gameTime)
{
	game->Clear(  D3DCOLOR_XRGB(200, 200, 200));
	game->begin();
	game->render_frame();
	game->end();
	game->present();
}


int windowsAPI:: bouclePrincipale(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow,HWND hwnd,HWND hwndGUI)
{
	 if (!Generatewindow(hInstance, nCmdShow, "gui_class", "Fenêtre GUI", 1000, 100, 300, 350, hwndGUI, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU))
        return 0;
 	if(!Generatewindow(hInstance,nCmdShow,"api window directX","soccer game directx9!",10,10,960,540,hwnd,WS_OVERLAPPEDWINDOW))
 	 return 0;
 	 
 		MSG msg;
 		setup * game=new setup();
 		game->initD3D( hwnd,true);
 		game->init_graphics(hwnd);
 		game->init_Light();
 		windowsAPI::set = game; // ?? ici tu l’associes
 		
	 	while(true) {
	        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
	            TranslateMessage(&msg);
	            DispatchMessage(&msg);
	        }
	        if(msg.message==WM_QUIT) break;
	        else {
		       	update(game,0.0f);//CPU
		        draw(game,0.0f);//GPU
			}
		
		
		}
		delete game;
		return msg.wParam;
	
	 
	return 0;
}
