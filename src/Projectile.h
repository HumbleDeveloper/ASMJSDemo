//
//  Projectile.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

#include "Sprite.h"
#include "Updatable.h"

class Projectile : public Sprite, public Updatable {
    bool m_active;
    Vector2f m_velocity;
public:
    Projectile(TextureRef texture, const Vector2f& vector);

    bool active() const { return m_active; }
    void activate() { m_active = true; }

    Vector2f velocity() const { return m_velocity; }
    void set_velocity(const Vector2f& velocity) { m_velocity = velocity; }

    bool update(float delta);
};