//
//  Texture.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "Texture.h"

class NullTexture : public Texture {
public:
    NullTexture() {}
};

static NullTexture nullTexture;

TextureRef Texture::NullTexture = &nullTexture;
