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
    Rect(const Vector2i& size) : x(0), y(0), w(size.x), h(size.y) {}
    Rect(const Vector2i& position, const Vector2i& size) : x(position.x), y(position.y), w(size.x), h(size.y) {}

    Vector2i bottom_right() const { return Vector2i(x + w, y + h); }

    bool empty() const {
        return w == 0 && h == 0;
    }

    bool contains(const Vector2i& point) const {
        Vector2i br = bottom_right();

        if (point.x >= x && point.y >= y
            && point.x < br.x && point.y < br.y) {
            return true;
        }
        return false;
    }

    bool intersects(const Rect& r) {
        if (empty() || r.empty()) return false;

        if (r.x < x + w && x < r.x + r.w && r.y < y + h)
            return y < r.y + r.h;

        return false;
    }
};