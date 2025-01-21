#pragma once

#include <SDL_image.h>
#include <SDL.h>

class UI
{
public:
	explicit UI(SDL_Renderer* renderer);
	~UI() = default;
	void renderTexture(SDL_Texture* texture, SDL_Rect* destRect);

protected:
	SDL_Renderer* m_renderer;
};