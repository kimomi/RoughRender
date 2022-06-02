#include "Image.h"
#include <fstream>
#include <iostream>
#include <string>

Image::Image(int32_t w, int32_t h)
{
	width = w, height = h, pixelArr = new Color[w * h];
}

Image::~Image()
{
	delete[] pixelArr;
}

void Image::SetPixel(uint32_t x, uint32_t y, const Color& color)
{
	pixelArr[y * width + x] = color;
}

Color Image::GetPixel(uint32_t x, uint32_t y)
{
	return Color(pixelArr[y * width + x]);
}

void Image::WriteToFile(const char* fileName)
{
	std::ofstream outf{ fileName };

	if (!outf)
	{
		std::cerr << "Cound not open file " << fileName << " for writing!" << std::endl;
		return;
	}

	outf << "P3" << std::endl;
	outf << width << " " << height << std::endl;
	outf << "255" << std::endl;
	for (int32_t j = 0; j < height; j++)
	{
		for (int32_t i = 0; i < width; i++)
		{
			auto Color = GetPixel(i, j);
			outf << std::to_string(Color.R) << " " << std::to_string(Color.G) << " " << std::to_string(Color.B) << std::endl;
		}
	}
}

void Image::DrawLine(Vector2i startPoint, Vector2i endPoint, const Color& color)
{
	int x0 = startPoint.x;
	int x1 = endPoint.x;
	int y0 = startPoint.y;
	int y1 = endPoint.y;

	bool steep = std::abs(y1 - y0) > abs(x1 - x0);
	if (steep)
	{
		std::swap(x0, y0);
		std::swap(x1, y1);
	}

	if (x0 > x1)
	{
		std::swap(x0, x1);
		std::swap(y0, y1);
	}

	int32_t deltaX = x1 - x0;
	int32_t deltaY = std::abs(y1 - y0);
	int32_t error = deltaX / 2;
	int32_t y = y0;
	int32_t ystep = (y0 < y1) ? 1 : -1;
	for (int32_t x = x0; x <= x1; x++)
	{
		if (steep)
		{
			SetPixel(y, x, color);
		}
		else
		{
			SetPixel(x, y, color);
		}
		error -= deltaY;
		if (error < 0)
		{
			y += ystep;
			error += deltaX;
		}
	}
}
