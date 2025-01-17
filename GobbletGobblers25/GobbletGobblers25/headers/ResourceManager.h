#pragma once

#include <vector>
#include <string>
#include <map>
#include <SDL_image.h>
#include <SDL.h>
#include "Enums.h"


class PictureData
{
public:
	explicit PictureData(std::string picturePath, SDL_Texture* texture = nullptr);
	~PictureData();

	SDL_Texture* getTexture() const;
	std::string getPath() const;

	void setTexture(SDL_Texture* texture);
	void setPath(std::string path);

private:
	std::string m_path;
	SDL_Texture* m_texture;
};


class ResourceManager
{
public:

	explicit ResourceManager(SDL_Renderer* renderer);
	virtual ~ResourceManager() = default;

	virtual void loadResources() = 0;  
	virtual void unloadResources() = 0; 

protected:
	void initTexture(PictureData& picData);

	template<typename T>
	void removeTexturesFromData(std::map<T, PictureData>& picturesData);

protected:
	SDL_Renderer* m_renderer;
};

#include "../Details/ResourceManager.inl"