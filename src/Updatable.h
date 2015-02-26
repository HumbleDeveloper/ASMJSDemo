//
//  Updatable.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

struct Updatable {
    virtual bool update(float delta) = 0;
};
