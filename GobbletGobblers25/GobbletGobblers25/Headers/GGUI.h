#pragma once

#include "UI.h"
#include "ResourceManager.h"
#include "GGResourceManager.h"
#include "enums.h"

const 

class GGUI : public UI
{
public:
    explicit GGUI(SDL_Renderer* renderer, GGResourceManager& resMng);
    ~GGUI() = default;

    void renderScreen();
    void renderBoard();
    void renderExitBtn();
    void renderNewGameBtn();
    void renderButtons();

private:

private:
    GGResourceManager& m_resourceManager; // will it be better to give the general ResourceManager?
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
