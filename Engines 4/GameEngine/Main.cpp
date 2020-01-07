#include "Engine/Core/CoreEngine.h"

int main(int argc, char* argv[]) {
	
	if (!CoreEngine::GetInstance()->OnCreate("Engine", 1600, 900)) {
		std::cout << "Engine failed to be created" << std::endl;
		return 0;
	}

	CoreEngine::GetInstance()->Run();

	return 0;
}