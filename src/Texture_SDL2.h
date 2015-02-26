//
//  Texture_SDL2.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

#include "Renderer_SDL2.h"

#include <SDL_render.h>

class Texture_SDL2 : public Texture {
    friend class Renderer_SDL2;
    SDL_Texture *m_texture;
public:
    Texture_SDL2(Renderer_SDL2& rend, const std::string& filename);
    ~Texture_SDL2();
};