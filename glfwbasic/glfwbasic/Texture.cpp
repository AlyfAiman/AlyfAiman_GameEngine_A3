#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#include <glad/glad.h>
#include <iostream>

Texture::~Texture() 
{
	refCount--;
	std::cout << "Refcount after deleted gameObjects: " << refCount << std::endl;
}

Texture* Texture::createTexture(const std::string& path) 
{

	int width, height, nrChannels;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);

	if (data) 
	{
		Texture* texture = new Texture();
		texture->width = width;
		texture->height = height;

		glGenTextures(1, &(texture->textureID));
		glBindTexture(GL_TEXTURE_2D, (texture->textureID));

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

		glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		GLint internalFormat = nrChannels == 4 ? GL_RGBA : GL_RGB;
		GLenum format = nrChannels == 4 ? GL_RGBA : GL_RGB;
		glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, GL_UNSIGNED_BYTE, data);

		printf("Loaded texture: %s\n", path.c_str());
		stbi_image_free(data);
		return texture;
	}
	else 
	{
		stbi_image_free(data);
		printf("Failed to load texture: %s\n", path.c_str());
	}
	stbi_image_free(data);
	return nullptr;

}