//
//  Game.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#include "Game.h"

#ifdef WIN32
#define _USE_MATH_DEFINES
#include <math.h>
#endif
#include <cmath>
#include <cstdlib>
#include <ctime>

#include <algorithm>

Game::Game(Renderer& r) : m_renderer(r), m_Player(r.load_texture("spaceship"))
{
    m_renderer.set_swap_interval(1);

    add_renderable(&m_Player);

    m_renderer.set_logical_size(Vector2i(640, 400));

    float ypos = m_renderer.logical_size().y - m_Player.size().y / 2;

    m_Player.set_move_range(Vector2f(m_Player.center().x, ypos), Vector2f(m_renderer.logical_size().x - m_Player.center().x, ypos));
    m_Player.set_position(Vector2f(m_renderer.logical_size().x / 2.0f, ypos));

    for (int i = 0; i < InputForce_MAX; ++i) {
        inputValues[i] = 0;
    }

    std::srand((unsigned int)std::time(0));
}

void Game::apply_input(Game::InputForce force, int value)
{
    if (force >= 0 && force < InputForce_MAX) {
        inputValues[force] = value;
    }
}

#define PLAYER_X_SPEED 0.02f
#define ENEMY_MAX 3
#define ENEMY_PROBABILITY 5
#define ENEMY_ROTATION 45.0f
#define ENEMY_SPEED 64.0f
#define ENEMY_START_BASE 80.0f
#define ENEMY_START_RANGE 50.0f

void Game::update(float delta)
{
    for (auto it = m_updatables.begin(); it != m_updatables.end(); ) {
        bool keep = (*it)->update( delta );
        if (!keep) {
            Renderable *o = dynamic_cast<Renderable*>(*it);
            ++it;
            remove_renderable(o);
        } else {
            ++it;
        }
    }

    if (inputValues[InputForce_X_AXIS]) {
        float distance = inputValues[InputForce_X_AXIS] * delta * PLAYER_X_SPEED;
        m_Player.move_position_by(Vector2f(distance, 0.0f));
    }
    if (inputValues[InputForce_SHOOT]) {
        fire_torpedo(m_Player);
    }
    check_enemies();
    check_collisions();
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

void Game::remove_renderable(Renderable *renderable, bool updatable_also)
{
    if (renderable == 0) return;

    for (int i = 0; i < MAX_LAYERS; ++i) {
        m_renderables[i].remove(renderable);
    }
    if (updatable_also) {
        Updatable *updatable = dynamic_cast<Updatable*>(renderable);
        if (updatable) {
            m_updatables.remove(updatable);
        }
    }
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

static float random(float range)
{
    int r = std::rand();
    return float(r) / RAND_MAX * range;
}

// This would be easier with C++11 variadic templates
template <typename T, typename T1, typename T2>
static typename std::list<T>::iterator find_or_create(std::list<T>& list, const T1& a1, const T2& a2)
{
    auto it = list.begin();
    for (; it != list.end(); ++it) {
        if (!it->active()) break;
    }
    if (it == list.end()) {
        list.push_back(T(a1, a2));
        it = --list.end();
    }
    return it;
}
template <typename T, typename T1, typename T2, typename T3>
static typename std::list<T>::iterator find_or_create(std::list<T>& list, const T1& a1, const T2& a2, const T3& a3)
{
    auto it = list.begin();
    for (; it != list.end(); ++it) {
        if (!it->active()) break;
    }
    if (it == list.end()) {
        list.push_back(T(a1, a2, a3));
        it = --list.end();
    }
    return it;
}
template <typename T, typename T1, typename T2, typename T3, typename T4>
static typename std::list<T>::iterator find_or_create(std::list<T>& list, const T1& a1, const T2& a2, const T3& a3, const T4& a4)
{
    auto it = list.begin();
    for (; it != list.end(); ++it) {
        if (!it->active()) break;
    }
    if (it == list.end()) {
        list.push_back(T(a1, a2, a3, a4));
        it = --list.end();
    }
    return it;
}

void Game::fire_torpedo(Player &player)
{
    if (!player.can_shoot() || !player.fire_torpedo()) {
        return;
    }

    auto it = find_or_create(m_projectiles, m_renderer.load_texture("torpedo"), Vector2f(0, -TORPEDO_VELOCITY), Recti(m_renderer.logical_size()).as<float>());

    it->set_position(player.position());
    it->activate();

    add_renderable(&(*it), 1);
}

template <typename T>
bool isActive(const T& o) {
    return o.active();
}

void Game::check_collisions()
{
    for (auto it_p = m_projectiles.begin(); it_p != m_projectiles.end(); ++it_p) {
        if (!it_p->active()) continue;
        for (auto it_e = m_enemies.begin(); it_e != m_enemies.end(); ++it_e) {
            if (!it_e->active()) continue;

            if (it_p->collides_with(*it_e)) {
                it_p->deactivate();
                it_e->deactivate();

                Rectf bounds = Recti(m_renderer.logical_size()).as<float>();

                auto it = find_or_create(m_explosions, m_renderer.load_texture("explosion"), bounds);
                it->set_duration(0.35f);
                it->set_velocity(it_e->velocity() * 0.75f);
                it->set_position(it_e->position());
                it->activate();
                add_renderable(&(*it), 0);
            }
        }
        if (!it_p->active()) {
            Rectf bounds = Recti(m_renderer.logical_size()).as<float>();

            auto it = find_or_create(m_explosions, m_renderer.load_texture("explosion"), bounds);
            it->set_duration(0.2f);
            it->set_velocity(it_p->velocity() / 2);
            it->set_position(it_p->position());
            it->activate();
            add_renderable(&(*it), 0);
        }
    }
}

void Game::check_enemies()
{
    if (std::count_if(m_enemies.begin(), m_enemies.end(), isActive<Enemy>) < ENEMY_MAX) {
        if (random(100.0f) < ENEMY_PROBABILITY) {
            float angle = random(90.0f);
            angle -= 45.0f;
            if (random(100.0f) >= 50.0f) {
                angle += 180.0f;
            }
            angle *= M_PI / 180.0f;

            Vector2f velocity(std::cos(angle), std::sin(angle));

            auto it = find_or_create(m_enemies, m_renderer.load_texture("ufo"), velocity * ENEMY_SPEED, Recti(m_renderer.logical_size()).as<float>(), ENEMY_ROTATION);

            Vector2f position(-it->size().x / 2, ENEMY_START_BASE + random(ENEMY_START_RANGE));
            if (velocity.x < 0) {
                position.x = m_renderer.logical_size().x + it->size().x / 2;
            }
            it->set_position(position);
            it->activate();
            add_renderable(&(*it), 0);
        }
    }
}
