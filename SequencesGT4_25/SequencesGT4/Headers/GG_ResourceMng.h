#pragma once

#include "ResourceManager.h"
#include <string>
#include <map>
#include <SDL_image.h>
#include <SDL.h>

#include "GG_Enums.h"

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

using GobblerKey = std::pair<PlayerColor, GobblerSize>;


class GGResourceManager : public ResourceManager
{
public:
    explicit GGResourceManager(SDL_Renderer* renderer);
    ~GGResourceManager();

    void loadResources() override;
    void unloadResources() override;

    SDL_Texture* getTexture(GobblerKey gobblerEnum) const; 
    SDL_Texture* getTexture(ButtonImage buttonEnum) const;
    SDL_Texture* getTexture(BoardImage boardEnum) const;
    SDL_Texture* getTexture(ScreenImage screenEnum) const;

private:
    void initializeGobblersRes();
    void initializeBoardRes();
    void initializeButtonsRes();
    void initializeScreensRes();

    /**
     * @brief Initializes the picture data for gobblers.
     * This method sets up the `PictureData` for gobbler textures in the game, including their file paths.
     */
    void initGobblersPicsData();
    void initBoardsPicsData();
    void initButtonsPicsData();
    void initScreensPicsData();

    /**
     * @brief Removes the gobbler textures from memory.
     * This method cleans up the textures for gobblers and frees the associated resources.
     */
    void removeGobblersTextures();
    void removeBoardTextures();
    void removeButtonsTextures();
    void removeScreensTextures();

private:
    std::map<GobblerKey, PictureData> m_gobblersRes;   // Map storing gobbler images data by their enum.
    std::map<BoardImage, PictureData> m_boardsRes;       // Map storing board images data by their enum.
    std::map<ButtonImage, PictureData> m_buttonsRes;     // Map storing button images data by their enum.
    std::map<ScreenImage, PictureData> m_screensRes;     // Map storing screen images data by their enum.
};