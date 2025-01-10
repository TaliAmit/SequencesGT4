#pragma once

#include <vector>
#include <string>
#include <map>
#include <SDL_image.h>
#include <SDL.h>


enum GobblerImage
{
	RED_GOBBLER_SMALL,
	RED_GOBBLER_MEDIUM,
	RED_GOBBLER_LARGE,

	BLUE_GOBBLER_SMALL,
	BLUE_GOBBLER_MEDIUM,
	BLUE_GOBBLER_LARGE,

	GREEN_GOBBLER_SMALL,
	GREEN_GOBBLER_MEDIUM,
	GREEN_GOBBLER_LARGE,

	ORANGE_GOBBLER_SMALL,
	ORANGE_GOBBLER_MEDIUM,
	ORANGE_GOBBLER_LARGE,
};

enum FourInARowPlayerImage
{
	RED_PLAYER,
	BLUE_PLAYER,
	GREEN_PLAYER,
	ORANGE_PLAYER,
};

enum TicTacToePlayerImage
{
	X_PLAYER,
	O_PLAYER
};


enum BoardImage
{
	GOBBLET_GOBBLERS_BOARD
	// FOUR_IN_A_ROW_BOARD
	// TIC_TAC_TOE_BOARD
};


enum ButtonImage
{
	NEW_GAME,
	EXIT_GAME 
	//SCORES
};


enum class Fonts
{
	GOBBLET_GOBBLERS_FONT
	// FOUR_IN_A_ROW_FONT
	// TIC_TAC_TOE_FONT
};


enum class Music
{
	GOBBLET_GOBBLERS_GAME,
	MAIN_MENU
};


// use this : #include "ResourcesManager.inl" for the templates parts (?)

class ResourcesManager // singelton
{
public:
	explicit ResourcesManager(const ResourcesManager& a_other) = delete;
	ResourcesManager& operator=(const ResourcesManager& a_other) = delete;
	static ResourcesManager& instance();

	//SDL_Texture* texture(FourInARowPlayerImage a_enum);
	//SDL_Texture* texture(TicTacToePlayerImage a_enum);

	template<typename T>
	SDL_Texture* loadTexture(const T& a_enum);


private:
	explicit ResourcesManager(SDL_Renderer* renderer);
	~ResourcesManager();


	void initializeGobblersRes();
	void initializeBoardsRes();
	void initializeButtonsRes();

	//void initializeFourInARowPlayerRes();
	//void initializeTicTacToePlayersRes();
	//void initializeFonts();
	//void initializeMusic();


private:
	std::map<GobblerImage, SDL_Texture*> m_gobblersTextures;
	std::map<BoardImage, SDL_Texture*> m_boardsTextures;
	std::map<ButtonImage, SDL_Texture*> m_buttonsTextures;
	
	// std::map<FourInARowPlayerImage, SDL_Texture*> m_fourInARowPlayersTextures;
	// std::map<TicTacToePlayerImage, SDL_Texture*> m_ticTacToePlayersTextures;

	SDL_Renderer* m_renderer;

	template<typename T>
	void initializeTextures(const std::map<T, std::string>& paths, std::map<T, SDL_Texture*>& textureMap);
	

	template<typename T>
	void cleanupTextures(std::map<T, SDL_Texture*>& texturesMap);


	// learn why there are no parameters in the braces?
	template <typename T>
	std::map<T, SDL_Texture*>& getTexturesMap();
};

#include "../Details/ResourcesManager.inl"

