//
//  Player.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Sprite.h"
#include "Projectile.h"

#include <vector>

class Player : public Sprite, public Updatable {
    Vector2f m_min, m_max;

    float m_torpedo_delay;
    float m_torpedo_reload_time;
public:
    Player(TextureRef texture, float torpedo_reload_time);

    void set_move_range(const Vector2f& min, const Vector2f& max);
    void move_position_by(const Vector2f& adjust_position);

    bool can_shoot() const;
    bool fire_torpedo();

    bool update(float delta);
};