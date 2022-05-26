#pragma once

#include <cstdint>
#include "Color.h"

/// <summary>
/// 图片基类
/// </summary>
class Image
{
private:

	/// <summary>
	/// 实际数据
	/// </summary>
	Color* pixelArr;

public:
	/// <summary>
	/// 图片宽度
	/// </summary>
	int32_t width;

	/// <summary>
	/// 图片高度
	/// </summary>
	int32_t height;

	Image(int32_t w, int32_t h);
	~Image();

	/// <summary>
	/// 设置像素点颜色
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="color"></param>
	void SetPixel(uint32_t x, uint32_t y, Color color);

	/// <summary>
	/// 写图片文件
	/// </summary>
	/// <param name="fileName">文件名</param>
	void WriteToFile(const char* fileName);
};

