//
//  Vector2.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

template <typename T>
struct Vector2 {
    T x, y;

    Vector2() : x(T()), y(T()) {}
    Vector2(T _v) : x(_v), y(_v) {}
    Vector2(T _x, T _y) : x(_x), y(_y) {}
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;