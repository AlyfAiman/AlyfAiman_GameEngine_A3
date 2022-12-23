#include "SimpleAllocator.h"
#include "Texture.h"
#include <stdio.h>

Texture* texture;
std::map<std::string, Texture*> resourceMap;

Texture* AlyfGE::SimpleAllocator::getTexture(std::string path)
{
    std::cout << "Path is: " << path << std::endl;

    // check if resource is in the map
    if (!resourceMap.empty()) 
    {
        if (resourceMap.find(path) == resourceMap.end()) 
        {
            texture = Texture::createTexture(path);
        }
        else 
        {
            texture->refCount++;
            std::cout << "Refcount = " << texture->refCount << std::endl;
            return texture;
        }
    }

    else if (resourceMap.empty()) 
    {
        printf("Check 2");
        texture = Texture::createTexture(path);
    }
    else if (texture->refCount == 0) 
    {
        std::cout << "Deleted" << std::endl;
    }


    // check if resource is created
    if (texture != NULL) 
    {
        texture->refCount++;
        std::cout << "Refcount = " << texture->refCount << std::endl;
        resourceMap.insert(std::pair<std::string, Texture*>(path, texture));
        return texture;
    }
    else 
    {
        printf("Resource creation failed.\n");
        return 0;
    }
}

// Declaration
void AlyfGE::SimpleAllocator::decreaseDelete() 
{
    texture->refCount--;
    if (texture->refCount == 0) 
    {
        resourceMap.clear();
        printf("All referencing gameObject has been deleted. Clearing map.\n");
    }
}