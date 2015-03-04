//
//  Entity.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 3/3/15.
//
//

#pragma once

#include "Sprite.h"
#include "Updatable.h"
#include "Rect.h"

class Entity : public Sprite, public Updatable {
    bool m_active;
    Vector2f m_velocity;
    Rect m_bounds;
public:
    Entity(TextureRef texture, const Vector2f& vector, const Rect& bounds);

    bool active() const { return m_active; }
    void activate() { m_active = true; }

    Vector2f velocity() const { return m_velocity; }
    void set_velocity(const Vector2f& velocity) { m_velocity = velocity; }

    virtual bool update(float delta);
};