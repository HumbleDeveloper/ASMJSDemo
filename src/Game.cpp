//
//  Game.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Game.h"

#include <cmath>

Game::Game(Renderer& r) : m_renderer(r), m_angle(0.0f)
{
    m_renderer.set_swap_interval(1);
}

void Game::update(float delta)
{
    m_angle += 90.0f * delta;
    if (m_angle > 350.0f) m_angle -= 360.0f;
}

void Game::render()
{
    int width = m_renderer.width();
    int height = m_renderer.height();

    int radius = width / 2 * 0.45;

    float rad = m_angle / 180.0f * M_PI;
    float x = radius * std::cos(rad);
    float y = radius * std::sin(rad);

    Rect r(x + width / 4, y + height / 4, width / 2, height / 2);

    m_renderer.clear();

    m_renderer.draw_rect_fill(r, Color(255, 0, 0));

    m_renderer.present();
}