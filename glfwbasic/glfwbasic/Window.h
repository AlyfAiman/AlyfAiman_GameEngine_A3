#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <string>
#include <functional>


typedef std::function<void(std::string)> SimpleEventCallbackFn;

namespace AlyfGE
{
	class Window
	{
	public:
		// destructor
		~Window();

		// creates GLFWWindow and declare GLFWWindow event callback behaviours
		int initializeWindow(int width, int heaight, std::string& title);

		// do last
		void swapBufferAndPoll(float deltaTime);

		// returns window
		GLFWwindow* getNativeWindow() const { return nativeWindow; }

		void SetWindowEventCallback(const SimpleEventCallbackFn& callback);



	private:

		struct WindowData
		{
			int width, height;
			std::string title;

			SimpleEventCallbackFn callbackFn;
		};

		WindowData data;

		GLFWwindow* nativeWindow;


	};
}
