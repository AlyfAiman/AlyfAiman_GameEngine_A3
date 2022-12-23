#pragma once
#include <string>

class Texture
{

public:

	// Holds texture variables such as width & height.
	// Variables will then be called by classes that need to access them.
	~Texture();
	int width, height;
	unsigned int textureID, refCount;

	// Obtains the wanted texture. The function will access the wanted texture in the specific file directory.
	static Texture* createTexture(const std::string& path);
};