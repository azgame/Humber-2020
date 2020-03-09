#include "GameScene.h"



GameScene::GameScene() : Scene(), shape(nullptr) {

}

GameScene::~GameScene() {
	delete shape;
	shape = nullptr;
}

bool GameScene::OnCreate() {
	Debug::Info("Creating Game Scene ", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera);
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CoreEngine::GetInstance()->GetCamera()->AddLightSources(new LightSource (glm::vec3(0.0f, 2.0f, 4.0f),glm::vec3(1.0f, 1.0f, 1.0f), 0.1f, 0.5f));


	Model* model = new Model("./Resources/Models/Apple.obj", "./Resources/Materials/Apple.mtl", ShaderHandler::GetInstance()->GetShader("basicShader"));
	shape = new GameObject(model);

	shape->SetPosition(glm::vec3(0.0f, -1.0f, 0.0f));
	shape->SetScale(glm::vec3(0.65f));

	return true;
}

void GameScene::Update(const float deltaTime_) {
	shape->Update(deltaTime_);
}

void GameScene::Render() {
	shape->Render(CoreEngine::GetInstance()->GetCamera());
}