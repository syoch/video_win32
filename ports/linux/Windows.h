#pragma once

#include "windows/enums/all.h"
#include "windows/types/all.h"

#define CALLBACK

#define __TEXT(quote) L##quote
#define TEXT(quote) __TEXT(quote)

#define WINAPI

#define CW_USEDEFAULT ((int)0x80000000)

using HBITMAP = void *;
using HDC = void *;
using HWND = void *;
using HINSTANCE = void *;
using LRESULT = void *;

using PAINTSTRUCT = void *;

using ATOM = unsigned int;

using WINBOOL = unsigned int;
using WNDPROC = void *(*)(HWND, UINT, WPARAM, LPARAM);

using HICON = void *;
using HCURSOR = void *;
using HBRUSH = void *;
using HMENU = void *;

using LPVOID = void *;
struct RECT {
  int left;
  int top;
  int right;
  int bottom;
};

struct WINDOWINFO {
  DWORD cbSize;
  RECT rcWindow;
  RECT rcClient;
  DWORD dwStyle;
  DWORD dwExStyle;
  DWORD dwWindowStatus;
  UINT cxWindowBorders;
  UINT cyWindowBorders;
  ATOM atomWindowType;
  WORD wCreatorVersion;
};
struct POINT {
  int x;
  int y;
};

struct WNDCLASS {
  UINT style;
  WNDPROC lpfnWndProc;
  int cbClsExtra;
  int cbWndExtra;
  HINSTANCE hInstance;
  HICON hIcon;
  HCURSOR hCursor;
  HBRUSH hbrBackground;
  LPWSTR lpszMenuName;
  LPWSTR lpszClassName;
};

struct MSG {
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
};
using LPMSG = MSG *;

HDC GetDC(HWND hwnd);
WINBOOL GetWindowInfo(HWND hwnd, WINDOWINFO *pwi);
void PostQuitMessage(int exitCode);
HDC BeginPaint(HWND hwnd, PAINTSTRUCT *ps);
bool EndPaint(HWND hwnd, PAINTSTRUCT *ps);
LRESULT DefWindowProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
HICON LoadIcon(HINSTANCE hInstance, LPCWSTR lpIconName);
HCURSOR LoadCursor(HINSTANCE hInstance, LPCWSTR lpCursorName);

ATOM RegisterClass(const WNDCLASS *lpWndClass);

HWND CreateWindowEx(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName,
                    DWORD dwStyle, int X, int Y, int nWidth, int nHeight,
                    HWND hWndParent, HMENU hMenu, HINSTANCE hInstance,
                    LPVOID lpParam);

#define CreateWindow(lpClassName, lpWindowName, dwStyle, x, y, nWidth,       \
                     nHeight, hWndParent, hMenu, hInstance, lpParam)         \
  CreateWindowEx((DWORD)0, lpClassName, lpWindowName, dwStyle, x, y, nWidth, \
                 nHeight, hWndParent, hMenu, hInstance, lpParam)
WINBOOL GetMessage(LPMSG lpMsg, HWND hWnd, UINT wMsgFilterMin,
                   UINT wMsgFilterMax);

WINBOOL TranslateMessage(const MSG *lpMsg);

LRESULT DispatchMessage(const MSG *lpMsg);

HBITMAP CreateCompatibleBitmap(HDC hdc, int cx, int cy);

HDC CreateCompatibleDC(HDC hdc);
int ReleaseDC(HWND hWnd, HDC hDC);

WINBOOL DeleteDC(HDC hdc);
WINBOOL DeleteObject(HGDIOBJ ho);
WINBOOL BitBlt(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1,
               int y1, DWORD rop);
WINBOOL PatBlt(HDC hdc, int x, int y, int w, int h, DWORD rop);

#define SRCCOPY (DWORD)0x00CC0020
#define SRCPAINT (DWORD)0x00EE0086
#define SRCAND (DWORD)0x008800C6
#define SRCINVERT (DWORD)0x00660046
#define SRCERASE (DWORD)0x00440328
#define NOTSRCCOPY (DWORD)0x00330008
#define NOTSRCERASE (DWORD)0x001100A6
#define MERGECOPY (DWORD)0x00C000CA
#define MERGEPAINT (DWORD)0x00BB0226
#define PATCOPY (DWORD)0x00F00021
#define PATPAINT (DWORD)0x00FB0A09
#define PATINVERT (DWORD)0x005A0049
#define DSTINVERT (DWORD)0x00550009
#define BLACKNESS (DWORD)0x00000042
#define WHITENESS (DWORD)0x00FF0062
#define NOMIRRORBITMAP (DWORD)0x80000000
#define CAPTUREBLT (DWORD)0x40000000
#define MAKEROP4(fore, back) (DWORD)((((back) << 8) & 0xFF000000) | (fore))
