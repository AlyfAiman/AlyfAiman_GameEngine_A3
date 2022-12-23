#include "Window.h"


AlyfGE::Window::~Window()
{
	glfwDestroyWindow(nativeWindow);

}


int AlyfGE::Window::initializeWindow(int width, int height, std::string& title)
{
	if (!glfwInit())
	{
		return 0;
	}



	nativeWindow = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);

	data.width = width;
	data.height = height;
	data.title = title;

	if (!nativeWindow)
	{
		glfwTerminate();

		return 0;
	}

	glfwMakeContextCurrent(nativeWindow);

	glfwSetWindowUserPointer(nativeWindow, &data);

	glfwSetWindowCloseCallback(nativeWindow, [](GLFWwindow* w)
		{
			WindowData& dat = *(WindowData*)glfwGetWindowUserPointer(w);
	dat.callbackFn("Exit Program\n");
		});

	return 1;
}

void AlyfGE::Window::swapBufferAndPoll(float deltaTime)
{
	// Show what was rendered to the window
	glfwSwapBuffers(nativeWindow);

	// Process events and invoke callbacks (e.g. window, keyboard, mouse, ect)
	glfwPollEvents();
}

void AlyfGE::Window::SetWindowEventCallback(const SimpleEventCallbackFn& callback)
{
	data.callbackFn = callback;
}