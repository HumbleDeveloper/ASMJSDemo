//
//  Color.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/20/15.
//
//

#pragma once

struct Color {
    unsigned char r,g,b,a;

    Color() : r(0), g(0), b(0), a(255) {}
    Color(char _r, char _g, char _b, char _a = 0) : r(_r), g(_g), b(_b), a(_a) {}
};