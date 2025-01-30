#pragma once

#include <vector>
#include <string>
#include <map>
#include <SDL_image.h>
#include <SDL.h>
#include "GG_Enums.h"
#include "PictureData.h"


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