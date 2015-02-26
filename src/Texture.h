//
//  Texture.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

#include "Vector2.h"

class Texture;
typedef Texture* TextureRef;

class Texture {
protected:
    Vector2i m_size;

    Texture() {}
    virtual ~Texture() {}
public:
    int width() { return m_size.x; }
    int height() { return m_size.y; }
    const Vector2i& size() { return m_size; }

    static TextureRef NullTexture;
};
