//
//  Sprite.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

#include "Renderable.h"
#include "Texture.h"

#include "Vector2.h"

class Sprite : public Renderable {
    TextureRef m_texture;
    Vector2i m_position;
    Vector2i m_size;
    Vector2i m_center;
public:
    Sprite(TextureRef m_texture);
    virtual void render(Renderer& rend);

    void set_position(const Vector2i& position) { m_position = position; }
    const Vector2i& position() const { return m_position; }

    void move_position_by(const Vector2i& adjust_position);

    void set_center(const Vector2i& center) { m_center = center; }
    const Vector2i& center() const { return m_center; }

    const Vector2i& size() const { return m_size; }
};