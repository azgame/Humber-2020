#ifndef COREENGINE_H
#define COREENGINE_H

#include "Window.h"
#include <memory>
#include "Timer.h"
#include "GameInterface.h"
#include "Scene.h"
#include "../Rendering/3D/GameObject.h"
#include "../Graphics/ShaderHandler.h"
#include "../Graphics/TextureHandler.h"
#include "../Camera/Camera.h"	

class CoreEngine
{
public:
	//singleton code
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator=(const CoreEngine&) = delete;
	CoreEngine& operator=(CoreEngine&&) = delete;

	

	bool OnCreate(std::string name_, int width_, int height_);
	void Run();

	static CoreEngine* GetInstance();


	int GetCurrentScene();
	bool GetIsRunning() const;
	glm::vec2 GetWindowSize() const;
	Camera* GetCamera() const;


	void SetCurrentScene(int sceneNum_);
	void SetGameInterface(GameInterface* gameInterface_);
	void SetCamera(Camera* camera_);
	void Exit();
private:
	CoreEngine();
	~CoreEngine();
	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;

	void Update(const float deltaTime_);
	void Render();
	void OnDestroy();
	Window* window;
	bool isRunning;

	Timer timer;
	unsigned int fps;

	GameInterface* gameInterface;

	int currentSceneNum;

	Camera* camera;
};

#endif // !COREENGINE_H


