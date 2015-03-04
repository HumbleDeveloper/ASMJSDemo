//
//  Explosion.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 3/4/15.
//
//

#include "Explosion.h"

Explosion::Explosion(TextureRef texture, const Rectf& bounds)
    : Entity(texture, Vector2f(), bounds), m_duration(0.0f)
{
}

bool Explosion::update(float delta)
{
    m_duration -= delta;

    if (m_duration <= 0.0f) {
        deactivate();
    }

    return Entity::update(delta);
}