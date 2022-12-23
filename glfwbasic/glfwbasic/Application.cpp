#include "Application.h"
#include "InputSystem.h"
#include "SceneStateMachine.h"
#include "SplashScene.h"
#include "GameScene.h"


AlyfGE::Application::Application()
{

}

AlyfGE::Application::~Application()
{

}


bool AlyfGE::Application::Initialize(int width, int height, std::string title)
{

	if (window.initializeWindow(width, height, title))
	{
		isInitialized = true;
	}
	return isInitialized;
}

void AlyfGE::Application::SetFrameRate(int fr)
{
	if (fr <= 0.0) {
		frameRate = 0.0;
	}
	else {
		frameRate = 1.0 / fr;
	}
}


void AlyfGE::Application::Run()
{

	if (isInitialized != true)
	{
		return;
	}

	isRunning = true;
	SceneStateMachine sceneManager;

	unsigned int splashId = 0;
	unsigned int gameId = 0;

	sceneManager.addScene<SplashScene>(splashId);
	sceneManager.addScene<GameScene>(gameId);

	// set initial scene
	sceneManager.loadScene("SplashScene");

	float prevTimeFrame = 0.0;

	while (isRunning)
	{
		Input::InputSystem::Setup(window.getNativeWindow());
		Application::SetFrameRate(30);

		float currentTimeFrame = glfwGetTime();
		float currentTime = glfwGetTime();
		float deltaTime = currentTimeFrame - prevTimeFrame;


		while (deltaTime < frameRate) {
			currentTime = glfwGetTime();
			deltaTime = currentTime - prevTimeFrame;
		}

		sceneManager.update(deltaTime);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		sceneManager.render();

		prevTimeFrame = currentTimeFrame;

		char str[64];
		sprintf_s(str, "Console/Application run: %f fps, dt: %f", 1.0 / deltaTime, deltaTime);
		glfwSetWindowTitle(window.getNativeWindow(), str);

		window.swapBufferAndPoll(deltaTime);
	}

}







void AlyfGE::Application::SetupEventCallbacks()
{

	if (isInitialized != true)
	{
		return;
	}

	// reduce dependency on glfwWindows
	window.SetWindowEventCallback([this](std::string evt)
		{
			OnWindowEventFired(evt);
		});

}

void AlyfGE::Application::OnWindowEventFired(std::string& evt)
{
	printf("%s", evt.c_str());
	if (evt == "Exited\n")
	{
		isRunning = false;
	}
}