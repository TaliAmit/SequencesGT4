#pragma once

#include "GGUI.h"

#include <map>
#include <SDL_image.h>
#include <SDL.h>

#include "UI.h"
#include "ResourceManager.h"
#include "GGResourceManager.h"
#include "enums.h"

// not final! (supposed to be commpared to the 0,0 of the window or something)
const int Board_X = 100;
const int Board_Y = 100;

const int Screen_X = 100;
const int Screen_Y = 100;

const int ExitBtn_X = 100;
const int ExitBtn_Y = 100;

const int NewGameBtn_X = 100;
const int NewGameBtn_Y = 100;

GGUI::GGUI(SDL_Renderer* renderer, GGResourceManager& resMng)
	: UI(renderer)
	, m_resourceManager(resMng)
{
}

void GGUI::renderScreen()
{
	static SDL_Texture* boardTexture = m_resourceManager.getTexture(GG_GAME_SCREEN);
	static SDL_Rect textureLocation = { Screen_X, Screen_Y, 0, 0 };

	SDL_RenderCopy(m_renderer, boardTexture, nullptr, &textureLocation);
}


void GGUI::renderBoard()
{
	static SDL_Texture* screenGameTexture = m_resourceManager.getTexture(GG_BOARD);
	static SDL_Rect textureLocation = { Board_X, Board_Y, 0, 0 }; 

	SDL_RenderCopy(m_renderer, screenGameTexture, nullptr, &textureLocation);
}

void GGUI::renderExitBtn()
{
	static SDL_Texture* exitGameBtnTexture = m_resourceManager.getTexture(EXIT_GAME);
	static SDL_Rect textureLocation = { ExitBtn_X, ExitBtn_Y, 0, 0 };
	SDL_RenderCopy(m_renderer, exitGameBtnTexture, nullptr, &textureLocation);
}

void GGUI::renderNewGameBtn()
{
	static SDL_Texture* exitGameBtnTexture = m_resourceManager.getTexture(NEW_GAME);
	static SDL_Rect textureLocation = { NewGameBtn_X, NewGameBtn_Y, 0, 0 };
	SDL_RenderCopy(m_renderer, exitGameBtnTexture, nullptr, &textureLocation);
}

void GGUI::renderButtons()
{
	renderExitBtn();
	renderNewGameBtn();
}




