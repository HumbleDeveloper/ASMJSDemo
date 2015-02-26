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
    Vector2i m_position;
    TextureRef m_texture;
public:
    Sprite(TextureRef m_texture);
    virtual void render(Renderer& rend);

    void set_position(const Vector2i& position) { m_position = position; }
    const Vector2i& position() { return m_position; }
};