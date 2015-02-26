//
//  Player.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Sprite.h"

class Player : public Sprite {
    Vector2i m_min, m_max;
public:
    Player(TextureRef texture);

    void set_move_range(const Vector2i& min, const Vector2i& max);
    void move_position_by(const Vector2i& adjust_position);
};