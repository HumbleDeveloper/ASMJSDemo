//
//  Projectile.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "Projectile.h"

Projectile::Projectile(TextureRef texture, const Vector2f& velocity, const Rectf& bounds) : Entity(texture, velocity, bounds) {
    set_center(size() / 2);
}

