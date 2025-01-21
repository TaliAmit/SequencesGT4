#pragma once

#include "ResourceManager.h"
#include <string>
#include <map>
#include <SDL_image.h>
#include <SDL.h>

#include "enums.h"


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


/**
 * @class 
 * 
 * @brief A specialized subclass of ResourceManager for managing resources in a Gobbler game.
 * The `GGResourceManager` class extends the base `ResourceManager` class and specializes resource
 * management for a Gobbler game, including textures for gobblers, boards, buttons, and screens. This
 * class handles loading, unloading, and accessing resources specific to the game.
 */
class GGResourceManager : public ResourceManager
{
public:
    /**
     * @brief Constructs a GGResourceManager object with the provided SDL_Renderer.
     * @param renderer The SDL_Renderer used for rendering the textures in the game.
     */
    explicit GGResourceManager(SDL_Renderer* renderer);
    ~GGResourceManager();

    /**
     * @brief Loads the game-specific resources, such as textures for gobblers, boards, buttons, and screens.
     * This method overrides the `loadResources()` function in the base class and is responsible for
     * loading all necessary game assets.
     */
    void loadResources() override;

    /**
     * @brief Unloads all the game-specific resources that were loaded using `loadResources()`.
     * This method overrides the `unloadResources()` function in the base class and ensures that all
     * resources are properly cleaned up when no longer needed.
     */
    void unloadResources() override;

    /**
     * @brief Gets the texture for a specific texture, based on the provided enum.
     * @param gobblerEnum The enum value corresponding to the specific gobbler image.
     * @return The SDL_Texture associated with the specified gobbler.
     */
    SDL_Texture* getTexture(GobblerImage gobblerEnum);
    SDL_Texture* getTexture(ButtonImage buttonEnum);
    SDL_Texture* getTexture(BoardImage boardEnum);
    SDL_Texture* getTexture(ScreenImage screenEnum);

private:
    /**
     * @brief Initializes the resources for gobblers (textures and associated data).
     * This method loads and prepares the textures and data associated with the gobblers.
     */
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
    std::map<GobblerImage, PictureData> m_gobblersRes;   // Map storing gobbler images data by their enum.
    std::map<BoardImage, PictureData> m_boardsRes;       // Map storing board images data by their enum.
    std::map<ButtonImage, PictureData> m_buttonsRes;     // Map storing button images data by their enum.
    std::map<ScreenImage, PictureData> m_screensRes;     // Map storing screen images data by their enum.
};