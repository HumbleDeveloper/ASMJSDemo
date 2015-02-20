//
//  Renderer_SDL2.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Renderer.h"

#include <SDL.h>

class Renderer_SDL2 : public Renderer {
    SDL_Window* m_win;
    SDL_Renderer* m_rend;
public:
    Renderer_SDL2(SDL_Window* win, SDL_Renderer* rend);

    void set_swap_interval(int swap);
    void update_window_size();
    void clear();
    void draw_rect_fill(const Rect& r, const Color& c);
    void present();

private:
    void set_draw_color(const Color& c);
};
