#define WIN32_LEAN_AND_MEAN

#include "Ey3.h"

#include <windows.h>
#include <fstream>

bool exiting = false;
long windowWidth = 800;
long windowHeight = 600;
long windowBits = 32;
bool fullscreen = false;
HDC hDC;
Ey3::WGLRenderer* render;
Ey3::Core* core;
using namespace Ey3;
bool camForward = false;
bool camBackward = false;
bool camLeft = false;
bool camRight = false;
bool camUp = false;
bool camDown = false;
bool camTurnLeft = false;
bool camTurnRight = false;
bool showCursor = true;
Vector3 mPos;
Vector3 oldMPos;
bool mouseMove = false;

LRESULT CALLBACK MainWindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    static HDC hDC;
    static HGLRC hRC;
    int height, width;
	int xPos;
	int yPos;

    // dispatch messages
    switch (uMsg)
    {   
    case WM_CREATE:         // window creation
        
		
		
        break;

    case WM_DESTROY:            // window destroy
    case WM_QUIT:
    case WM_CLOSE:                  // windows is closing

        // deselect rendering context and delete it
        //wglMakeCurrent(hDC, NULL);
        //wglDeleteContext(hRC);
		
        // send WM_QUIT to message queue
        PostQuitMessage(0);
        break;

    case WM_SIZE:
        height = HIWORD(lParam);        // retrieve width and height
        width = LOWORD(lParam);

        render->resize(width,height);

        break;

    case WM_ACTIVATEAPP:        // activate app
        break;

    case WM_PAINT:              // paint
        PAINTSTRUCT ps;
        BeginPaint(hWnd, &ps);
        EndPaint(hWnd, &ps);
        break;

    case WM_LBUTTONDOWN:        // left mouse button
		xPos = int(LOWORD(lParam));
        yPos = int(HIWORD(lParam));
		showCursor = (showCursor)?false:true;
		ShowCursor((BOOL)showCursor);
		if(!showCursor) 
		{ 
			oldMPos.x = xPos;
			oldMPos.y = yPos;
			oldMPos.z = 1.0f;
		}
		else mouseMove = false;
        break;

    case WM_RBUTTONDOWN:        // right mouse button
        break;

    case WM_MOUSEMOVE:          // mouse movement
		xPos = int(LOWORD(lParam));
        yPos = int(HIWORD(lParam));

		if(!showCursor)
		{
			mPos.x = xPos;
			mPos.y = yPos;
			mPos.z = 1.0f;
			mouseMove = true;
		}

        break;

    case WM_LBUTTONUP:          // left button release
        break;

    case WM_RBUTTONUP:          // right button release
        break;

    case WM_KEYDOWN:
        int fwKeys;
        LPARAM keyData;
        fwKeys = (int)wParam;    // virtual-key code 
        keyData = lParam;          // key data 
		
        switch(fwKeys)
        {
		case 'W':
			camForward = true;
		    break;
		case 'S':
			camBackward = true;
		    break;
		case 'A':
			camLeft = true;
			break;
		case 'D':
			camRight = true;
			break;
		case 'E':
			camUp = true;
			break;
		case 'Q':
			camDown = true;
			break;
		case VK_LEFT:
			camTurnLeft = true;
			break;
		case VK_RIGHT:
			camTurnRight = true;
			break;
        case VK_ESCAPE:
            PostQuitMessage(0);
            break;
        default:
            break;
        }

        break;

	case WM_KEYUP:
		fwKeys = (int)wParam;    // virtual-key code 
        keyData = lParam; 

		switch(fwKeys)
		{
		case 'W':
			camForward = false;
			break;
		case 'S':
			camBackward = false;
			break;
		case 'A':
			camLeft = false;
			break;
		case 'D':
			camRight = false;
			break;
		case 'E':
			camUp = false;
			break;
		case 'Q':
			camDown = false;
			break;
		case VK_LEFT:
			camTurnLeft = false;
			break;
		case VK_RIGHT:
			camTurnRight = false;
			break;
		default:
			break;
		}
		
		break;
		

    default:
        break;
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    WNDCLASSEX windowClass;     // window class
    HWND       hwnd;            // window handle
    MSG        msg;             // message
    DWORD      dwExStyle;       // Window Extended Style
    DWORD      dwStyle;         // Window Style
    RECT       windowRect;

    windowRect.left=(long)0;                        // Set Left Value To 0
    windowRect.right=(long)windowWidth; // Set Right Value To Requested Width
    windowRect.top=(long)0;                         // Set Top Value To 0
    windowRect.bottom=(long)windowHeight;   // Set Bottom Value To Requested Height

	core = new Ey3::Core;
	core->init();

    // fill out the window class structure
    windowClass.cbSize          = sizeof(WNDCLASSEX);
    windowClass.style           = CS_HREDRAW | CS_VREDRAW;
    windowClass.lpfnWndProc     = MainWindowProc;
    windowClass.cbClsExtra      = 0;
    windowClass.cbWndExtra      = 0;
    windowClass.hInstance       = hInstance;
    windowClass.hIcon           = LoadIcon(NULL, IDI_APPLICATION);  // default icon
    windowClass.hCursor         = LoadCursor(NULL, IDC_ARROW);      // default arrow
    windowClass.hbrBackground   = NULL;                             // don't need background
    windowClass.lpszMenuName    = NULL;                             // no menu
    windowClass.lpszClassName   = "GLClass";
    windowClass.hIconSm         = LoadIcon(NULL, IDI_WINLOGO);      // windows logo small icon


    // register the windows class
    if (!RegisterClassEx(&windowClass))
        return 0;

    if (fullscreen)                             // fullscreen?
    {
        DEVMODE dmScreenSettings;                   // device mode
        memset(&dmScreenSettings,0,sizeof(dmScreenSettings));
        dmScreenSettings.dmSize = sizeof(dmScreenSettings); 
        dmScreenSettings.dmPelsWidth = windowWidth;         // screen width
        dmScreenSettings.dmPelsHeight = windowHeight;           // screen height
        dmScreenSettings.dmBitsPerPel = windowBits;             // bits per pixel
        dmScreenSettings.dmFields=DM_BITSPERPEL|DM_PELSWIDTH|DM_PELSHEIGHT;

        // 
        if (ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN) != DISP_CHANGE_SUCCESSFUL)
        {
            // setting display mode failed, switch to windowed
			MessageBox(NULL,"Display mode failed", NULL, MB_OK);
            fullscreen = FALSE; 
        }
    }

    if (fullscreen)                             // Are We Still In Fullscreen Mode?
    {
        dwExStyle=WS_EX_APPWINDOW;                  // Window Extended Style
        dwStyle=WS_POPUP;                       // Windows Style
        ShowCursor(FALSE);                      // Hide Mouse Pointer
    }
    else
    {
        dwExStyle=WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;   // Window Extended Style
        dwStyle=WS_OVERLAPPEDWINDOW;                    // Windows Style
    }

    AdjustWindowRectEx(&windowRect, dwStyle, FALSE, dwExStyle);     // Adjust Window To True Requested Size
    // class registered, so now create our window
    hwnd = CreateWindowEx(NULL,                      // extended style
        "GLClass",                          // class name
        "Test Render",      // app name
        dwStyle | WS_CLIPCHILDREN |
        WS_CLIPSIBLINGS,
        0, 0,                               // x,y coordinate
        windowRect.right - windowRect.left,
        windowRect.bottom - windowRect.top, // width, height
        NULL,                               // handle to parent
        NULL,                               // handle to menu
        hInstance,                          // application instance
        NULL);                              // no extra params

	render = new Ey3::WGLRenderer(hwnd,windowWidth,windowHeight);
	Ey3::Camera* cam = new Ey3::Camera();
	
	render->setCamera(cam);
	render->setBackgroundColor(ColorRGB(0.0f,0.0f,0.0f));
	cam->setLocation(Vector3(0.0f,0.0f,-5.0f));

    LOG("Renderer Created");
	
    ShowWindow(hwnd, SW_SHOW);          // display the window
	UpdateWindow(hwnd);                 // update the window
    //Init?

	std::ifstream xyFile("XY.txt");
	Ey3::SimpleGeometry* xyGeom = Ey3::SimpleGeometry::createFromStream(xyFile);
	Ey3::SceneNode* node = new SceneNode(1);
	node->setChild(0,xyGeom);
	node->local.setUniformScale(2.0f);
	node->updateWorldTransform();

	Matrix3 rot;
	float rotSpeed = 0.001f;

    while (TRUE)
    {
		
		Vector3 kLoc = cam->getWorldLocation();
	
		if(camForward)
		{
			kLoc += cam->getWorldDVector()*0.001f;
			cam->setLocation(kLoc);
		}

		if(camBackward)
		{
			kLoc -= cam->getWorldDVector()*0.001f;
			cam->setLocation(kLoc);
		}

		if(camLeft)
		{
			kLoc += cam->getWorldRVector()*0.001f;
			cam->setLocation(kLoc);
		}

		if(camRight)
		{
			kLoc -= cam->getWorldRVector()*0.001f;
			cam->setLocation(kLoc);
		}

		if(camUp)
		{
			kLoc += cam->getWorldUVector()*0.001f;
			cam->setLocation(kLoc);
		}

		if(camDown)
		{
			kLoc -= cam->getWorldUVector()*0.001f;
			cam->setLocation(kLoc);
		}
	
		if(camTurnLeft)
		{
			rot.fromAxisAngle(cam->getWorldUVector(),rotSpeed);
	
		    Vector3 DVector = rot*cam->getDVector();
		    Vector3 UVector = rot*cam->getUVector();
		    Vector3 RVector = rot*cam->getRVector();
		    cam->setAxes(DVector,UVector,RVector);
		}

		if(camTurnRight)
		{
			rot.fromAxisAngle(cam->getWorldUVector(),-rotSpeed);
	
		    Vector3 DVector = rot*cam->getDVector();
		    Vector3 UVector = rot*cam->getUVector();
		    Vector3 RVector = rot*cam->getRVector();
		    cam->setAxes(DVector,UVector,RVector);
		}
		
		render->drawScene((SceneNode*)node);
        render->displayBackBuffer();

        while (PeekMessage (&msg, NULL, 0, 0, PM_NOREMOVE))
        {
            if (!GetMessage (&msg, NULL, 0, 0))
            {
                exiting = true;
                break;
            }

            TranslateMessage (&msg);
            DispatchMessage (&msg);
        }
    }

	delete cam;
	delete render;
	delete core;
	delete node;
	delete xyGeom;
    return (int)msg.wParam;
}