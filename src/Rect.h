//
//  Rect.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

#include "Vector2.h"

template <typename T>
struct Rect {
    T x, y;
    T w, h;

    Rect() : x(T()), y(T()), w(T()), h(T()) {}
    Rect(T _x, T _y, T _w, T _h) : x(_x), y(_y), w(_w), h(_h) {}
    Rect(const Vector2<T>& size) : x(T()), y(T()), w(size.x), h(size.y) {}
    Rect(const Vector2<T>& position, const Vector2<T>& size) : x(position.x), y(position.y), w(size.x), h(size.y) {}

    template<typename O>
    Rect<O> as() const {
        return Rect<O>(O(x), O(y), O(w), O(h));
    }

    Vector2<T> bottom_right() const { return Vector2<T>(x + w, y + h); }

    bool empty() const {
        return w == T() && h == T();
    }

    bool contains(const Vector2<T>& point) const {
        Vector2<T> br = bottom_right();

        if (point.x >= x && point.y >= y
            && point.x < br.x && point.y < br.y) {
            return true;
        }
        return false;
    }

    bool intersects(const Rect<T>& r) {
        if (empty() || r.empty()) return false;

        if (r.x < x + w && x < r.x + r.w && r.y < y + h)
            return y < r.y + r.h;

        return false;
    }
};

typedef Rect<int> Recti;
typedef Rect<float> Rectf;
