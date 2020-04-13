#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"
#include "..//..//Graphics/MaterialHandler.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 colour;
};

struct SubMesh {
	std::vector<Vertex> vertexList;
	Material material;
	std::vector<int> meshIndices;

};

class Mesh {
public:
	Mesh(SubMesh subMesh, GLuint shaderProgram_);
	~Mesh();
	void Render(Camera* camera, std::vector<glm::mat4> instances_);
private: 
	void GenerateBuffers();
	SubMesh subMesh;

	GLuint VAO, VBO;
	GLuint shaderProgram;
	GLuint modelLoc, textureLoc, viewLoc, projLoc;

	GLuint viewPositionLoc;
	GLuint lightPositionLoc, lightAmbientLoc, lightDiffuseLoc, lightColourLoc;
	GLuint shininessLoc, transparencyLoc, ambientLoc, diffuseLoc, specularLoc, diffuseMapLoc;
};

#endif // !MESH_H
