#pragma once

#include "UI.h"
#include "ResourceManager.h"
#include "GG_ResourceMng.h"
#include "GG_Enums.h"


namespace UIPossitions
{
    const size_t BoardX = 100;
    const size_t BoardY = 100;

    const size_t ScreenX = 100;
    const size_t ScreenY = 100;

    const size_t LeftHandX = 100;
    const size_t LeftHandY = 100;

    const size_t RightHandX = 100;
    const size_t RightHandY = 100;

    const size_t HandGapX = 100;
    const size_t HandGapY = 100;

    const size_t BoardGapX = 100;
    const size_t BoardGapY = 100;

    const size_t ExitBtnX = 100;
    const size_t ExitBtnY = 100;

    const size_t NewGameBtnX = 100;
    const size_t NewGameBtnY = 100;

    //const size_t GapBetweenGobblers = 20;
}


class GGUI : public UI
{
public:
    explicit GGUI(SDL_Renderer* renderer, GGResourceManager& resMng);
    ~GGUI() = default;

    void renderScreen();
    void renderBoard();
    void renderButtons();
    void renderHands();
    void renderLeftHand(); // should it be private or not?
    void renderRightHand(); // should it be private or not?

private:
    void renderHand(PlayerColor playerColor, int xPos, int yPos);
    void renderButton(ButtonImage enumBtn, int xPos, int yPos);

    void renderExitBtn();
    void renderNewGameBtn(); 
    void renderButton(ButtonImage enumBtn, SDL_Rect textureLocation);

    
private:
    GGResourceManager& m_resourceManager; // will it be better to give the general ResourceManager?
    
    //std::map<GobblerSize, SDL_Texture*> rightHandTextures;
    //std::map<GobblerSize, SDL_Texture*> lefttHandTextures;

    PlayerColor m_leftHandColor;   // Store left hand color
    PlayerColor m_rightHandColor;  // Store right hand color
};
    /*
    {
        // Render background
        SDL_Texture* backgroundTexture = m_resourceManager->getTexture(BoardImage::Background);
        SDL_RenderCopy(m_renderer, backgroundTexture, nullptr, nullptr);

        // Render buttons (example of two buttons)
        SDL_Texture* playButtonTexture = m_resourceManager->getTexture(ButtonImage::PlayButton);
        SDL_Rect playButtonRect = { 100, 100, 200, 50 };  // Position and size of the button
        SDL_RenderCopy(m_renderer, playButtonTexture, nullptr, &playButtonRect);

        SDL_Texture* quitButtonTexture = m_resourceManager->getTexture(ButtonImage::QuitButton);
        SDL_Rect quitButtonRect = { 100, 200, 200, 50 };  // Position and size of the button
        SDL_RenderCopy(m_renderer, quitButtonTexture, nullptr, &quitButtonRect);

        // Any other UI elements can be rendered similarly
    }
   
    

    // Handles user input (button clicks, etc.)
    void handleInput()
    {
        // For example, check for mouse clicks on buttons
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                // Handle quit event
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);

                // Check if the click is inside the play button
                SDL_Rect playButtonRect = { 100, 100, 200, 50 };
                if (x >= playButtonRect.x && x <= playButtonRect.x + playButtonRect.w &&
                    y >= playButtonRect.y && y <= playButtonRect.y + playButtonRect.h) {
                    // Play button clicked, start the game or perform an action
                }

                // Check if the click is inside the quit button
                SDL_Rect quitButtonRect = { 100, 200, 200, 50 };
                if (x >= quitButtonRect.x && x <= quitButtonRect.x + quitButtonRect.w &&
                    y >= quitButtonRect.y && y <= quitButtonRect.y + quitButtonRect.h) {
                    // Quit button clicked, exit the game
                }
            }
        }
    }

    // Unloads resources when no longer needed
    void cleanup()
    {
        m_resourceManager->unloadResources();
    }
     */
