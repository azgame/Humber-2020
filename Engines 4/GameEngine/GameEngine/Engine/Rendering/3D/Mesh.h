#ifndef MESH_H
#define MESH_H

#include <glew.h>
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Camera/Camera.h"

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 colour;
};

struct SubMesh {
	std::vector<Vertex> vertexList;
	std::vector<int> meshIndices;
	GLuint textureID;

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
	GLuint lightPositionLoc;
	GLuint lightAmbientLoc;
	GLuint lightDiffuseLoc;
	GLuint lightColourLoc;
};

#endif // !MESH_H
