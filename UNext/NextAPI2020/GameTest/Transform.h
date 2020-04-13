#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "Vector.h"
#include "stdafx.h"

class Transform : public Component
{
public:

	Vector2 position;
	Vector2 rotation;
	Vector2 scale;
	Vector2 forward;

	Transform(GameObject* owner_ = nullptr);
	~Transform();

	bool Init() override;
	void Update(float deltaTime) override;
	void Draw() override;
	void Attach(GameObject* owner_) override;
};

#endif