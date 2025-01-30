#pragma once

#include <SDL_image.h>
#include <SDL.h>

class UI
{
public:
	explicit UI(SDL_Renderer* renderer);
	~UI() = default;
	void renderTexture(SDL_Texture* texture, SDL_Rect* destRect);
	void renderTexture(SDL_Texture* texture, int xPos, int yPos);


protected:
	bool isMouseOver(int x, int y, int width, int height, int mouseX, int mouseY);


protected:
	SDL_Renderer* m_renderer;
};