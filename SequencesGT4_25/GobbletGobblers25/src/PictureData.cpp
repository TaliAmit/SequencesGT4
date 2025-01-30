#pragma once

#include "PictureData.h"
#include <string>


PictureData::PictureData(std::string picPath, SDL_Texture* texture)
	: m_path(picPath), m_texture(texture)
{
}


PictureData::~PictureData()
{
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
	}
}


SDL_Texture* PictureData::getTexture() const
{
	return m_texture;
}


std::string PictureData::getPath() const
{
	return m_path;
}


void PictureData::setTexture(SDL_Texture* texture)
{
	m_texture = texture;
}


void PictureData::setPath(std::string path)
{
	m_path = path;
}
