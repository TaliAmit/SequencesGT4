#pragma once

#include <SDL_image.h>
#include <SDL.h>

#include <string>

#include "Init.h"
#include "ResourceManager.h"

class SDLGame
{
public:
	explicit SDLGame(ResourceManager& resMng, const std::string& title = "SequencesGT4", int width = GameConstants::WINDOW_WIDTH, int height = GameConstants::WINDOW_HEIGHT, int imgFlags = IMG_INIT_PNG);
	~SDLGame();
	
	void run();
	virtual void handleEvents() = 0;
	virtual void update() = 0;
	virtual void render() = 0;


protected:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	bool m_isRunning;
	ResourceManager& m_resMng; // or unique ptr and then std::move(...)


private:
	bool initSDL();
	
	bool initWindow(const std::string& title, int width, int height);
	bool initRenderer();
	bool initSDLPictureFormat(int imgFlags = IMG_INIT_PNG);

	void clean();
};

