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

    m_Player.set_position(Vector2i(50));
}

void Game::update(float delta)
{
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