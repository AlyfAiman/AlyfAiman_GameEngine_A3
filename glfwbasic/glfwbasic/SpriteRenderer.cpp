#include "SpriteRenderer.h"
#include <glad/glad.h>
#include <iostream>
#include "InputSystem.h"

AlyfGE::SimpleAllocator* simpleAllocator;
AlyfGE::SpriteRenderer::SpriteRenderer(GameObj* go) :BaseComp(go) 
{

}

AlyfGE::SpriteRenderer::~SpriteRenderer() 
{

	simpleAllocator->decreaseDelete();

}

const float AlyfGE::SpriteRenderer::getWidth() 
{
	return width;
}

const float AlyfGE::SpriteRenderer::getHeight() 
{
	return height;
}

void AlyfGE::SpriteRenderer::loadTexture(const std::string& path) 
{
	texture = SimpleAllocator::getTexture(path);
	width = texture->width;
	height = texture->height;
}

void AlyfGE::SpriteRenderer::render() 
{
	if (texture) 
	{
		glPushMatrix();

		glTranslatef(owner->transformation->Position.x, owner->transformation->Position.y, owner->transformation->Position.z);
		glRotatef(owner->angle, 0, 0, 1);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture->textureID);
		colorTinting(red, green, blue, alpha);
		resize(width, height);
		//Ready to render mesh

		float halfW = width / 2.0f;
		float halfH = height / 2.0f;

		glBegin(GL_QUADS);

		glTexCoord2f(0, 1); glVertex2f(-halfW, halfH);
		glTexCoord2f(0, 0); glVertex2f(-halfW, -halfH);
		glTexCoord2f(1, 0); glVertex2f(halfW, -halfH);
		glTexCoord2f(1, 1); glVertex2f(halfW, halfH);

		glEnd();

		glBindTexture(GL_TEXTURE_2D, 0);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_BLEND);

		glPopMatrix();
	}
}

void AlyfGE::SpriteRenderer::colorTinting(float r, float g, float b, float a) 
{
	float currRed = r + ((255 - r) * .10);
	currRed = currRed / 255.0f;
	float currGreen = g + ((255 - g) * .10);
	currGreen = currGreen / 255.0f;
	float currBlue = b + ((255 - b) * .10);
	currBlue = currBlue / 255.0f;
	float currAlpha = a + ((255 - a) * .10);
	currAlpha = currAlpha / 255.0f;

	return glColor4f(currRed, currGreen, currBlue, currAlpha);
}

float AlyfGE::SpriteRenderer::resize(float w, float h) 
{
	width = w;
	height = h;
	return width, height;
}

void AlyfGE::SpriteRenderer::update(float deltaTime) 
{

	if (Input::InputSystem::GetKey(ArrowUp)) 
	{
		if (redM) 
		{
			red -= 10;
			if (red <= 0) 
			{
				redM = false;
			}
		}
		else 
		{
			red += 10;
			if (red == 255) 
			{
				redM = true;
			}
		}
	}
	else if (Input::InputSystem::GetKey(ArrowDown)) 
	{
		if (blueM) 
		{
			blue -= 10;
			if (blue <= 0) 
			{
				blueM = false;
			}
		}
		else 
		{
			blue += 10;
			if (blue == 255) 
			{
				blueM = true;
			}
		}
	}
	else if (Input::InputSystem::GetKey(ArrowLeft)) 
	{
		if (greenM) 
		{
			green -= 10;
			if (green <= 0) 
			{
				greenM = false;
			}
		}
		else 
		{
			green += 10;
			if (green == 255) 
			{
				greenM = false;
			}
		}
	}
	else if (Input::InputSystem::GetKey(ArrowRight)) 
	{
		if (alphaM) 
		{
			alpha -= 10;
			if (alpha <= 0) 
			{
				alphaM = false;
			}
		}
		else 
		{
			alpha += 10;
			if (alpha == 255) 
			{
				alphaM = true;
			}
		}
	}
	else if (Input::InputSystem::GetKey(R)) 
	{
		std::cout << "Resizing sprites: " << std::endl;
		std::cin >> width >> height;
		std::cout << "Width = " << width << std::endl;
		std::cout << "Height = " << height << std::endl;
	}
}