//
//  Rect.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Vector2.h"

struct Rect {
    int x, y;
    int w, h;

    Rect() : x(0), y(0), w(0), h(0) {}
    Rect(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}
    Rect(const Vector2i& position, const Vector2i& size) : x(position.x), y(position.y), w(size.x), h(size.y) {}
};