//
//  FileSystem.h
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#pragma once

#include <string>

namespace FileSystem {
    FILE* open(const std::string& path, const std::string& mode = "r");

    bool exists(const std::string& path);

    std::string join_path(const std::string& dir, const std::string& file);
}