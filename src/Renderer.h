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
#include "Texture.h"

#include <string>

class Renderer {
protected:
    Vector2i m_size, m_logical_size;
    bool m_logical_set;
public:
    Renderer() : m_logical_set(false) {}
    virtual ~Renderer() {}

    virtual void set_logical_size(Vector2i size, bool keepAspect = true) = 0;

    virtual void set_swap_interval(int swap) = 0;
    virtual void update_window_size() = 0;
    virtual void clear(const Color& c = Color()) = 0;
    virtual void present() = 0;
    virtual void draw_rect_fill(const Recti& r, const Color& c) = 0;

    virtual TextureRef load_texture(const std::string& name) = 0;
    virtual void draw_texture(TextureRef texture, const Vector2i& dst, float angle = 0.0f);
    virtual void draw_texture(TextureRef texture, const Recti& src, const Recti& dst, float angle = 0.0f) = 0;

    const Vector2i& size() const { return m_size; }
    int width() const { return m_size.x; }
    int height() const { return m_size.y; }

    const Vector2i& logical_size() const { return m_logical_size; }
};