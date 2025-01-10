#include "ResourcesManager.h"



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


template <typename T>
void ResourcesManager::cleanupTextures(std::map<T, SDL_Texture*>& texturesMap)
{
	for (auto& [key, texture] : texturesMap)
	{
		SDL_DestroyTexture(texture);
	}

	textureMap.clear();
}


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



