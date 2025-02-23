// Win32 headers
#include <windows.h>

// Libraries
#pragma comment(lib, "GDI32.lib")
#pragma comment(lib, "USER32.lib")
#pragma comment(lib, "Winmm.lib")

// macros
#define TEAL    1
#define MAGENTA 2
#define CYAN    3
#define BLUE    4
#define GOLD    5

// typedefs
typedef int counter_t;
typedef int status_t;
typedef int flag_t;

// global variable declarations
BOOL bButtonPress = FALSE;
flag_t flag = 0;
status_t active_button = 0;
counter_t count_b1 = 0;
counter_t count_b2 = 0;
counter_t count_b3 = 0;
counter_t count_b4 = 0;
counter_t count_b5 = 0;
counter_t count_b6 = 0;

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
                TEXT("Mini Music Studio By Parth"),
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
            HWND hButton1 = CreateWindow
                            (
                                "Button",
                                "Suspense",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                280,
                                250,
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
                                "Still Dre",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                390,
                                250,
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
                                "Shape of You",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                500,
                                250,
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
                                "URI",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                610,
                                250,
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
                                "Joy",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                720,
                                250,
                                100,
                                20,
                                hwnd,
                                (HMENU)5,
                                NULL,
                                NULL
                            );
            break;

            case WM_COMMAND:
                switch(LOWORD(wParam))
                {
                    case 1:
                        PlaySound(NULL, NULL, 0);
                        bButtonPress = TRUE;
                        count_b1++;
                        count_b2 = 0; // Refeshing count of other buttons
                        count_b3 = 0;
                        count_b4 = 0;
                        count_b5 = 0;
                        active_button = TEAL;
                        if(count_b1 % 2 == 0)
                        {
                            PlaySound(NULL, NULL, 0);
                            InvalidateRect(hwnd, NULL, TRUE);
                            break;
                        }
                        PlaySound("Suspense.wav", NULL, SND_FILENAME | SND_ASYNC);
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;                    
                    case 2:
                        PlaySound(NULL, NULL, 0);
                        bButtonPress = TRUE;
                        count_b2++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b3 = 0;
                        count_b4 = 0;
                        count_b5 = 0;
                        active_button = MAGENTA;
                        if(count_b2 % 2 == 0)
                        {
                            PlaySound(NULL, NULL, 0);
                            InvalidateRect(hwnd, NULL, TRUE);
                            break;
                        }
                        PlaySound("Still Dre Ringtone.wav", NULL, SND_FILENAME | SND_ASYNC);
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;
                    case 3:
                        PlaySound(NULL, NULL, 0);
                        bButtonPress = TRUE;
                        count_b3++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b2 = 0;
                        count_b4 = 0;
                        count_b5 = 0;
                        active_button = CYAN;
                        if(count_b3 % 2 == 0)
                        {
                            PlaySound(NULL, NULL, 0);
                            InvalidateRect(hwnd, NULL, TRUE);
                            break;
                        }
                        PlaySound("Shape of you ringtone  shape of you bgm  Ed Sheeran  @Zyxbeats12.wav", NULL, SND_FILENAME | SND_ASYNC);
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;
                    case 4:
                        PlaySound(NULL, NULL, 0);
                        bButtonPress = TRUE;
                        count_b4++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b2 = 0;
                        count_b3 = 0;
                        count_b5 = 0;
                        active_button = BLUE;
                        if(count_b4 % 2 == 0)
                        {
                            PlaySound(NULL, NULL, 0);
                            InvalidateRect(hwnd, NULL, TRUE);
                            break;
                        }
                        PlaySound("Uri ringtone.wav", NULL, SND_FILENAME | SND_ASYNC);
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;
                    case 5:
                        PlaySound(NULL, NULL, 0);
                        bButtonPress = TRUE;
                        count_b5++;
                        count_b1 = 0; // Refeshing count of other buttons
                        count_b2 = 0;
                        count_b3 = 0;
                        count_b4 = 0;
                        active_button = GOLD;
                        if(count_b5 % 2 == 0)
                        {
                            PlaySound(NULL, NULL, 0);
                            InvalidateRect(hwnd, NULL, TRUE);
                            break;
                        }
                        PlaySound("Ting ting.wav", NULL, SND_FILENAME | SND_ASYNC);
                        InvalidateRect(hwnd, NULL, TRUE);
                        break;

                    default:
                        break;
                }
                break;
        case WM_PAINT:
            HDC hdc = NULL;
            HBRUSH hbr;
            RECT rect;
            PAINTSTRUCT ps;
            if(bButtonPress == FALSE)
            {
            hdc = BeginPaint(hwnd, &ps);
            hbr = CreateSolidBrush(RGB(152, 251, 152));
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, hbr);

            SetBkMode(hdc, TRANSPARENT);
        
            TextOut(hdc, 500, 20, "Enjoy The Music !!!", 20);
            SetBkMode(hdc, OPAQUE);
            EndPaint(hwnd, &ps);
            break;
            }
            hdc = BeginPaint(hwnd, &ps);
            switch(active_button)
                    {
                        case TEAL:
                            if(count_b1 % 2 == 0)
                            {
                                hbr = CreateSolidBrush(RGB(152, 251, 152));
                                flag = 0;
                            }
                            else
                            {
                                hbr = CreateSolidBrush(RGB(255, 165, 0));
                                flag = 1;
                            }
                            break;
                        case MAGENTA:
                            if (count_b2 % 2 == 0)
                            {
                                hbr = CreateSolidBrush(RGB(152, 251, 152));
                                flag = 0;
                            }
                            else
                            {
                                hbr = CreateSolidBrush(RGB(255, 0, 255));
                                flag = 1;
                            }
                            break;
                        case CYAN:
                            if (count_b3 % 2 == 0)
                            {
                                hbr = CreateSolidBrush(RGB(152, 251, 152));
                                flag = 0;
                            }
                            else
                            {
                                hbr = CreateSolidBrush(RGB(0, 255, 255));
                                flag = 1;
                            }
                            break;
                        case BLUE:
                            if (count_b4 % 2 == 0)
                            {
                                hbr = CreateSolidBrush(RGB(152, 251, 152));
                                flag = 0;
                            }
                            else
                            {
                                hbr = CreateSolidBrush(RGB(0, 191, 255));
                                flag = 1;
                            }
                            break;
                        case GOLD:
                            if (count_b5 % 2 == 0)
                            {
                                hbr = CreateSolidBrush(RGB(152, 251, 152));
                                flag = 0;
                            }
                            else
                            {
                                hbr = CreateSolidBrush(RGB(255, 215, 0));
                                flag = 1;
                            }
                            break;
                    }
            GetClientRect(hwnd, &rect);
            FillRect(hdc, &rect, hbr);
            SetBkMode(hdc, TRANSPARENT);
            TextOut(hdc, 500, 20, "Enjoy The Music !!!", 20);
            if(flag == 0)
            {
                TextOut(hdc, 510, 120, "Music Stopped !!!", 18);
            }
            else
            {
                TextOut(hdc, 510, 120, "Playing Music !!!", 18);
            }
            SetBkMode(hdc, OPAQUE);
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
