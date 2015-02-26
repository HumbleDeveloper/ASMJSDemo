//
//  Player.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Player.h"

Player::Player(TextureRef texture) : Sprite(texture)
{
    
}

void Player::set_move_range(const Vector2i& min, const Vector2i& max)
{
    m_min = min;
    m_max = max;
    move_position_by(Vector2i());
}

void Player::move_position_by(const Vector2i& adjust_position)
{
    Sprite::move_position_by(adjust_position);
    if (position().x < m_min.x) {
        set_position(m_min);
    } else if (position().x > m_max.x) {
        set_position(m_max);
    }
}
