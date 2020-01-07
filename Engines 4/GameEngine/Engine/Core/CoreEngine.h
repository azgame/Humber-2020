#ifndef COREENGINE_H
#define COREENGINE_H
#include "Window.h"

//singleton
#include <memory>

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
	bool GetIsRunning() const;

	static CoreEngine* GetInstance();

private:
	//singleton
	CoreEngine();
	~CoreEngine();
	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;

	void Update(float deltaTime_);
	void Render();
	void OnDestroy();
	Window* window;
	bool isRunning;
};

#endif // !COREENGINE_H


