#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <iostream>
#include <windows.h> //GetCurrentDirectory

#include "SDLGame.h"
#include "GG_Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void waitForUserInput() {
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.ignore();
}


void printCurrentWorkingDirectory() {
    char cwd[1024];
    if (GetCurrentDirectoryA(sizeof(cwd), cwd)) {
        std::cout << "Current working dir: " << cwd << std::endl;
    }
    else {
        std::cerr << "Error getting current directory" << std::endl;
    }
}

int main(int argc, char* argv[])
{
    //GGGame game(1, 2, 3, 4);

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* texture = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        waitForUserInput();
        return 1;
    }

    window = SDL_CreateWindow("SDL Image Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        waitForUserInput();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        waitForUserInput();
        return 1;
    }

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        waitForUserInput();
        return 1;
    }

    printCurrentWorkingDirectory();

    SDL_Surface* loadedSurface = IMG_Load("Resources/Pictures/PNG_transparency_demonstration_1.png");
    if (loadedSurface == NULL)
    {
        std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError() << std::endl;
        waitForUserInput();
        return 1;
    }

    texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
    if (texture == NULL)
    {
        std::cout << "Unable to create texture from image! SDL Error: " << SDL_GetError() << std::endl;
        waitForUserInput();
        return 1;
    }

    SDL_FreeSurface(loadedSurface);

    SDL_Event e;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}
