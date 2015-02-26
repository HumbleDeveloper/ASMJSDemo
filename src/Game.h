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
    Renderer& m_renderer;
    Player m_Player;

    std::list<Renderable*> m_renderables;
public:
    Game(Renderer& r);

    void update(float delta);
    void render();
};