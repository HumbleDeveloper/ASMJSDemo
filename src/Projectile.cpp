//
//  Projectile.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "Projectile.h"

Projectile::Projectile(TextureRef texture, const Vector2f& velocity) : Sprite(texture), m_active(false), m_velocity(velocity) {
    set_center(size() / 2);
}

bool Projectile::update(float delta)
{
    move_position_by(m_velocity * delta);

    if (position().y < -size().y) {
        m_active = false;
    }

    return m_active;
}