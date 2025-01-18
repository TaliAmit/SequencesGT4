#pragma once

#include "ResourceManager.h"
#include <string>
#include <map>
#include <SDL_image.h>
#include <SDL.h>


enum GobblerImage
{
	RED_GOBBLER_SMALL,
	RED_GOBBLER_MEDIUM,
	RED_GOBBLER_LARGE,

	BLUE_GOBBLER_SMALL,
	BLUE_GOBBLER_MEDIUM,
	BLUE_GOBBLER_LARGE,

	GREEN_GOBBLER_SMALL,
	GREEN_GOBBLER_MEDIUM,
	GREEN_GOBBLER_LARGE,

	ORANGE_GOBBLER_SMALL,
	ORANGE_GOBBLER_MEDIUM,
	ORANGE_GOBBLER_LARGE,
};


enum BoardImage
{
	GG_BOARD
};


enum ButtonImage
{
	NEW_GAME,
	EXIT_GAME
};

enum ScreenImage
{
	GG_GAME_SCREAN
};

/*
enum Fonts
{
	GG_FONT
};


enum Music
{
	GG_MUSIC
};
*/


class GG_ResourceManager : public ResourceManager
{
public:
	explicit GG_ResourceManager(SDL_Renderer* renderer);
	~GG_ResourceManager();

	void loadResources() override;
	void unloadResources() override;

	SDL_Texture* getTexture(GobblerImage gobblerEnum);
	SDL_Texture* getTexture(ButtonImage buttonEnum);
	SDL_Texture* getTexture(BoardImage boardEnum);
	SDL_Texture* getTexture(ScreenImage screenEnum);

	
private:
	void initializeGobblersRes();
	void initializeBoardRes();
	void initializeButtonsRes();
	void initializeScreensRes();

	void initGobblersPicsData();
	void initBoardsPicsData();
	void initButtonsPicsData();
	void initScreensPicsData();

	// I think I can delete those because I have created a template instead, ask Haim.
	void removeGobblersTextures();
	void removeBoardTextures();
	void removeButtonsTextures();
	void removeScreensTextures();


private:
	std::map<GobblerImage, PictureData> m_gobblersRes;
	std::map<BoardImage, PictureData> m_boardsRes;
	std::map<ButtonImage, PictureData> m_buttonsRes;
	std::map<ScreenImage, PictureData> m_screensRes;
};

