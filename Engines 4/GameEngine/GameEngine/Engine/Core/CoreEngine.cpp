#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::engineInstance = nullptr;


CoreEngine::CoreEngine() : window(nullptr), isRunning(false), fps(60), gameInterface(nullptr), currentSceneNum(0), camera(nullptr) {}

CoreEngine::~CoreEngine() { OnDestroy(); }

bool CoreEngine::OnCreate(std::string name_, int width_, int height_) {
	Debug::DebugInit();
	Debug::SetSeverity(MessageType::TYPE_INFO);

	window = new Window();
	if (!window->OnCreate(name_, width_, height_)) {
		Debug::FatalError("Window failed to create!", "CoreEngine.cpp", __LINE__);
		return isRunning = false;
	}

	ShaderHandler::GetInstance()->CreateProgram("colourShader", 
		"Engine/Shaders/ColourVertexShader.glsl", "Engine/Shaders/ColourFragmentShader.glsl");

	ShaderHandler::GetInstance()->CreateProgram("basicShader",
		"Engine/Shaders/VertexShader.glsl", "Engine/Shaders/FragmentShader.glsl");

	if (gameInterface) {
		if (gameInterface->OnCreate()) {
			Debug::Info("Game Interface was created succesfully ", "CoreEngine.cpp", __LINE__);
		}
	}

	timer.Start();
	Debug::Info("Engine was created correctly ", "CoreEngine.cpp", __LINE__);
	return isRunning = true;
}

void CoreEngine::Run() {
	while (isRunning) {
		timer.UpdateFrameTicks();
		Update(timer.GetDeltaTime());
		Render();
		SDL_Delay(timer.GetSleepTime(fps));
	}
	if (!isRunning) {
		OnDestroy();
	}
}

bool CoreEngine::GetIsRunning() const { return isRunning; }

glm::vec2 CoreEngine::GetWindowSize() const{ return glm::vec2(window->GetWidth(), window->GetHeight());}

Camera* CoreEngine::GetCamera() const { return camera; }

CoreEngine* CoreEngine::GetInstance() {
	if (engineInstance.get() == nullptr) {
		engineInstance.reset(new CoreEngine);
	}
	return engineInstance.get();
}

void CoreEngine::SetGameInterface(GameInterface * gameInterface_){ gameInterface = gameInterface_; }

void CoreEngine::SetCamera(Camera * camera_){ camera = camera_;}

int CoreEngine::GetCurrentScene(){ return currentSceneNum; }

void CoreEngine::SetCurrentScene(int sceneNum_){ currentSceneNum = sceneNum_; }



void CoreEngine::Exit(){
	isRunning = false;
}


void CoreEngine::Update(const float deltaTime_) {
	if (gameInterface) {
		gameInterface->Update(deltaTime_);
	}
}

void CoreEngine::Render() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gameInterface) {
		gameInterface->Render();
	}
	SDL_GL_SwapWindow(window->GetWindow());
}

void CoreEngine::OnDestroy() {
	delete camera;
	camera = nullptr;

	delete gameInterface;
	gameInterface = nullptr;

	delete window;
	window = nullptr;


	SDL_Quit();
	exit(0);
}