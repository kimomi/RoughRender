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

void Image::SetPixel(uint32_t x, uint32_t y, Color color)
{
	pixelArr[x * width + y] = color;
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
	for (int32_t i = 0; i < width; i++)
	{
		for (int32_t j = 0; j < height; j++)
		{
			outf << std::to_string(pixelArr[i * height + j].R) << " " << std::to_string(pixelArr[i * height + j].R) << " " << std::to_string(pixelArr[i * height + j].B) << std::endl;
		}
	}
}
