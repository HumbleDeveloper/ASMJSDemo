//
//  Game.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Renderer.h"
#include "Player.h"
#include "Renderable.h"

#include <list>

class Game {
public:
    enum InputForce {
        InputForce_X_AXIS,
        InputForce_Y_AXIS,
        InputForce_SHOOT,
        InputForce_START,
        InputForce_MAX,
    };
private:
    Renderer& m_renderer;
    Player m_Player;

    int inputValues[InputForce_MAX];

    std::list<Projectile> m_projectiles;

    static const int MAX_LAYERS = 2;
    static const int TORPEDO_VELOCITY = 128;

    std::list<Renderable*> m_renderables[MAX_LAYERS];
    std::list<Updatable*> m_updatables;
public:
    Game(Renderer& r);

    void apply_input(InputForce force, int value);

    void update(float delta);
    void render();

    void add_renderable(Renderable* renderable, int layer = 0);

    void fire_torpedo(Player& player);
};