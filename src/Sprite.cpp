//
//  Sprite.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "Sprite.h"
#include "Renderer.h"

Sprite::Sprite(TextureRef texture) : m_texture(texture)
{

}

void Sprite::render(Renderer& rend)
{
    rend.draw_texture(m_texture, m_position);
}