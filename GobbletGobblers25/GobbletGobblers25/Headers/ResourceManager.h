/*
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
*/


#pragma once

#include <vector>
#include <string>
#include <map>
#include <SDL_image.h>
#include <SDL.h>
#include "Enums.h"

/**
 * @class PictureData
 * @brief A class that represents an individual picture's data, including its file path and associated texture.
 *
 * This class holds the path to an image file and its corresponding SDL_Texture object. It provides getter and setter
 * methods to access and modify the texture and path.
 */
class PictureData
{
public:
    /**
     * @brief Constructs a PictureData object with a given picture path and an optional texture.
     * @param picturePath The file path to the picture.
     * @param texture The SDL_Texture object associated with the picture (optional).
     */
    explicit PictureData(std::string picturePath, SDL_Texture* texture = nullptr);
    ~PictureData();

    /**
     * @brief Gets the texture associated with the picture.
     * @return The SDL_Texture object representing the picture.
     */
    SDL_Texture* getTexture() const;

    /**
     * @brief Gets the file path of the picture.
     * @return The string representing the picture's file path.
     */
    std::string getPath() const;

    /**
     * @brief Sets the texture for the picture.
     * @param texture The SDL_Texture object to be associated with the picture.
     */
    void setTexture(SDL_Texture* texture);

    /**
     * @brief Sets the file path of the picture.
     * @param path The file path string to be associated with the picture.
     */
    void setPath(std::string path);

private:
    std::string m_path;        // The file path to the picture.
    SDL_Texture* m_texture;    // The texture associated with the picture.
};



/**
 * @class ResourceManager
 * @brief A base class that manages resources such as textures, music and fonts.
 * The ResourceManager class is responsible for loading and unloading resources like textures and other assets.
 * It provides methods to initialize textures, load and unload resources, and handles texture management through
 * derived classes.
 */
class ResourceManager
{
public:
    /**
     * @brief Constructs a ResourceManager object with the given SDL_Renderer.
     * @param renderer The SDL_Renderer object that will be used for rendering textures.
     */
    explicit ResourceManager(SDL_Renderer* renderer);
    virtual ~ResourceManager() = default;

    /**
     * @brief Pure virtual function to load resources. Must be implemented in derived classes.
     * This method should load all necessary resources (e.g., textures, sounds, etc.) for the application.
     */
    virtual void loadResources() = 0;

    /**
     * @brief Pure virtual function to unload resources. Must be implemented in derived classes.
     * This method should unload all resources that were loaded using `loadResources()`.
     */
    virtual void unloadResources() = 0;

protected:
    /**
     * @brief Initializes the texture for a given PictureData object.
     * This method is used to load an SDL_Texture from a PictureData object and associate it with the provided
     * texture data.
     * @param picData The PictureData object containing the texture information.
     */
    void initTexture(PictureData& picData);

    /**
     * @brief Removes textures from the provided data map.
     * This template function removes textures from the map of PictureData objects, effectively freeing any resources
     * that were allocated for the textures.
     * @tparam T The key type of the map (e.g., enum values, strings, etc.).
     * @param picturesData The map containing PictureData objects to be processed.
     */
    template<typename T>
    void removeTexturesFromData(std::map<T, PictureData>& picturesData);

protected:
    SDL_Renderer* m_renderer; // The SDL_Renderer used for rendering textures.
};

#include "../Details/ResourceManager.inl"