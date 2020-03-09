#include "stdafx.h"
#include "Transform.h"

Transform::Transform()
{
}

Transform::~Transform()
{
}

bool Transform::Init()
{
	return true;
}

void Transform::Update(float deltaTime)
{
}

void Transform::Draw()
{
}

void Transform::Attach(GameObject* owner_)
{
	owner = owner_;
}
