#include "UI.h"
#pragma once

UI::UI(SDL_Renderer* renderer)
    : m_renderer(renderer)
{
}

void UI::renderTexture(SDL_Texture* texture, SDL_Rect* destRect)
{
    if (texture)
    {
        if (destRect == nullptr)
        {
            SDL_RenderCopy(m_renderer, texture, nullptr, nullptr);
        }
        else
        {
            SDL_RenderCopy(m_renderer, texture, nullptr, destRect);
        }
    }
}

void UI::renderTexture(SDL_Texture* texture, int xPos, int yPos)
{
    if (texture)
    {
        if (xPos >= 0 && yPos >= 0) // and also the position doesn't exceed the board size  
        {
            SDL_Rect destRect = { xPos, yPos, 0, 0 };
            SDL_RenderCopy(m_renderer, texture, nullptr, &destRect);
        }
    }
}

bool UI::isMouseOver(int x, int y, int width, int height, int mouseX, int mouseY)
{
    return (mouseX >= x && mouseX <= x + width)
        && (mouseY >= y && mouseY <= y + height);
}
