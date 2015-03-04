//
//  Player.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Player.h"

#define TORPEDO_DELAY 0.5f

Player::Player(TextureRef texture) : Sprite(texture), m_torpedo_delay(0.0f)
{
    set_center(size() / 2);
}

void Player::set_move_range(const Vector2f& min, const Vector2f& max)
{
    m_min = min;
    m_max = max;
    move_position_by(Vector2f());
}

void Player::move_position_by(const Vector2f& adjust_position)
{
    Sprite::move_position_by(adjust_position);
    if (position().x < m_min.x) {
        set_position(m_min);
    } else if (position().x > m_max.x) {
        set_position(m_max);
    }
}

bool Player::update(float delta)
{
    m_torpedo_delay -= delta;
    if (m_torpedo_delay < 0.0f) m_torpedo_delay = 0.0f;

    return true;
}

bool Player::can_shoot() const
{
    return m_torpedo_delay == 0.0f;
}

bool Player::fire_torpedo()
{
    m_torpedo_delay = TORPEDO_DELAY;

    return true;
}
