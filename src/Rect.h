//
//  Rect.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

struct Rect {
    int x, y;
    int w, h;

    Rect() : x(0), y(0), w(0), h(0) {}
    Rect(int _x, int _y, int _w, int _h) : x(_x), y(_y), w(_w), h(_h) {}
};