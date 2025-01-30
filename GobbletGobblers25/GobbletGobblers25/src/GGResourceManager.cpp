#pragma once

#include "GGResourceManager.h"

#include <SDL_image.h>
#include <SDL.h>

#include <string>
#include <map>

#include "ResourceManager.h"


GGResourceManager::GGResourceManager(SDL_Renderer* renderer)
    : ResourceManager(renderer)
{
    //loadResources(); 
}

GGResourceManager::~GGResourceManager()
{

}

void GGResourceManager::loadResources()
{
    initializeGobblersRes();
    initializeBoardRes();
    initializeButtonsRes();
    initializeScreensRes();
}


void GGResourceManager::initGobblersPicsData()
{
    m_gobblersRes.emplace(GobblerKey(RED, SMALL), PictureData("pictures/PNG_GobblerRed_S.png"));
    m_gobblersRes.emplace(GobblerKey(RED, MEDIUM), PictureData("pictures/PNG_GobblerRed_M.png"));
    m_gobblersRes.emplace(GobblerKey(RED, LARGE), PictureData("pictures/PNG_GobblerRed_L.png"));

    m_gobblersRes.emplace(GobblerKey(BLUE, SMALL), PictureData("pictures/PNG_GobblerBlue_S.png"));
    m_gobblersRes.emplace(GobblerKey(BLUE, MEDIUM), PictureData("pictures/PNG_GobblerBlue_M.png"));
    m_gobblersRes.emplace(GobblerKey(BLUE, LARGE), PictureData("pictures/PNG_GobblerBlue_L.png"));

    m_gobblersRes.emplace(GobblerKey(GREEN, SMALL), PictureData("pictures/PNG_GobblerGreen_S.png"));
    m_gobblersRes.emplace(GobblerKey(GREEN, MEDIUM), PictureData("pictures/PNG_GobblerGreen_M.png"));
    m_gobblersRes.emplace(GobblerKey(GREEN, LARGE), PictureData("pictures/PNG_GobblerGreen_L.png"));

    m_gobblersRes.emplace(GobblerKey(ORANGE, SMALL), PictureData("pictures/PNG_GobblerOrange_S.png"));
    m_gobblersRes.emplace(GobblerKey(ORANGE, MEDIUM), PictureData("pictures/PNG_GobblerOrange_M.png"));
    m_gobblersRes.emplace(GobblerKey(ORANGE, LARGE), PictureData("pictures/PNG_GobblerOrange_L.png"));
}

void GGResourceManager::initBoardsPicsData()
{
    m_boardsRes.emplace(GG_BOARD, PictureData("pictures/PNG_GobbletGobblersBoard.png"));
}

void GGResourceManager::initButtonsPicsData()
{
    m_buttonsRes.emplace(NEW_GAME, PictureData("pictures/PNG_NewGameButton.png"));
    m_buttonsRes.emplace(EXIT_GAME, PictureData("pictures/PNG_ExitButton.png"));
}


void GGResourceManager::initScreensPicsData()
{
    m_screensRes.emplace(GG_GAME_SCREEN, PictureData("pictures/PNG_GobbletGobblersScreen.png"));
}


void GGResourceManager::unloadResources()
{
    removeTexturesFromData(m_gobblersRes);
    removeTexturesFromData(m_boardsRes);
    removeTexturesFromData(m_buttonsRes);
    removeTexturesFromData(m_screensRes);

    /*
    // should I replace this 3 function in one template?
    removeGobblersTextures();
    removeBoardTextures();
    removeButtonsTextures();
     removeScreensTextures();
    */

}

SDL_Texture* GGResourceManager::getTexture(GobblerKey gobblerKey) const
{
    auto it = m_gobblersRes.find(gobblerKey);

    if (it != m_gobblersRes.end())
    {
        return it->second.getTexture();
    }

    return nullptr;
}


SDL_Texture* GGResourceManager::getTexture(ButtonImage buttonEnum) const
{
    auto it = m_buttonsRes.find(buttonEnum);

    if (it != m_buttonsRes.end())
    {
        return it->second.getTexture();
    }

    return nullptr;
}

SDL_Texture* GGResourceManager::getTexture(BoardImage boardEnum) const
{
    auto it = m_boardsRes.find(boardEnum);

    if (it != m_boardsRes.end())
    {
        return it->second.getTexture();
    }

    return nullptr;
}

SDL_Texture* GGResourceManager::getTexture(ScreenImage screenEnum) const
{
    auto it = m_screensRes.find(screenEnum);

    if (it != m_screensRes.end())
    {
        return it->second.getTexture();
    }

    return nullptr;
}

void GGResourceManager::removeGobblersTextures()
{
    for (auto [key, picData] : m_gobblersRes)
    {
        if (picData.getTexture() != nullptr)
        {
            SDL_DestroyTexture( picData.getTexture() ); 
            picData.setTexture(nullptr);
        }
    }
}


void GGResourceManager::removeBoardTextures()
{
    for (auto [key, picData] : m_boardsRes)
    {
        if (picData.getTexture() != nullptr)
        {
            SDL_DestroyTexture(picData.getTexture());
            picData.setTexture(nullptr);
        }
    }
}


void GGResourceManager::removeButtonsTextures()
{
    for (auto [key, picData] : m_buttonsRes)
    {
        if (picData.getTexture() != nullptr)
        {
            SDL_DestroyTexture(picData.getTexture());
            picData.setTexture(nullptr);
        }
    }
}


void GGResourceManager::removeScreensTextures()
{
    for (auto [key, picData] : m_screensRes)
    {
        if (picData.getTexture() != nullptr)
        {
            SDL_DestroyTexture(picData.getTexture());
            picData.setTexture(nullptr);
        }
    }
}


void GGResourceManager::initializeGobblersRes()
{
    initGobblersPicsData();

    for (auto [key, val] : m_gobblersRes)
    {
        initTexture(val);
    }
}


void GGResourceManager::initializeBoardRes()
{
    initBoardsPicsData();

    for (auto [key, val] : m_boardsRes)
    {
        initTexture(val);
    }
}


void GGResourceManager::initializeButtonsRes()
{
    initButtonsPicsData();

    for (auto [key, val] : m_buttonsRes)
    {
        initTexture(val);
    }
}


void GGResourceManager::initializeScreensRes()
{
    initScreensPicsData();

    for (auto [key, val] : m_screensRes)
    {
        initTexture(val);
    }
}