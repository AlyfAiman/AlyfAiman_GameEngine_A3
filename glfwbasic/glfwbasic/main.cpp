#include <iostream>
#include <glad/glad.h>
#include "Application.h"
#include <glfw/glfw3.h>

int main() {
	AlyfGE::Application app;
	if (!app.Initialize(800, 600, "GameEngineArchitecture A2"))
	{
		return 0;
	}


	app.SetupEventCallbacks();
	app.Run();


}