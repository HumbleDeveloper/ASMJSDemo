//
//  Renderer.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Renderer.h"

void Renderer::draw_texture(TextureRef texture, const Vector2i &dst_pos, float angle)
{
    const Vector2i& size = texture->size();
    Rect src(size);
    Rect dst(dst_pos, size);

    draw_texture(texture, src, dst, angle);
}