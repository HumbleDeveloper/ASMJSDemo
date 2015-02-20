//
//  Renderer.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Color.h"
#include "Rect.h"

class Renderer {
protected:
    int m_w, m_h;
public:
    Renderer() {}
    virtual ~Renderer() {}

    virtual void set_swap_interval(int swap) = 0;
    virtual void update_window_size() = 0;
    virtual void clear() = 0;
    virtual void present() = 0;
    virtual void draw_rect_fill(const Rect& r, const Color& c) = 0;

    int width() { return m_w; }
    int height() { return m_h; }
};