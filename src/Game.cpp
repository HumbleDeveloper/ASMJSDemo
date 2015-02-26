//
//  Game.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Game.h"

#include <cmath>

Game::Game(Renderer& r) : m_renderer(r), m_Player(r.load_texture("spaceship"))
{
    m_renderer.set_swap_interval(1);

    m_renderables.push_back(&m_Player);

    m_renderer.set_logical_size(Vector2i(768, 480));

    m_Player.set_position(Vector2i(m_renderer.logical_size().x / 2, m_renderer.logical_size().y - m_Player.size().y / 2));
    m_Player.set_center(m_Player.size() / 2);
    m_Player.set_move_range(Vector2i(m_Player.center().x, m_Player.position().y), Vector2i(m_renderer.logical_size().x - m_Player.center().x, m_Player.position().y));
}

void Game::apply_input(Game::InputForce force, int value)
{
    if (force >= 0 && force < InputForce_MAX) {
        inputValues[force] = value;
    }
}

#define PLAYER_X_SPEED 0.02

void Game::update(float delta)
{
    if (inputValues[InputForce_X_AXIS]) {
        int distance = inputValues[InputForce_X_AXIS] * delta * PLAYER_X_SPEED;
        m_Player.move_position_by(Vector2i(distance, 0));
    }
}

void Game::render()
{
    m_renderer.clear();

    for( auto it = m_renderables.begin(); it != m_renderables.end(); ++it)
    {
        (*it)->render( m_renderer );
    }

    m_renderer.present();
}