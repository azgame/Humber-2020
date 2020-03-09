#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include "stdafx.h"

class Transform : public Component
{
public:
	Transform();
	~Transform();

	bool Init() override;
	void Update(float deltaTime) override;
	void Draw() override;
	void Attach(GameObject* owner_) override;
};

#endif