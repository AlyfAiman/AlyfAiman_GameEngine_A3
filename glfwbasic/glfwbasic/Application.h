#pragma once
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <string>
#include "Window.h"


namespace AlyfGE
{ 
	class Application
	{
	public:
		// constructor
		Application();
		// destructor
		~Application();

		// initializes Window, keeps track of success or failure
		bool Initialize(int width, int height, std::string title);

		// if Initialize not called, log to console and return,
		// otherwise, bind to window events.
		void SetupEventCallbacks();

		// if Initialize not called, log to console and return
		// otherwise, enter application loop until window closes.
		void Run();

		void SetFrameRate(int fr);

		float deltaTime;

		float deltaTimeReturn();

		void InputSystemSetup();

	private:
		void OnWindowEventFired(std::string& evt);

		bool isInitialized = false;

		bool isRunning = false;

		float frameRate = 0;


		Window window;


	};

}