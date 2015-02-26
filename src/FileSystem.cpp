//
//  FileSystem.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "FileSystem.h"

#ifndef WIN32
#define PATH_SEPARATOR "/"

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
#else // the windows code-path
#define PATH_SEPARATOR "\\"

#include <io.h>

bool FileSystem::exists(const std::string &path)
{
	return _access(path.c_str(), 0) == 0;
}


FILE* FileSystem::open(const std::string &path, const std::string& mode)
{
    FILE* fp = 0;
	fopen_s(&fp, path.c_str(), mode.c_str());
    return fp;
}
#endif


std::string FileSystem::join_path(const std::string &dir, const std::string &file)
{
    std::string ret = dir;
	char last_c = ret[ret.length() - 1];
    if (last_c != '/' && last_c != '\\') {
        ret += PATH_SEPARATOR;
    }
    if (file[0] == '/' || file[0] == '\\') {
        ret += file.substr(1);
    } else {
        ret += file;
    }
    return ret;
}