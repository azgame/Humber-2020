#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"

class GameObject
{
public:
	GameObject(Model* model_, glm::vec3 position_ = glm::vec3());
	~GameObject();
	void Render(Camera* camera_);
	void Update(const float deltaTime_);

	//getters
	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec3 GetRotation() const;
	glm::vec3 GetScale() const;


	//setters
	void SetPosition(glm::vec3 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec3 rotation_);
	void SetScale(glm::vec3 scale_);
private:
	Model* model;

	glm::vec3 position;
	float angle;
	glm::vec3 rotation;
	glm::vec3 scale;

	int modelInstance;
};

#endif // !GAMEOBJECT_H
