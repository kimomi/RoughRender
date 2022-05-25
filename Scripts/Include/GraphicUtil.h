#pragma once

#include <fstream>
#include <iostream>
#include <string>

/// <summary>
/// 写图片文件
/// </summary>
/// <param name="fileName"></param>
/// <param name="pixelArr"></param>
/// <param name="width"></param>
/// <param name="height"></param>
void WritePicToFile(const char* fileName, uint8_t* pixelArr, int32_t width, int32_t height)
{
	std::ofstream outf{fileName};

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
			outf << std::to_string(pixelArr[i * height + j * 3 + 0]) << " " << std::to_string(pixelArr[i * height + j * 3 + 1]) << " " << std::to_string(pixelArr[i * height + j * 3 + 2]) << std::endl;
		}
	}
}
