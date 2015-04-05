//
//  Player.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Player.h"

Player::Player(TextureRef texture, float torpedo_reload_time) :
    Sprite(texture),
    m_torpedo_delay(0.0f),
    m_torpedo_reload_time(torpedo_reload_time),
    m_normalized_position(0.0f)
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
    } else {
        update_normalized_position();
    }
}

void Player::set_position(const Vector2f &position)
{
    Sprite::set_position(position);
    update_normalized_position();
}

void Player::update_normalized_position()
{
    Vector2f range = (m_max - m_min) / 2;
    Vector2f mid = position() - m_min - range;
    m_normalized_position = mid / range;
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
    m_torpedo_delay = m_torpedo_reload_time;

    return true;
}
