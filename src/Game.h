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

    std::list<Renderable*> m_renderables;
public:
    Game(Renderer& r);

    void apply_input(InputForce force, int value);

    void update(float delta);
    void render();
};