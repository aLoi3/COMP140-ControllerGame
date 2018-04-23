#include "stdafx.h"
#include "Text.h"

Text::Text(SDL_Renderer * renderer, char * filePath, float initHeight, float initWidth)
{
	//Load image as texture
	texture = IMG_LoadTexture(renderer, filePath);
	height = initHeight;
	width = initWidth;
}