#pragma once

#include "GG_UI.h"

#include <map>
#include <vector>
#include <SDL_image.h>
#include <SDL.h>

#include "UI.h"
#include "ResourceManager.h"
#include "GG_ResourceMng.h"
#include "GG_Enums.h"
#include "init.h"



GGUI::GGUI(SDL_Renderer* renderer, GGResourceManager& resMng)
	: UI(renderer)
	, m_resourceManager(resMng)
	, m_leftHandColor(NONE) // change this
	, m_rightHandColor(NONE) // change this
{
}

void GGUI::renderScreen()
{
	static SDL_Texture* boardTexture = m_resourceManager.getTexture(GG_GAME_SCREEN);
	static SDL_Rect textureLocation = { UIPossitions::ScreenX, UIPossitions::ScreenY, 0, 0 };

	SDL_RenderCopy(m_renderer, boardTexture, nullptr, &textureLocation);
}


void GGUI::renderBoard()
{
	static SDL_Texture* screenGameTexture = m_resourceManager.getTexture(GG_BOARD);
	static SDL_Rect textureLocation = { UIPossitions:: BoardX, UIPossitions::BoardY, 0, 0 };

	SDL_RenderCopy(m_renderer, screenGameTexture, nullptr, &textureLocation);
}

void GGUI::renderHands()
{
	renderLeftHand();
	renderRightHand();
}

void GGUI::renderLeftHand()
{
	renderHand(m_leftHandColor, UIPossitions::LeftHandX, UIPossitions::LeftHandY);
}

void GGUI::renderRightHand()
{
	renderHand(m_rightHandColor, UIPossitions::RightHandX, UIPossitions::RightHandY);
}

// change this function to get all locations of current possitions and then draw the hand.
void GGUI::renderHand(PlayerColor playerColor, int xPos, int yPos)
{
	int gapX = UIPossitions::HandGapX;
	int gapY = UIPossitions::HandGapY;

	auto textureGobblerS = m_resourceManager.getTexture(GobblerKey(playerColor, SMALL));
	auto textureGobblerM = m_resourceManager.getTexture(GobblerKey(playerColor, MEDIUM));
	auto textureGobblerL = m_resourceManager.getTexture(GobblerKey(playerColor, LARGE));
	
	int countGobblers = 0, j = 1;

	for (int i = 0; i < GameConstants::LARGE_GOBBLERS; ++i)
	{
		renderTexture(textureGobblerS, xPos * gapX * i, yPos * j / GameConstants::LARGE_GOBBLERS);
		++j;
	}

	for (int i = 0; i < GameConstants::MEDIUM_GOBBLERS; ++i)
	{
		renderTexture(textureGobblerS, xPos * gapX * i, yPos * j / GameConstants::LARGE_GOBBLERS);
		++j;
	}

	for (int i = 0; i < GameConstants::SMALL_GOBBLERS; ++i)
	{
		renderTexture(textureGobblerS, xPos * gapX * i, yPos * j / GameConstants::LARGE_GOBBLERS);
		++j;
	}
}

void GGUI::renderButton(ButtonImage enumBtn, int xPos, int yPos)
{
	SDL_Texture* btnTexture = m_resourceManager.getTexture(enumBtn);
	SDL_Rect textureLocation = { xPos, yPos, 0, 0 };
	renderTexture(btnTexture, &textureLocation);
}


void GGUI::renderButton(ButtonImage enumBtn, SDL_Rect textureLocation)
{
	renderTexture(m_resourceManager.getTexture(enumBtn), &textureLocation);
}


void GGUI::renderExitBtn()
{
	//renderButton(EXIT_GAME, UIPossitions::ExitBtnX, UIPossitions::ExitBtnY);

	static SDL_Texture* exitGameBtnTexture = m_resourceManager.getTexture(EXIT_GAME);
	static SDL_Rect textureLocation = { UIPossitions::ExitBtnX, UIPossitions::ExitBtnY, 0, 0 };
	renderTexture(exitGameBtnTexture, &textureLocation);

	//SDL_RenderCopy(m_renderer, exitGameBtnTexture, nullptr, &textureLocation);
}

void GGUI::renderNewGameBtn()
{
	// renderButton(NEW_GAME, UIPossitions::NewGameBtnX, UIPossitions::NewGameBtnY);

	static SDL_Texture* newGameBtnTexture = m_resourceManager.getTexture(NEW_GAME);
	static SDL_Rect textureLocation = { UIPossitions::NewGameBtnX, UIPossitions::NewGameBtnY, 0, 0 };
	renderTexture(newGameBtnTexture, &textureLocation);

	//SDL_RenderCopy(m_renderer, newGameBtnTexture, nullptr, &textureLocation);
}

void GGUI::renderButtons()
{
	renderExitBtn();
	renderNewGameBtn();
}




