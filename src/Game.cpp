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

    add_renderable(&m_Player);

    m_renderer.set_logical_size(Vector2i(640, 400));

    float ypos = m_renderer.logical_size().y - m_Player.size().y / 2;

    m_Player.set_move_range(Vector2f(m_Player.center().x, ypos), Vector2f(m_renderer.logical_size().x - m_Player.center().x, ypos));
    m_Player.set_position(Vector2f(m_renderer.logical_size().x / 2, ypos));

    for (int i = 0; i < InputForce_MAX; ++i) {
        inputValues[i] = 0;
    }
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
    for (auto it = m_updatables.begin(); it != m_updatables.end(); ) {
        bool keep = (*it)->update( delta );
        if (!keep) {
            for (int i = 0; i < MAX_LAYERS; ++i) {
                m_renderables[i].remove(dynamic_cast<Renderable*>(*it));
            }
            it = m_updatables.erase(it);
        } else {
            ++it;
        }
    }

    if (inputValues[InputForce_X_AXIS]) {
        int distance = inputValues[InputForce_X_AXIS] * delta * PLAYER_X_SPEED;
        m_Player.move_position_by(Vector2f(distance, 0));
    }
    if (inputValues[InputForce_SHOOT]) {
        fire_torpedo(m_Player);
    }
}

void Game::add_renderable(Renderable *renderable, int layer)
{
    if (!renderable) return;

    Updatable* updatable = dynamic_cast<Updatable*>(renderable);
    if (updatable) {
        m_updatables.push_back(updatable);
    }
    m_renderables[layer].push_back(renderable);
}

void Game::render()
{
    m_renderer.clear();

//    m_renderer.draw_rect_fill(Rect(Vector2i(), m_renderer.logical_size()), Color(100, 50, 20));

    for (int l = MAX_LAYERS - 1; l >= 0; --l) {
        for( auto it = m_renderables[l].begin(); it != m_renderables[l].end(); ++it) {
            (*it)->render( m_renderer );
        }
    }

    m_renderer.present();
}

void Game::fire_torpedo(Player &player)
{
    if (!player.can_shoot() || !player.fire_torpedo()) {
        return;
    }

    auto it = m_projectiles.begin();

    for (; it != m_projectiles.end(); ++it) {
        if (!it->active()) break;
    }
    if (it == m_projectiles.end()) {
        m_projectiles.push_back(Projectile(m_renderer.load_texture("torpedo"), Vector2f(0, -TORPEDO_VELOCITY), Rect(m_renderer.logical_size())));
        it = --m_projectiles.end();
    }

    it->set_position(player.position());
    it->activate();

    add_renderable(&(*it), 1);
}