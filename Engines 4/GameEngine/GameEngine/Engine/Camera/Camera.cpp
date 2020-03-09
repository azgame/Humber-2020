#include "Camera.h"
#include "../Core/CoreEngine.h"
Camera::Camera() : position(glm::vec3()){
	fov = 45.0f; // Field of View can be 45-60;
	forward = glm::vec3(0.0f, 0.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	worldUp = up;
	nearPlane = 2.0f;
	farPlane = 50.0f;
	yaw = -90.0f;
	pitch = 0.0f;

	persp = glm::perspective(fov, CoreEngine::GetInstance()->GetWindowSize().x / CoreEngine::GetInstance()->GetWindowSize().y, nearPlane, farPlane);
	ortho = glm::ortho(0.0f, CoreEngine::GetInstance()->GetWindowSize().x, 0.0f, CoreEngine::GetInstance()->GetWindowSize().y, -1.0f, 1.0f);

	UpdateCameraVector();
}

Camera::~Camera(){
	OnDestroy();
}

void Camera::SetPosition(glm::vec3 position_) { position = position_; UpdateCameraVector(); }

void Camera::SetRotation(float yaw_, float pitch_) { yaw = yaw_; pitch = pitch_; UpdateCameraVector(); }

glm::mat4 Camera::GetView() const{ return glm::lookAt(position, position + forward, up); }

// if you want to have the ability to resize window, recalc persp and ortho like the constructor does. 
glm::mat4 Camera::GetPerspective() const{ return persp; }
glm::mat4 Camera::GetOrthographic() const{ return ortho; }

void Camera::UpdateCameraVector(){
	forward.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	forward.y = sin(glm::radians(pitch));
	forward.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	forward = glm::normalize(forward);

	right = glm::normalize(glm::cross(forward, worldUp));

	up = glm::normalize(glm::cross(right, forward));
}
void Camera::OnDestroy()
{
	lightsources.clear();
}
void Camera::AddLightSources(LightSource* lightsource_)
{
	lightsources.push_back(lightsource_);
}
std::vector<LightSource*> Camera::GetLightSources()
{
	return lightsources;
}
glm::vec3 Camera::GetPosition()
{
	return position;
}