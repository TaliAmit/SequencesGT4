#pragma once

#include "SDLGame.h"

#include <string>
#include <SDL_image.h>
#include <SDL.h>


SDLGame::SDLGame(ResourceManager& resMng, const std::string& title, int width, int height, int imgFlags)
    : m_resMng(resMng)
    , m_window(nullptr)
    , m_renderer(nullptr)
    , m_isRunning(true)
    
{
    initSDL();
    initWindow(title, width, height);
    initRenderer();
    initSDLPictureFormat(imgFlags);
}

SDLGame::~SDLGame()
{
    clean();
}

void SDLGame::run()
{
    while (m_isRunning) 
    {
        handleEvents();  
        update();        
        render();        

        SDL_Delay(16);   
    }

    //clean(); 
}


bool SDLGame::initSDL()
{
    return SDL_Init(SDL_INIT_EVERYTHING) == 0;
}



bool SDLGame::initWindow(const std::string& title, int width, int height)
{
    m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    return m_window != NULL;
}

bool SDLGame::initRenderer()
{
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    return m_renderer != NULL;
}

bool SDLGame::initSDLPictureFormat(int imgFlags)
{
    return IMG_Init(imgFlags) & imgFlags;
}

void SDLGame::clean()
{
    SDL_DestroyRenderer(m_renderer);
    m_renderer = nullptr;

    SDL_DestroyWindow(m_window);
    m_window = nullptr;

    SDL_Quit();
}
