#pragma once

#define UNICODE
#include <Windows.h>

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#define  TIMELINE_BMP_WIDTH   2000
#define  TIMELINE_BMP_HEIGHT  1000

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

struct Point {
  i64 x;
  i64 y;
};

struct Size {
  i64 width;
  i64 height;
};

struct MouseEvent {
  enum class Kind {
    Down,
    Up,
    Move
  };

  Kind kind;
  Point pos;
};

class Timeline {
  HBITMAP bitmap;
  HDC     buffer;

public:
  explicit Timeline(HWND);
  ~Timeline();

  Timeline(Timeline&&) = delete;
  Timeline(Timeline const&) = delete;

  void draw(HDC dest, Point drawpos);

  void mouse_down(MouseEvent);
  void mouse_move(MouseEvent);
  void mouse_up(MouseEvent);
};

class Application {
  HINSTANCE hInstance;
  WINDOWINFO window_info;

  std::unique_ptr<Timeline> timeline;
  Point tl_drawpos; // timeline

public:
  explicit Application(HINSTANCE);
  Application(Application&&) = delete;
  Application(Application const&) = delete;

  LRESULT CALLBACK wnd_proc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp);

  int main(std::vector<std::wstring> args);
};