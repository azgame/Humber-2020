#include "GameScene.h"



GameScene::GameScene() : Scene(), shape(nullptr) {

}

GameScene::~GameScene() {
	delete shape;
	shape = nullptr;
}

bool GameScene::OnCreate() {
	Debug::Info("Creating Game Scene ", "GameScene.cpp", __LINE__);

	Vertex v;
	std::vector<Vertex> vertexList;
	//Make a triangle
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);
	v.position = glm::vec3(0.5f, -0.5f, 0.0f);
	vertexList.push_back(v);

	std::vector<Vertex> vertexList2;
	//ANOTHER ONE
	v.position = glm::vec3(0.5f, 0.5f, 0.0f);
	vertexList2.push_back(v);
	v.position = glm::vec3(-0.5f, -0.5f, 0.0f);
	vertexList2.push_back(v);
	v.position = glm::vec3(-0.5f, 0.5f, 0.0f);
	vertexList2.push_back(v);


	Model* model = new Model();
	model->AddMesh(new Mesh(&vertexList));
	model->AddMesh(new Mesh(&vertexList2));

	shape = new GameObject(model);

	return true;
}

void GameScene::Update(const float deltaTime_) {
	
}

void GameScene::Render() {
	shape->Render();
}