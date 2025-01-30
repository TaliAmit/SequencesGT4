#pragma once
#include "ResourceManager.h"


template <typename T>
void ResourceManager::removeTexturesFromData(std::map<T, PictureData>& picturesData)
{
    for (auto [key, picData] : picturesData)
    {
        if (picData.getTexture() != nullptr)
        {
            SDL_DestroyTexture( picData.getTexture() );
            picData.setTexture(nullptr);
        }
    }
}



//template <typename T>
//void ResourceManager::initializeTextures(std::map<T, PictureData> resourceMap)
//{
//	for (const auto& [key, picData] : pathsMap)
//	{
//		SDL_Texture* texture = IMG_LoadTexture(m_renderer, picData.path.c_str());
//		
//		if (!texture)
//		{
//			// return something (value or exception to the Game class)
//			std::cout << "Error loading texture: " << path << std::endl;
//			std::cout << "SDL_image error: " << IMG_GetError() << std::endl;
//			continue;
//		}
//
//		picData.texture = texture;
//	}
//}
//
//
//template <typename T>
//SDL_Texture* ResourceManager::loadTexture(const T& a_enum)
//{
//	// check why did I wnated to get an instance (if I am currently in the class) can approach directly 
//	ResourcesManager& instance = instance();
//	auto& textureMap = instance.getTexturesMap<T>();
//
//	// change : remove try and catch from here and put in the Game class. 
//	try
//	{
//		return textureMap.at(a_enum);
//	}
//	catch (const std::out_of_range&)
//	{
//		std::cout << "Texture not found for enum value: " << a_enum << std::endl;
//		return nullptr;
//	}
//}
//
//
//




//
//
//// I need to learn 1. this <> and 2. the decleration with no parameters in the braces
//template <>
//std::map<GobblerImage, SDL_Texture*>& 
// ::getTexturesMap<GobblerImage>()
//{
//	return m_gobblersTextures;
//}
//
//
//template <>
//std::map<BoardImage, SDL_Texture*>& GGResourceManager::getTexturesMap<BoardImage>()
//{
//	return m_boardsTextures;
//}
//
//
//template <>
//std::map<ButtonImage, SDL_Texture*>& GGResourceManager::getTexturesMap<ButtonImage>()
//{
//	return m_buttonsTextures;
//}
//
//

