#pragma once
#include <iostream>
#include <glad/glad.h>
#include <string>
#include <map>
#include "Texture.h"


// Simple Allocator is used to free up RAM space to prevent crashing.

namespace AlyfGE
{
	class SimpleAllocator
	{
	public:
		
		// Function that gets the texture from users computer path.
		static Texture* getTexture(std::string path);

		// Checks the refCount, which is the number of references to the loaded texture and decrease
		// count when the components refering to the textures are removed.
		void decreaseDelete();
	};
}