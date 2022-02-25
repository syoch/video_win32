#pragma once

#include "../types/integer.h"
#include "../types/string.h"

#define IS_INTRESOURCE(_r) ((((ULONG_PTR)(_r)) >> 16) == 0)
constexpr LPCWSTR MAKEINTRESOURCE(int x) {
  return reinterpret_cast<LPCWSTR>(static_cast<uintptr_t>(x));
};
