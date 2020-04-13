#include "GameScene.h"



GameScene::GameScene() : Scene() {

}

GameScene::~GameScene() {
	SceneGraph::GetInstance()->OnDestroy();
}

bool GameScene::OnCreate() {
	Debug::Info("Creating Game Scene ", "GameScene.cpp", __LINE__);

	CoreEngine::GetInstance()->SetCamera(new Camera);
	CoreEngine::GetInstance()->GetCamera()->SetPosition(glm::vec3(0.0f, 0.0f, 4.0f));
	CoreEngine::GetInstance()->GetCamera()->AddLightSources(new LightSource(glm::vec3(0.0f, 0.0f, 2.0f), 
		glm::vec3(1.0f, 1.0f, 1.0f), 0.1f, 0.5f));


	Model* model = new Model("./Resources/Models/Dice.obj", "./Resources/Materials/Dice.mtl", 
		ShaderHandler::GetInstance()->GetShader("basicShader"));
	SceneGraph::GetInstance()->AddModel(model);
	Model* model1 = new Model("./Resources/Models/Apple.obj", "./Resources/Materials/Apple.mtl", 
		ShaderHandler::GetInstance()->GetShader("basicShader"));
	SceneGraph::GetInstance()->AddModel(model1);
	SceneGraph::GetInstance()->AddGameObject(new GameObject(model, glm::vec3(1.0f, 1.0f, 0.0f)), "dice");
	SceneGraph::GetInstance()->AddGameObject(new GameObject(model1, glm::vec3(3.0f, -1.0f, 0.0f)), "apple");


	std::cout << "Min Vert: " << glm::to_string(model->GetBoundingBox().minVert) << std::endl;
	std::cout << "Max Vert: " << glm::to_string(model->GetBoundingBox().maxVert) << std::endl;
	return true;
}

void GameScene::Update(const float deltaTime_) {
	SceneGraph::GetInstance()->Update(deltaTime_);
}

void GameScene::Render() {
	SceneGraph::GetInstance()->Render(CoreEngine::GetInstance()->GetCamera());
}