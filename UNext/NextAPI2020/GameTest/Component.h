#ifndef COMPONENT_H
#define COMPONENT_H

#include "stdafx.h"

class GameObject;

class Component
{
protected:
	GameObject* owner = nullptr;

public:
	virtual bool Init() { return true; }
	virtual void Update(float deltaTime) {}
	virtual void Draw() {}
	virtual void Attach(GameObject* owner_) {}
};

#endif