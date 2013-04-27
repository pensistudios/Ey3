#include <windows.h>
#pragma comment(lib,"comctl32.lib")

#include "Ey3WindowedApp.h"
using namespace Ey3;

const int WindowedApp::KEY_ESCAPE = VK_ESCAPE;
const int WindowedApp::KEY_LEFT_ARROW = VK_LEFT;
const int WindowedApp::KEY_RIGHT_ARROW = VK_RIGHT;
const int WindowedApp::KEY_UP_ARROW = VK_UP;
const int WindowedApp::KEY_DOWN_ARROW = VK_DOWN;
const int WindowedApp::KEY_HOME = VK_HOME;
const int WindowedApp::KEY_END = VK_END;
const int WindowedApp::KEY_PAGE_UP = VK_PRIOR;
const int WindowedApp::KEY_PAGE_DOWN = VK_NEXT;
const int WindowedApp::KEY_INSERT = VK_INSERT;
const int WindowedApp::KEY_DELETE = VK_DELETE;
const int WindowedApp::KEY_F1 = VK_F1;
const int WindowedApp::KEY_F2 = VK_F2;
const int WindowedApp::KEY_F3 = VK_F3;
const int WindowedApp::KEY_F4 = VK_F4;
const int WindowedApp::KEY_F5 = VK_F5;
const int WindowedApp::KEY_F6 = VK_F6;
const int WindowedApp::KEY_F7 = VK_F7;
const int WindowedApp::KEY_F8 = VK_F8;
const int WindowedApp::KEY_F9 = VK_F9;
const int WindowedApp::KEY_F10 = VK_F10;
const int WindowedApp::KEY_F11 = VK_F11;
const int WindowedApp::KEY_F12 = VK_F12;

const int WindowedApp::KEY_SHIFT = MK_SHIFT;
const int WindowedApp::KEY_CONTROL = MK_CONTROL;
const int WindowedApp::KEY_ALT = 0;      // not currently handled
const int WindowedApp::KEY_COMMAND = 0;  // not currently handled

const int WindowedApp::MOUSE_LEFT_BUTTON = 0;
const int WindowedApp::MOUSE_MIDDLE_BUTTON = 1;
const int WindowedApp::MOUSE_RIGHT_BUTTON = 2;
const int WindowedApp::MOUSE_UP = 0;
const int WindowedApp::MOUSE_DOWN = 1;

const int WindowedApp::MODIFIER_CONTROL = MK_CONTROL;
const int WindowedApp::MODIFIER_LBUTTON = MK_LBUTTON;
const int WindowedApp::MODIFIER_MBUTTON = MK_MBUTTON;
const int WindowedApp::MODIFIER_RBUTTON = MK_RBUTTON;
const int WindowedApp::MODIFIER_SHIFT = MK_SHIFT;

extern Renderer* MsCreateRenderer (HWND hWnd, int iWidth, int iHeight);

void WindowedApp::RequestTermination ()
{
    PostMessage((HWND)IntToPtr(m_iWindowID),WM_DESTROY,0,0);
}

LRESULT CALLBACK MsWindowEventHandler (HWND hWnd, UINT uiMsg, WPARAM wParam,
    LPARAM lParam)
{
    WindowedApp* pkTheApp =
        (WindowedApp*)Application::TheApplication;

    if ( !pkTheApp || !pkTheApp->GetWindowID() )
        return DefWindowProc(hWnd,uiMsg,wParam,lParam);

    switch ( uiMsg ) 
    {
        case WM_PAINT:
        {
            PAINTSTRUCT kPS;
            HDC hDC = BeginPaint(hWnd,&kPS);
            pkTheApp->OnDisplay();
            EndPaint(hWnd,&kPS);
            return 0;
        }
        case WM_ERASEBKGND:
        {
            // This tells Windows not to erase the background (and that the
            // application is doing so).
            return 1;
        }
        case WM_MOVE:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));
            pkTheApp->OnMove(iXPos,iYPos);
            return 0;
        }
        case WM_SIZE:
        {
            int iWidth = int(LOWORD(lParam));
            int iHeight = int(HIWORD(lParam));
            pkTheApp->OnResize(iWidth,iHeight);
            return 0;
        }
        case WM_CHAR:
        {
            unsigned char ucKey = (unsigned char)(char)wParam;

            // get the cursor position in client coordinates
            POINT kPoint;
            GetCursorPos(&kPoint);
            ScreenToClient(hWnd,&kPoint);
            int iXPos = (int)kPoint.x;
            int iYPos = (int)kPoint.y;

            pkTheApp->OnKeyDown(ucKey,iXPos,iYPos);
            return 0;
        }
        case WM_KEYDOWN:
        {
            int iVirtKey = int(wParam);

            // get cursor position client coordinates
            POINT kPoint;
            GetCursorPos(&kPoint);
            ScreenToClient(hWnd,&kPoint);
            int iXPos = (int)kPoint.x;
            int iYPos = (int)kPoint.y;

            if ( (VK_F1 <= iVirtKey && iVirtKey <= VK_F12)
            ||   (VK_PRIOR <= iVirtKey && iVirtKey <= VK_DOWN)
            ||   (iVirtKey == VK_INSERT) )
            {
                pkTheApp->OnSpecialKeyDown(iVirtKey,iXPos,iYPos);
            }
            return 0;
        }
        case WM_KEYUP:
        {
            int iVirtKey = int(wParam);

            // get the cursor position in client coordinates
            POINT kPoint;
            GetCursorPos(&kPoint);
            ScreenToClient(hWnd,&kPoint);
            int iXPos = (int)kPoint.x;
            int iYPos = (int)kPoint.y;

            if ( (VK_F1 <= iVirtKey && iVirtKey <= VK_F12)
            ||   (VK_PRIOR <= iVirtKey && iVirtKey <= VK_DOWN)
            ||   (iVirtKey == VK_INSERT) )
            {
                pkTheApp->OnSpecialKeyUp(iVirtKey,iXPos,iYPos);
            }
            else
            {
                pkTheApp->OnKeyUp((unsigned char)iVirtKey,iXPos,iYPos);
            }
            return 0;
        }
        case WM_LBUTTONDOWN:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));
            pkTheApp->OnMouseClick(WindowedApp::MOUSE_LEFT_BUTTON,
                WindowedApp::MOUSE_DOWN,iXPos,iYPos,PtrToUint(wParam));
            return 0;
        }
        case WM_LBUTTONUP:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));
            pkTheApp->OnMouseClick(WindowedApp::MOUSE_LEFT_BUTTON,
                WindowedApp::MOUSE_UP,iXPos,iYPos,PtrToUint(wParam));
            return 0;
        }
        case WM_MBUTTONDOWN:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));
            pkTheApp->OnMouseClick(WindowedApp::MOUSE_MIDDLE_BUTTON,
                WindowedApp::MOUSE_DOWN,iXPos,iYPos,PtrToUint(wParam));
            return 0;
        }
        case WM_MBUTTONUP:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));
            pkTheApp->OnMouseClick(WindowedApp::MOUSE_MIDDLE_BUTTON,
                WindowedApp::MOUSE_UP,iXPos,iYPos,PtrToUint(wParam));
            return 0;
        }
        case WM_RBUTTONDOWN:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));
            pkTheApp->OnMouseClick(WindowedApp::MOUSE_RIGHT_BUTTON,
                WindowedApp::MOUSE_DOWN,iXPos,iYPos,PtrToUint(wParam));
            return 0;
        }
        case WM_RBUTTONUP:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));
            pkTheApp->OnMouseClick(WindowedApp::MOUSE_RIGHT_BUTTON,
                WindowedApp::MOUSE_UP,iXPos,iYPos,PtrToUint(wParam));
            return 0;
        }
        case WM_MOUSEMOVE:
        {
            int iXPos = int(LOWORD(lParam));
            int iYPos = int(HIWORD(lParam));

            int iButton = -1;
            if ( wParam & MK_LBUTTON )
                iButton = WindowedApp::MOUSE_LEFT_BUTTON;
            else if ( wParam & MK_MBUTTON )
                iButton = WindowedApp::MOUSE_MIDDLE_BUTTON;
            else if ( wParam & MK_RBUTTON )
                iButton = WindowedApp::MOUSE_RIGHT_BUTTON;

            if ( iButton >= 0 )
                pkTheApp->OnMotion(iButton,iXPos,iYPos);
            else
                pkTheApp->OnPassiveMotion(iXPos,iYPos);

            return 0;
        }
        case WM_DESTROY:
        {
            PostQuitMessage(0);
            return 0;
        }
    }

    return DefWindowProc(hWnd,uiMsg,wParam,lParam);
}
//----------------------------------------------------------------------------
int WindowedApp::doMain (int iQuantity, char** apcArgument)
{
    WindowedApp* pkTheApp = (WindowedApp*)TheApplication;

    // allow work to be done before the window is created
    if ( !pkTheApp->OnPrecreate() )
        return -1;

    // register the window class
    static char s_acWindowClass[] = "Wild Magic Application";
    WNDCLASS wc;
    wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc   = MsWindowEventHandler;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = 0;
    wc.hIcon         = LoadIcon(0,IDI_APPLICATION);
    wc.hCursor       = LoadCursor(0,IDC_ARROW);
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.lpszClassName = s_acWindowClass;
    wc.lpszMenuName  = 0;
    RegisterClass(&wc);

    // require the window to have the specified client area
    RECT kRect = { 0, 0, pkTheApp->GetWidth()-1, pkTheApp->GetHeight()-1 };
    AdjustWindowRect(&kRect,WS_OVERLAPPEDWINDOW,false);

    // create the application window
    HWND hWnd = CreateWindow(s_acWindowClass,pkTheApp->GetWindowTitle(),
        WS_OVERLAPPEDWINDOW,pkTheApp->GetXPosition(),pkTheApp->GetYPosition(),
        kRect.right-kRect.left+1,kRect.bottom-kRect.top+1,0,0,0,0);

    pkTheApp->SetWindowID(PtrToInt(hWnd));

    pkTheApp->SetRenderer(MsCreateRenderer(hWnd,pkTheApp->GetWidth(),
        pkTheApp->GetHeight()));

    if ( pkTheApp->OnInitialize() )
    {
        // display the window
        ShowWindow(hWnd,SW_SHOW);
        UpdateWindow(hWnd);

        // start the message pump
        MSG kMsg;
        while ( TRUE )
        {
            if ( PeekMessage(&kMsg,0,0,0,PM_REMOVE) )
            {
                if ( kMsg.message == WM_QUIT )
                    break;

                HACCEL hAccel = 0;
                if ( !TranslateAccelerator(hWnd,hAccel,&kMsg) )
                {
                    TranslateMessage(&kMsg);
                    DispatchMessage(&kMsg);
                }
            }
            else
            {
                pkTheApp->OnIdle();
            }
        }
    }

    pkTheApp->OnTerminate();
    return 0;
}
