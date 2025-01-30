#pragma once

#include "ResourceManager.h"
#include <string>
#include <map>
#include <iostream>


void ResourceManager::initTexture(PictureData& picData)
{
	std::string path = picData.getPath();
	auto cPicPath = path.c_str();

	SDL_Surface* surface = IMG_Load(cPicPath);

	if (surface == nullptr)
	{
		// Handle the error in the Game Class
		SDL_Log("Error loading image %s: %s", cPicPath, IMG_GetError());
		return;
	}

	auto texture = SDL_CreateTextureFromSurface(m_renderer, surface);
	if (texture == nullptr)
	{
		// Handle the error in the Game Class
		SDL_Log("Error creating texture from surface: %s", SDL_GetError());
	}
	else
	{
		picData.setTexture(texture);
	}

	SDL_FreeSurface(surface);
}

ResourceManager::ResourceManager(SDL_Renderer* renderer)
	: m_renderer(renderer)
{
}





