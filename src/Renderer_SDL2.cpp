//
//  Renderer_SDL2.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Renderer_SDL2.h"

#include "AssetManager.h"
#include "Texture_SDL2.h"

Renderer_SDL2::Renderer_SDL2(SDL_Window* win, SDL_Renderer* rend) : m_win(win), m_rend(rend)
{
    update_window_size();
}

void Renderer_SDL2::update_window_size()
{
    SDL_GetWindowSize(m_win, &m_size.x, &m_size.y);
    if (!m_logical_set) {
        m_logical_size = m_size;
    }
}

void Renderer_SDL2::set_logical_size(Vector2i size, bool keepAspect)
{
    m_logical_set = true;
    m_logical_size = size;
    SDL_RenderSetLogicalSize(m_rend, size.x, size.y);
}

void Renderer_SDL2::set_swap_interval(int swap)
{
#ifndef EMSCRIPTEN
    int ret = SDL_GL_SetSwapInterval(swap);
    if (swap == -1 && ret != 0) {
        SDL_GL_SetSwapInterval(1);
    }
#endif
}

TextureRef Renderer_SDL2::load_texture(const std::string &name)
{
    std::string asset_file = AssetManager::DefaultManager().find_resource(name, "png");
    if (!asset_file.empty()) {
        return new Texture_SDL2(*this, asset_file);
    }
    return Texture::NullTexture;
}

void Renderer_SDL2::draw_texture(TextureRef texture, const Rect& src, const Rect& dst, float angle)
{
    SDL_Texture *stex = dynamic_cast<Texture_SDL2*>(texture)->m_texture;
    SDL_RenderCopyEx(m_rend, stex, (const SDL_Rect*)&src, (const SDL_Rect*)&dst, angle, NULL, SDL_FLIP_NONE);
}

void Renderer_SDL2::clear(const Color& color)
{
    set_draw_color(color);
    SDL_RenderClear(m_rend);
}

void Renderer_SDL2::draw_rect_fill(const Rect& r, const Color& c)
{
    set_draw_color(c);
    SDL_RenderFillRect(m_rend, (const SDL_Rect*)&r);
}

void Renderer_SDL2::present()
{
    SDL_RenderPresent(m_rend);
}

void Renderer_SDL2::set_draw_color(const Color& c)
{
    SDL_SetRenderDrawColor(m_rend, c.r, c.g, c.b, c.a);
}
