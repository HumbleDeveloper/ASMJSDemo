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

class Game {
    Player m_Player;
    Renderer& m_renderer;

    float m_angle;
public:
    Game(Renderer& r);

    void update(float delta);
    void render();
};