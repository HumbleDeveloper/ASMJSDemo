//
//  Projectile.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

#include "Entity.h"

class Projectile : public Entity {
public:
    Projectile(TextureRef texture, const Vector2f& vector, const Rectf& bounds);
};