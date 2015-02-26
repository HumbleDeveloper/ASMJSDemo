//
//  Renderable.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

class Renderer;

struct Renderable {
    virtual void render(Renderer& rend) = 0;
};