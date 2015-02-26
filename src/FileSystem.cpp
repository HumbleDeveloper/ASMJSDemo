//
//  FileSystem.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "FileSystem.h"

#include <unistd.h>

FILE* FileSystem::open(const std::string &path, const std::string& mode)
{
    FILE* fp = fopen(path.c_str(), mode.c_str());
    return fp;
}

bool FileSystem::exists(const std::string &path)
{
    return access(path.c_str(), F_OK) == 0;
}

std::string FileSystem::join_path(const std::string &dir, const std::string &file)
{
    std::string ret = dir;
    if (ret[ret.length() - 1] != '/') {
        ret += "/";
    }
    if (file[0] == '/') {
        ret += file.substr(1);
    } else {
        ret += file;
    }
    return ret;
}