#pragma once
#include "BaseComp.h"
#include "GameObj.h"
#include "Texture.h"
#include "SimpleAllocator.h"

namespace AlyfGE 
{
	class SpriteRenderer : public BaseComp
	{
	public:

		SpriteRenderer(GameObj* go);
		~SpriteRenderer();

		void update(float deltaTime)override;

		/**Load the chosen texture from the designated path*/
		void loadTexture(const std::string& path);

		/**Renders the chosen texture*/
		void render() override;


		const float getWidth();
		const float getHeight();

		/**Change the image or properties of the textures. Such as the colors or its size*/
		void colorTinting(float r, float g, float b, float a);
		float resize(float w, float h);

		/**Default values for the textures colors.*/
		float red = 255.0f;
		float green = 255.0f;
		float blue = 255.0f;
		float alpha = 255.0f;

		bool redM = true;
		bool blueM = true;
		bool greenM = true;
		bool alphaM = true;

		float newWidth;
		float newHeight;

	private:
		float width, height;
		Texture* texture;
	};
}