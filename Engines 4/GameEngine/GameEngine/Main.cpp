#include "Engine/Core/CoreEngine.h"
#include "Game/Game1.h"
int main(int argc, char* argv[]) {
	CoreEngine::GetInstance()->SetGameInterface(new Game1);

	if (!CoreEngine::GetInstance()->OnCreate("Engine", 1280, 720)) {
		//std::cout << "Engine failed to be created" << std::endl;
		Debug::FatalError("Engine failed to be created", "Main.cpp", __LINE__);
		return 0;
	}

	CoreEngine::GetInstance()->Run();

	return 0;
}