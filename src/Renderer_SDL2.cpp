//
//  Renderer_SDL2.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Renderer_SDL2.h"

Renderer_SDL2::Renderer_SDL2(SDL_Window* win, SDL_Renderer* rend) : m_win(win), m_rend(rend)
{
    update_window_size();
}

void Renderer_SDL2::update_window_size()
{
    SDL_GetWindowSize(m_win, &m_w, &m_h);
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

void Renderer_SDL2::clear()
{
    set_draw_color(Color());
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
