//
//  Sprite.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "Sprite.h"
#include "Renderer.h"

Sprite::Sprite(TextureRef texture)
    : m_texture(texture),
    m_size(m_texture->size())
{
}

void Sprite::render(Renderer& rend)
{
    rend.draw_texture(m_texture, m_position - m_center);
}

void Sprite::move_position_by(const Vector2i &adjust_position)
{
    m_position += adjust_position;
}