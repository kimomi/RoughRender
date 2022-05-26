#pragma once
#include <cstdint>

struct Color
{
public:
	uint8_t R;
	uint8_t G;
	uint8_t B;
	const static uint8_t CHANNEL_SIZE = 3;

	Color();
	Color(uint8_t r, uint8_t g, uint8_t b);
};