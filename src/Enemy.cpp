//
//  Enemy.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/27/15.
//
//

#include "Enemy.h"

Enemy::Enemy(TextureRef texture, const Vector2f& velocity, const Rectf& bounds, float rotate_speed)
    : Entity(texture, velocity, bounds),
    m_rotate_speed(rotate_speed)
{
    set_center(size() / 2);
}

bool Enemy::update(float delta)
{
    rotate_by(m_rotate_speed * delta);
    return Entity::update(delta);
}