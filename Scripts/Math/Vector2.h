#pragma once
#include <cstdint>

struct Vector2f
{
public:
	float x;
	float y;
};

struct Vector2i
{
public:
	int32_t x;
	int32_t y;
	Vector2i(int32_t ix, int32_t iy) { x = ix, y = iy; };
};