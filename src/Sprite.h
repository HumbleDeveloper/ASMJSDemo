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
    Vector2f m_position;
    Vector2f m_size;
    Vector2f m_center;
    float m_angle;
public:
    Sprite(TextureRef m_texture);
    virtual void render(Renderer& rend);

    void set_position(const Vector2f& position) { m_position = position; }
    const Vector2f& position() const { return m_position; }
    void move_position_by(const Vector2f& adjust_position);

    void set_angle(float angle) { m_angle = angle; }
    float angle() { return m_angle; }
    void rotate_by(float angle) { m_angle += angle; }

    void set_center(const Vector2f& center) { m_center = center; }
    const Vector2f& center() const { return m_center; }

    const Vector2f& size() const { return m_size; }
};