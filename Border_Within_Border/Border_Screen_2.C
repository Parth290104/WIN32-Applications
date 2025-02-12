#include <Windows.h> 
#include <stdlib.h> 

#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam); 

void cpaDrawFrame(HDC hdc, int cxScreen, int cyScreen, int iDelta); 
void cpaDrawAxes(HDC hdc, int cxScreen, int cyScreen, int iDelta); 

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The standard window"); 
    static TCHAR szAppName[] = TEXT("DrawLine Demo"); 

    HWND hwnd = NULL; 

    WNDCLASSEX wnd; 
    MSG msg; 

    wnd.cbSize = sizeof(wnd);
    wnd.cbClsExtra = 0; 
    wnd.cbWndExtra = 0; 
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
            TEXT("Failed to regisgter a window class"), 
            TEXT("RegisterClassEx"), 
            MB_ICONERROR | MB_TOPMOST
        ); 
        ExitProcess(EXIT_FAILURE); 
    }

    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW, 
        szClassName, 
        szAppName, 
        WS_OVERLAPPED | WS_CAPTION | WS_THICKFRAME | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU, 
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
            TEXT("Failed to create an application window"), 
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
    static int cxChar; 
    int iCnt; 

    HDC hdc = NULL; 

    TEXTMETRIC tm; 
    PAINTSTRUCT ps; 

    switch(uMsg)
    {   
        case WM_CREATE: 
            hdc = GetDC(hwnd); 
            GetTextMetrics(hdc, &tm); 
            cxChar = tm.tmAveCharWidth; 
            ReleaseDC(hwnd, hdc); 
            break; 
        
        case WM_SIZE: 
            cxScreen = LOWORD(lParam); 
            cyScreen = HIWORD(lParam); 
            break; 

        case WM_PAINT: 
            hdc = BeginPaint(hwnd, &ps); 

            iCnt = 1; 
            while( 
                    (cxScreen - iCnt * cxChar) > cxScreen / 2 && 
                    (cyScreen - iCnt * cxChar) > cyScreen / 2 
                )
            {
                cpaDrawFrame(hdc, cxScreen, cyScreen, iCnt * cxChar); 
                iCnt = iCnt + 1; 
            }
        
            EndPaint(hwnd, &ps); 
            break; 

        case WM_DESTROY: 
            PostQuitMessage(0); 
            break; 
    }

    return (DefWindowProc(hwnd, uMsg, wParam, lParam)); 
}

void cpaDrawFrame(HDC hdc, int cxScreen, int cyScreen, int iDelta)
{
    MoveToEx(hdc, iDelta, iDelta, NULL); 
    LineTo(hdc, iDelta, cyScreen-iDelta); 
    LineTo(hdc, cxScreen-iDelta, cyScreen-iDelta); 
    LineTo(hdc, cxScreen - iDelta, iDelta); 
    LineTo(hdc, iDelta, iDelta); 
}

void cpaDrawAxes(HDC hdc, int cxScreen, int cyScreen, int iDelta)
{
    MoveToEx(hdc, iDelta, cyScreen/2, NULL); 
    LineTo(hdc, cxScreen - iDelta, cyScreen/2);

    MoveToEx(hdc, cxScreen/2, iDelta, NULL);
    LineTo(hdc, cxScreen/2, cyScreen - iDelta);  
}