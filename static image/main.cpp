#include <windows.h>
 #define ID_ST 1
const char g_szClassName[] = "Static image";
void loadimage(HWND hwnd);
HBRUSH hb1;

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch(msg)
    {
    case WM_CREATE:
        loadimage(hwnd);
        break;
    case WM_COMMAND:
        if(LOWORD(wParam)==ID_ST){
        MessageBox(NULL,"Working","image",MB_OK);
       }
        break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;

    //Step 1: Registering the Window Class
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = hInstance;
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

    if(!RegisterClassEx(&wc))
    {
        MessageBox(NULL, "Window Registration Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    // Step 2: Creating the Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "The title of my window",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
        NULL, NULL, hInstance, NULL);

    if(hwnd == NULL)
    {
        MessageBox(NULL, "Window Creation Failed!", "Error!",
            MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // Step 3: The Message Loop
    while(GetMessage(&Msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }
    return Msg.wParam;
}
void loadimage(HWND hwnd){

HBITMAP h1;
        h1= (HBITMAP)LoadImage(NULL, "C:\\Users\\Nicat\\Documents\\static image\\pic.bmp", IMAGE_BITMAP, 100, 100, LR_LOADFROMFILE);
        if (h1 == NULL) {
            MessageBoxW(hwnd, L"Failed to load image", L"Error", MB_OK);
        }


        HWND hstat;

        hstat = CreateWindowW(L"Static", L"",
       WS_CHILD | WS_VISIBLE | SS_BITMAP,
       100, 100, 100, 100, hwnd, (HMENU)ID_ST, NULL, NULL);

   SendMessage(hstat, STM_SETIMAGE,
       (WPARAM)IMAGE_BITMAP, (LPARAM)h1);

}
