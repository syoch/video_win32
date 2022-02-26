#include <Windows.h>

HDC GetDC(HWND hwnd) { throw "Not Implemented."; }
WINBOOL GetWindowInfo(HWND hwnd, WINDOWINFO *pwi) { throw "Not Implemented."; }
void PostQuitMessage(int exitCode) { throw "Not Implemented."; }
HDC BeginPaint(HWND hwnd, PAINTSTRUCT *ps) { throw "Not Implemented."; }
bool EndPaint(HWND hwnd, PAINTSTRUCT *ps) { throw "Not Implemented."; }
LRESULT DefWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
  throw "Not Implemented.";
}
HICON LoadIcon(HINSTANCE hInstance, LPCWSTR lpIconName) {
  throw "Not Implemented.";
}
HCURSOR LoadCursor(HINSTANCE hInstance, LPCWSTR lpCursorName) {
  throw "Not Implemented.";
}

ATOM RegisterClass(const WNDCLASS *lpWndClass) { throw "Not Implemented."; }

HWND CreateWindowEx(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName,
                    DWORD dwStyle, int X, int Y, int nWidth, int nHeight,
                    HWND hWndParent, HMENU hMenu, HINSTANCE hInstance,
                    LPVOID lpParam) {}

WINBOOL GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                   UINT wMsgFilterMax) {}

WINBOOL TranslateMessage(const MSG *lpMsg) { throw "Not Implemented."; }

LRESULT DispatchMessage(const MSG *lpMsg) { throw "Not Implemented."; }

HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy) {
  throw "Not Implemented.";
}

HDC CreateCompatibleDC(HDC hdc) { throw "Not Implemented."; }
int ReleaseDC(HWND hWnd, HDC hDC) { throw "Not Implemented."; }

WINBOOL DeleteDC(HDC hdc) { throw "Not Implemented."; }
WINBOOL DeleteObject(HGDIOBJ ho) { throw "Not Implemented."; }
WINBOOL BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1,
               int y1, DWORD rop) {}
WINBOOL PatBlt(HDC hdc, int x, int y, int w, int h, DWORD rop) {
  throw "Not Implemented.";
}
HGDIOBJ GetStockObject(int fnObject) { throw "Not Implemented."; }