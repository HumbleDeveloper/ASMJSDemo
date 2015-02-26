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

    template<typename T2>
    const Vector2<T2> as() const {
        return Vector2<T2>(T2(x), T2(y));
    }

    Vector2<T>& operator -=(const Vector2<T>& o) {
        this->x -= o.x;
        this->y -= o.y;

        return *this;
    }

    Vector2<T>& operator +=(const Vector2<T>& o) {
        this->x += o.x;
        this->y += o.y;

        return *this;
    }

    const Vector2<T> operator -(const Vector2<T>& o) const {
        return Vector2<T>(x - o.x, y - o.y);
    }

    const Vector2<T> operator +(const Vector2<T>& o) const {
        return Vector2<T>(x + o.x, y + o.y);
    }

    const Vector2<T> operator /(const Vector2<T>& o) const {
        return Vector2<T>(x / o.x, y / o.y);
    }

    const Vector2<T> operator /(T o) const {
        return Vector2<T>(x / o, y / o);
    }

    const Vector2<T> operator *(const Vector2<T>& o) const {
        return Vector2<T>(x * o.x, y * o.y);
    }

    const Vector2<T> operator *(T o) const {
        return Vector2<T>(x * o, y * o);
    }
};

typedef Vector2<float> Vector2f;
typedef Vector2<int> Vector2i;