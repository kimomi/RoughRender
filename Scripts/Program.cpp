#include "stdio.h"
#include "GraphicCore/Image.h"

int main()
{
	
	Image* img = new Image(255, 255);
	for (auto i = 0; i < img->width; i++)
	{
		for (auto j = 0; j < img->height; j++)
		{
			img->SetPixel(i, j, Color(255, 255, 255));
		}
	}

	img->DrawLine(Vector2i(40, 50), Vector2i(200, 10), Color(0, 0, 0));
	img->DrawClipLine(Vector2i(40, 50), Vector2i(200, 10), 10, 80, 20, 100, Color(255, 0, 0));

	img->WriteToFile("line.ppm");
	

	return 0;
}