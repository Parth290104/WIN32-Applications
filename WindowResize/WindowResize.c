#include <Windows.h>

#define MAX_SIZE 32

#pragma comment (lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR szWindowTitle[] = TEXT("FIRST WINDOW");

    HWND hwnd = NULL;

    WNDCLASSEX wnd;
    MSG msg;

    ZeroMemory(&wnd, sizeof(WNDCLASSEX));
    ZeroMemory(&msg, sizeof(MSG));

    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbWndExtra = 0;
    wnd.cbClsExtra = 0;
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wnd.hCursor = LoadCursor((HINSTANCE)NULL, IDC_ARROW);
    wnd.hIcon = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadIcon((HINSTANCE)NULL, IDI_APPLICATION);
    wnd.hInstance = hInstance;
    
    wnd.lpfnWndProc = WndProc;
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL;
    wnd.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(
            (HWND)NULL,
            TEXT("Failed to register a window class"),
            TEXT("RegisterClassEx"),
            MB_ICONERROR | MB_TOPMOST
        );
        ExitProcess(EXIT_FAILURE);
    }

    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW,
        szClassName,
        szWindowTitle,
        WS_OVERLAPPED | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU | WS_CAPTION | WS_THICKFRAME,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        (HWND)NULL,
        (HMENU)NULL,
        hInstance,
        (LPVOID)NULL
    );

    if(hwnd == NULL)
    {
        MessageBox(
            (HWND)NULL,
            TEXT("Failed to create an application Window"),
            TEXT("CreateWindowEx"),
            MB_ICONERROR | MB_TOPMOST
        );
        ExitProcess(EXIT_FAILURE);

    }

    
        ShowWindow(hwnd, nShowCmd);
        UpdateWindow(hwnd);

        while(GetMessage(&msg, NULL, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        return ((int)msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        static int cxScreen, cyScreen;
        static TCHAR szSizeBuffer[MAX_SIZE];
        static int iLength;

        HDC hdc = NULL;
        PAINTSTRUCT ps;

        switch(uMsg)
        {
           case WM_PAINT:
                hdc = BeginPaint(hwnd, &ps);
                ZeroMemory(szSizeBuffer, MAX_SIZE);
                iLength = wsprintf(szSizeBuffer, TEXT("WIDTH:%d, HEIGHT:%d"), cxScreen, cyScreen);
                SetTextAlign(hdc, TA_TOP | TA_CENTER);
                TextOut(
                    hdc,
                    cxScreen/2,
                    cyScreen/2,
                    szSizeBuffer,
                    iLength
                );
                EndPaint(hwnd, &ps);
                break;
  
            case WM_SIZE:
                cxScreen = LOWORD(lParam);
                cyScreen = HIWORD(lParam);
                break;
            case WM_DESTROY:
                PostQuitMessage(EXIT_SUCCESS);
                break;
        }

        return (DefWindowProc(hwnd, uMsg, wParam, lParam));
    }