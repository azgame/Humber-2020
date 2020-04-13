#ifndef COMPONENT_H
#define COMPONENT_H

#include "stdafx.h"

class GameObject;

class Component
{
protected:
	GameObject* owner = nullptr;

public:
	Component(GameObject* owner_) { owner = owner_; }
	virtual ~Component() {}
	virtual bool Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
	virtual void Attach(GameObject* owner_) = 0;
};

#endif