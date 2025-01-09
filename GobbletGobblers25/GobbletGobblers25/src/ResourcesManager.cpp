#pragma once

#include "resourcesManager.h"
#include <map>
#include <iostream>


const std::map<GobblerImage, std::string> gobblersPicturesPaths
{
 {RED_GOBBLER_SMALL, "pictures/PNG_GobblerRed_S.png"},
 {RED_GOBBLER_MEDIUM, "pictures/PNG_GobblerRed_M.png"},
 {RED_GOBBLER_LARGE, "pictures/PNG_GobblerRed_L.png"},

 {BLUE_GOBBLER_SMALL, "pictures/PNG_GobblerBlue_S.png"},
 {BLUE_GOBBLER_MEDIUM, "pictures/PNG_GobblerBlue_M.png"},
 {BLUE_GOBBLER_LARGE, "pictures/PNG_GobblerBlue_L.png"},

 {GREEN_GOBBLER_SMALL, "pictures/PNG_GobblerGreen_S.png"},
 {GREEN_GOBBLER_MEDIUM, "pictures/PNG_GobblerGreen_M.png"},
 {GREEN_GOBBLER_LARGE, "pictures/PNG_GobblerGreen_L.png"},

 {ORANGE_GOBBLER_SMALL, "pictures/PNG_GobblerOrange_S.png"},
 {ORANGE_GOBBLER_MEDIUM, "pictures/PNG_GobblerOrange_M.png"},
 {ORANGE_GOBBLER_LARGE, "pictures/PNG_GobblerOrange_L.png"}
};


const std::map<BoardImage, std::string> boardsPicturesPaths
{
 {GOBBLET_GOBBLERS_BOARD, "pictures/PNG_GobbletGobblersBoard.png"}
};


const std::map<ButtonImage, std::string> buttonsPicturesPaths
{
 {NEW_GAME, "pictures/newGameButton.png"},
 {EXIT_GAME, "pictures/exitButton.png"}
};


// I need to learn 1. this <> and 2. the decleration with no parameters in the braces
template <>
std::map<GobblerImage, SDL_Texture*>& ResourcesManager::getTexturesMap<GobblerImage>()
{
	return m_gobblersTextures;
}


template <>
std::map<BoardImage, SDL_Texture*>& ResourcesManager::getTexturesMap<BoardImage>()
{
	return m_boardsTextures;
}


template <> 
std::map<ButtonImage, SDL_Texture*>& ResourcesManager::getTexturesMap<ButtonImage>()
{
	return m_buttonsTextures;
}


/*
const std::map<FourInARowPlayerImage, std::string> fourInARowPlayersPicsPaths
{
 {RED_PLAYER, "pictures/PNG_FIAR_RedPlayer.png"},
 {BLUE_PLAYER, "pictures/PNG_FIAR_BluePlayer.png"},
 {GREEN_PLAYER, "pictures/PNG_FIAR_GreenPlayer.png"},
 {ORANGE_PLAYER, "pictures/PNG_FIAR_OrangePlayer.png"},
};
*/


ResourcesManager::ResourcesManager(SDL_Renderer* renderer)
{
	initializeGobblersRes();
	initializeBoardsRes();
	initializeButtonsRes();

	// initialize fonts
	//initialize music
}

ResourcesManager::~ResourcesManager()
{
	cleanupTextures(m_gobblersTextures);
	cleanupTextures(m_boardsTextures);
	cleanupTextures(m_buttonsTextures);
}


template <typename T>
void ResourcesManager::initializeTextures(const std::map<T, std::string>& pathsMap, std::map<T, SDL_Texture*>& texturesMap)
{
	for (const auto& [key, path] : pathsMap)
	{
		SDL_Texture* texture = IMG_LoadTexture(m_renderer, path.c_str());

		if (!texture)
		{
			std::cout << "Error loading texture: " << path << std::endl;
			std::cout << "SDL_image error: " << IMG_GetError() << std::endl;
			continue;
		}

		textureMap[key] = texture;
	}
}


template <typename T>
void ResourcesManager::cleanupTextures(std::map<T, SDL_Texture*>& texturesMap)
{
	for (auto& [key, texture] : texturesMap)
	{
		SDL_DestroyTexture(texture);
	}

	textureMap.clear();
}

void ResourcesManager::initializeGobblersRes()
{
	initializeTextures(gobblersPicturesPaths, m_gobblersTextures);
}

void ResourcesManager::initializeBoardsRes()
{
	initializeTextures(boardsPicturesPaths, m_boardsTextures);
}

void ResourcesManager::initializeButtonsRes()
{
	initializeTextures(buttonsPicturesPaths, m_buttonsTextures);
}

// why do I need "_" before the parameter?
// why is it in red? what's wrong?
ResourcesManager& ResourcesManager::instance()
{
	static ResourcesManager _instance;
	return _instance;
}


template <typename T>
SDL_Texture* ResourcesManager::loadTexture(const T& a_enum)
{
	ResourcesManager& instance = instance();
	auto& textureMap = instance.getTexturesMap<T>();

	try
	{
		return textureMap.at(a_enum);
	}
	catch (const std::out_of_range&)
	{
		std::cout << "Texture not found for enum value: " << a_enum << std::endl;
		return nullptr;
	}
}


