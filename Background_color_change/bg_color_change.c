// Win32 headers
#include <windows.h>

// macros
#define TEAL    1
#define MAGENTA 2
#define CYAN    3
#define BLUE    4
#define GOLD    5
#define ORANGE  6

// global variable declarations
BOOL bButtonPress = FALSE;
int active_button;
int count_b1 = 0;
int count_b2 = 0;
int count_b3 = 0;
int count_b4 = 0;
int count_b5 = 0;
int count_b6 = 0;

// global function declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entrypoint function
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // variable declarations
    HWND hwnd = NULL;
    WNDCLASSEX wndclass;
    MSG msg;
    TCHAR szAppName[] = TEXT("Button Window");

    // code
    // window class initialization
    wndclass.cbSize = sizeof(WNDCLASSEX);
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.style = CS_HREDRAW | CS_VREDRAW;
    wndclass.hInstance = hInstance;
    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

    // Registration of window class
    RegisterClassEx(&wndclass);

    // Create window
    hwnd = CreateWindow
            (
                szAppName,
                TEXT("Color Change By Parth"),
                WS_OVERLAPPEDWINDOW,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                CW_USEDEFAULT,
                NULL,
                NULL,
                hInstance,
                NULL
            );
    
    // Show Window
    ShowWindow(hwnd, iCmdShow);

    // Update background of window
    UpdateWindow(hwnd);

    // Message Loop
    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return ((int)msg.wParam);
}

// callback function
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // code
    switch(iMsg)
    {
      case WM_CREATE:
            HWND chWnd = CreateWindow
                            (
                                "static",
                                "Hello!",
                                WS_VISIBLE | WS_CHILD,
                                20,
                                20,
                                100,
                                20,
                                hwnd,
                                NULL,
                                NULL,
                                NULL
                            );
            HWND hButton1 = CreateWindow
                            (
                                "Button",
                                "TEAL",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                20,
                                50,
                                100,
                                20,
                                hwnd,
                                (HMENU)1,
                                NULL,
                                NULL
                            );
            HWND hButton2 = CreateWindow
                            (
                                "Button",
                                "MAGENTA",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                130,
                                50,
                                100,
                                20,
                                hwnd,
                                (HMENU)2,
                                NULL,
                                NULL
                            );
            HWND hButton3 = CreateWindow
                            (
                                "Button",
                                "CYAN",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                240,
                                50,
                                100,
                                20,
                                hwnd,
                                (HMENU)3,
                                NULL,
                                NULL
                            );
            HWND hButton4 = CreateWindow
                            (
                                "Button",
                                "BLUE",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                350,
                                50,
                                100,
                                20,
                                hwnd,
                                (HMENU)4,
                                NULL,
                                NULL
                            );
            HWND hButton5 = CreateWindow
                            (
                                "Button",
                                "GOLD",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                460,
                                50,
                                100,
                                20,
                                hwnd,
                                (HMENU)5,
                                NULL,
                                NULL
                            );
            HWND hButton6 = CreateWindow
                            (
                                "Button",
                                "ORANGE",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                570,
                                50,
                                100,
                                20,
                                hwnd,
                                (HMENU)6,
                                NULL,
                                NULL
                            );
            break;

            case WM_COMMAND:
                switch(LOWORD(wParam))
                {
                    case 1:
                        bButtonPress = TRUE;
                        count_b1++;
                        count_b2 = 0; // Refeshing count of other buttons
                        count_b3 = 0;
                        count_b4 = 0;
                        count_b5 = 0;
                        count_b6 = 0;
                        active_button = TEAL;
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;                    
                    case 2:
                        bButtonPress = TRUE;
                        count_b2++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b3 = 0;
                        count_b4 = 0;
                        count_b5 = 0;
                        count_b6 = 0;
                        active_button = MAGENTA;
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;
                    case 3:
                        bButtonPress = TRUE;
                        count_b3++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b2 = 0;
                        count_b4 = 0;
                        count_b5 = 0;
                        count_b6 = 0;
                        active_button = CYAN;
                        InvalidateRect(hwnd,NULL, TRUE);
                        break;
                    case 4:
                        bButtonPress = TRUE;
                        count_b4++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b2 = 0;
                        count_b3 = 0;
                        count_b5 = 0;
                        count_b6 = 0;
                        active_button = BLUE;
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;
                    case 5:
                        bButtonPress = TRUE;
                        count_b5++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b2 = 0;
                        count_b3 = 0;
                        count_b4 = 0;
                        count_b6 = 0;
                        active_button = GOLD;
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;
                    case 6:
                        bButtonPress = TRUE;
                        count_b6++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b2 = 0;
                        count_b3 = 0;
                        count_b4 = 0;
                        count_b5 = 0;
                        active_button = ORANGE;
                        InvalidateRect(hwnd, NULL, TRUE);
                }
                
            case WM_PAINT:
                    if(bButtonPress == FALSE)
                        break;
                    PAINTSTRUCT ps;
                    HDC hdc = NULL;
                    HBRUSH hbr;
                    RECT rect;
                    hdc = BeginPaint(hwnd, &ps);
                    switch(active_button)
                    {
                        case TEAL:
                            if(count_b1 % 2 == 0)
                                hbr = CreateSolidBrush(RGB(255, 255, 255));
                            else
                                hbr = CreateSolidBrush(RGB(0, 128, 128));
                            break;
                        case MAGENTA:
                            if (count_b2 % 2 == 0)
                                hbr = CreateSolidBrush(RGB(255, 255, 255));
                            else
                                hbr = CreateSolidBrush(RGB(255, 0, 255));
                            break;
                        case CYAN:
                            if (count_b3 % 2 == 0)
                                hbr = CreateSolidBrush(RGB(255, 255, 255));
                            else
                                hbr = CreateSolidBrush(RGB(0, 255, 255));
                            break;
                        case BLUE:
                            if (count_b4 % 2 == 0)
                                hbr = CreateSolidBrush(RGB(255, 255, 255));
                            else
                                hbr = CreateSolidBrush(RGB(77, 77, 255));
                            break;
                        case GOLD:
                            if (count_b5 % 2 == 0)
                                hbr = CreateSolidBrush(RGB(255, 255, 255));
                            else
                                hbr = CreateSolidBrush(RGB(255, 215, 0));
                            break;
                        case ORANGE:
                            if (count_b6 % 2 == 0)
                                hbr = CreateSolidBrush(RGB(255, 255, 255));
                            else
                                hbr = CreateSolidBrush(RGB(255, 165, 0));
                            break;
                    }
                    GetClientRect(hwnd, &rect);
                    FillRect(hdc, &rect, hbr);
                    
                    DeleteObject(hbr);
                    EndPaint(hwnd, &ps);
                    break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            break;
    }

    return (DefWindowProc(hwnd, iMsg, wParam, lParam));
}
