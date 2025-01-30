#pragma once

#include <SDL_image.h>
#include <SDL.h>

#include <string>

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
    std::string m_path;        // The file path to the picture.
    SDL_Texture* m_texture;    // The texture associated with the picture.
};