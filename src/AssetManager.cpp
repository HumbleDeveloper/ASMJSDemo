//
//  AssetManager.cpp
//  HumbleASMJSDemo
//
//  Created by Edward Rudd on 2/25/15.
//
//

#include "AssetManager.h"
#include "FileSystem.h"

#include <stdexcept>

AssetManager* AssetManager::m_defaultManager = 0;

AssetManager& AssetManager::DefaultManager()
{
    if(m_defaultManager) {
        return *m_defaultManager;
    } else {
        throw std::runtime_error("No Default Manager Configured!");
    }
}

AssetManager::AssetManager()
{
}

void AssetManager::add_path(const std::string &path)
{
    m_searchpaths.push_back(path);
}

std::string AssetManager::find_resource(const std::string &name, const std::string& type)
{
    std::string filename = name + "." + type;
    for (auto it = m_searchpaths.begin(); it != m_searchpaths.end(); ++it) {
        std::string full_path = FileSystem::join_path(*it, filename);
        if (FileSystem::exists(full_path))
        {
            return full_path;
        }
    }
    return "";
}