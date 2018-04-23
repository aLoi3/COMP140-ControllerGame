#pragma once
#include <SDL_image.h>

class Text
{
public:
	Text() {};
	Text(SDL_Renderer* renderer, char* filePath, float height, float width);
	~Text() {};

	SDL_Texture* getTexture()
	{
		return texture;
	}

	//Update texture (currently useless, needs the ability to update texture)
	void setTexture(SDL_Texture* newTexture)
	{
		texture = newTexture;
	}

	//Getters and Setters
	float getHeight()
	{
		return height;
	}
	float getWidth()
	{
		return width;
	}

	void setHeight(float newHeight)
	{
		height = newHeight;
	}
	void setWidth(float newWidth)
	{
		width = newWidth;
	}

private:
	//Sprite image
	SDL_Texture* texture;

	//Sprite dimensions
	float height;
	float width;
};