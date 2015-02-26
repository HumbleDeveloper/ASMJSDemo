//
//  Texture_SDL2.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "Texture_SDL2.h"

#include <SDL_LodePNG.h>

Texture_SDL2::Texture_SDL2(Renderer_SDL2& rend, const std::string& filename) : m_texture(0)
{
    SDL_Surface *surface = SDL_LoadPNG(filename.c_str());
    if (surface) {
        m_texture = SDL_CreateTextureFromSurface(rend.m_rend, surface);
        if (m_texture) {
            m_size.x = surface->w;
            m_size.y = surface->h;
        }
        SDL_FreeSurface(surface);
    }
}

Texture_SDL2::~Texture_SDL2()
{
    if (m_texture) {
        SDL_DestroyTexture(m_texture);
    }
}