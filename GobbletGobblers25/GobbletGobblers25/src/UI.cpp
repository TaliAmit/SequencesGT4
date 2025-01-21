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
